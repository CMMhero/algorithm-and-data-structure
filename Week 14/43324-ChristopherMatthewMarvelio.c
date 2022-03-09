#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *bidang[] = {"Olahraga", "Sains & Sosial", "Seni & Budaya", "Unspecified"};
char *jenis[] = {"UKM", "Komunitas", "LSO"};

typedef struct Kegiatan
{
	int id;
	char nama[50], bidang[25], jenis[10];
	struct Kegiatan *prev, *next;
} Kegiatan;

typedef struct List
{
	Kegiatan *head, *tail;
} List;

int max(int a, int b)
{
	return a > b ? a : b;
}

int existed(List list, char *key)
{
	for (Kegiatan *temp = list.head; temp != NULL; temp = temp->next)
	{
		if (strcmp(temp->nama, key) == 0)
			return 1;
	}
	return 0;
}

void push(List *list, Kegiatan new)
{
	Kegiatan *node = (Kegiatan *)malloc(sizeof(Kegiatan));

	if (node == NULL)
		exit(0);

	*node = new;
	node->prev = node->next = NULL;

	if (list->head == NULL)
		list->head = list->tail = node;
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
}

void readData(List *list)
{
	FILE *fp = fopen("KegiatanUMN.txt", "r");
	if (fp != NULL)
	{
		Kegiatan new;
		while (!feof(fp))
		{
			fscanf(fp, "%d#%[^#]#%[^#]#%[^\n]\n", &new.id, new.nama, new.bidang, new.jenis);
			push(list, new);
		}
	}
	fclose(fp);
}

void tampilan(List list)
{
	system("cls");
	printf("====================================================================================\n");
	printf("                          Daftar Semua Kegiatan                                     \n");
	printf("====================================================================================\n\n");
	printf("------------------------------------------------------------------------------------\n");
	printf("| ID  |                 Nama                 |      Bidang      |      Jenis       |\n");
	printf("------------------------------------------------------------------------------------\n");

	if (list.head == NULL)
		printf("Kegiatan kosong\n");
	else
	{
		for (Kegiatan *temp = list.head; temp != NULL; temp = temp->next)
		{
			printf("| %.3d | %-36s | %-16s | %-16s |\n", temp->id, temp->nama, temp->bidang, temp->jenis);
		}
	}

	printf("------------------------------------------------------------------------------------\n\n");
	system("pause");
}

void swap(Kegiatan *a, Kegiatan *b)
{
	Kegiatan temp;
	temp = *a;
	*a = *b;
	*b = temp;

	Kegiatan *temp2 = a->prev;
	a->prev = b->prev;
	b->prev = temp2;

	temp2 = a->next;
	a->next = b->next;
	b->next = temp2;
}

Kegiatan *partition(Kegiatan *l, Kegiatan *h)
{
	char nama[50];
	strcpy(nama, h->nama);

	int id = h->id;

	Kegiatan *i = l->prev;

	for (Kegiatan *j = l; j != h; j = j->next)
	{
		if (strcmp(j->nama, nama) <= 0)
		{
			i = (i == NULL) ? l : i->next;
			swap(i, j);
		}
	}

	i = (i == NULL) ? l : i->next;
	swap(i, h);

	return i;
}

void quickSort(Kegiatan *l, Kegiatan *h)
{
	if (h != NULL && l != h && l != h->next)
	{
		Kegiatan *p = partition(l, h);
		quickSort(l, p->prev);
		quickSort(p->next, h);
	}
}

void sort(List list)
{
	quickSort(list.head, list.tail);
}

void cari(List list)
{
	char key[50];
	printf("Nama kegiatan yang dicari : ");
	scanf(" %[^\n]", key);
	fflush(stdin);

	Kegiatan *temp;
	for (temp = list.head; temp != NULL; temp = temp->next)
	{
		if (strcmp(temp->nama, key) == 0)
		{
			printf("\nData Found !\n");
			printf("ID     : %d\n", temp->id);
			printf("Nama   : %s\n", temp->nama);
			printf("Jenis  : %s\n", temp->jenis);
			printf("Bidang : %s\n\n", temp->bidang);
			break;
		}
	}

	if (temp == NULL)
		printf("\nData tidak ditemukan.\n\n");
	system("pause");
}

void tambah(List *list)
{
	printf("===============================\n");
	printf("       Tambah Kegiatan         \n");
	printf("===============================\n");
	printf("Keterangan :\n");
	printf("%-18sBidang :\n", "Jenis :");

	for (int i = 0, j = max(sizeof(jenis) / sizeof(jenis[0]), sizeof(bidang) / sizeof(bidang[0])); i < j; i++)
	{
		if (i < sizeof(jenis) / sizeof(jenis[0]))
			printf("- %-16s", jenis[i]);
		else
			printf("%-18s", " ");
		if (i < sizeof(bidang) / sizeof(bidang[0]))
			printf("- %s", bidang[i]);
		printf("\n");
	}
	printf("\n");

	Kegiatan new;
	while (1)
	{
		printf("Nama Kegiatan : ");
		scanf(" %[^\n]s", new.nama);
		fflush(stdin);
		if (existed(*list, new.nama) == 1)
			printf("\nNama kegiatan telah digunakan\n");
		else
			break;
	}

	int valid = 0;
	while (1)
	{
		printf("Jenis         : ");
		scanf(" %[^\n]s", new.jenis);
		fflush(stdin);
		for (int i = 0, j = sizeof(jenis) / sizeof(jenis[0]); i < j; ++i)
		{
			if (strcmp(jenis[i], new.jenis) == 0)
			{
				strcpy(new.jenis, jenis[i]);
				valid = 1;
				break;
			}
		}

		if (valid == 0)
			printf("\nJenis invalid\n");
		else
			break;
	}

	valid = 0;
	while (1)
	{
		printf("Bidang        : ");
		scanf(" %[^\n]s", new.bidang);
		fflush(stdin);
		for (int i = 0, j = sizeof(bidang) / sizeof(bidang[0]); i < j; ++i)
		{
			if (strcmp(bidang[i], new.bidang) == 0)
			{
				strcpy(new.bidang, bidang[i]);
				valid = 1;
				break;
			}
		}

		if (valid == 0)
			printf("\nBidang invalid\n");
		else
			break;
	}

	sort(*list);

	Kegiatan *node = (Kegiatan *)malloc(sizeof(Kegiatan));

	if (node == NULL)
		exit(0);

	*node = new;
	node->id = 1;
	node->prev = node->next = NULL;

	if (list->head == NULL)
		list->head = list->tail = node;
	else if (node->id < list->head->id)
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	else if (node->id > list->tail->id)
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	else
	{
		for (Kegiatan *temp = list->head; temp != NULL; temp = temp->next)
		{
			(node->id)++;

			if (node->id < temp->id)
			{
				node->prev = temp->prev;
				node->next = temp;
				temp->prev->next = node;
				temp->prev = node;
				break;
			}
		}
	}

	FILE *fp = fopen("KegiatanUMN.txt", "a");
	fprintf(fp, "%d#%s#%s#%s\n", node->id, node->nama, node->bidang, node->jenis);
	fclose(fp);

	printf("\nID            : %d\n", node->id);

	printf("Data berhasil ditambahkan\n\n");
	system("pause");
}

int main()
{
	int pilihan;
	while (1)
	{
		List list = {NULL, NULL};
		readData(&list);

		system("cls");
		printf("==============================\n");
		printf("    Daftar Kegiatan di UMN\n");
		printf("==============================\n");
		printf("1. Tampilan Kegiatan\n");
		printf("2. Urutkan Kegiatan\n");
		printf("3. Cari Kegiatan\n");
		printf("4. Tambah Kegiatan\n");
		printf("0. Keluar\n");
		printf("Pilih : ");
		scanf("%d", &pilihan);
		fflush(stdin);

		switch (pilihan)
		{
		case 0:
			return 0;
		case 1:
			system("cls");
			tampilan(list);
			break;
		case 2:
			system("cls");
			sort(list);
			tampilan(list);
			break;
		case 3:
			system("cls");
			cari(list);
			break;
		case 4:
			system("cls");
			tambah(&list);
			break;
		default:
			printf("\nPilihan invalid\n\n");
			system("pause");
			break;
		}
	}

	return 0;
}