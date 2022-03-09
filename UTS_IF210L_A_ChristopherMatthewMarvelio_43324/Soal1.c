/*
Nama: Christopher Matthew Marvelio
NIM : 00000043324
Kelas : A
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lagu{
	char judul[25];
	char penyanyi[25];
	char durasi[5];
	struct Lagu *next;
} Lagu;

typedef struct Playlist{
	char judul[25];
	char penyanyi[25];
	char durasi[5];
	struct Playlist *next, *prev;
} Playlist;

Playlist *phead, *ptail, *pnode;

void list() {		
	Lagu *head, *node, *tail;
	head = tail = NULL;
	FILE *fp = fopen("musik.txt", "r");
	while(!feof(fp)) {
		node = (Lagu*)malloc(sizeof(Lagu));
		fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", node->judul, node->penyanyi, node->durasi);
        node->next = NULL;
        
        if(head == NULL)
            head = node;
        else
            tail->next = node;
        tail = node;
	}
	fclose(fp);
	
	system("cls");
	Lagu *temp = head;
	int i=1;
	printf("No   Judul               Penyanyi            Durasi \n");
	printf("----------------------------------------------------\n");
	while(temp != NULL) {
		printf("%-4d %-19s %-21s %s\n", i, temp->judul, temp->penyanyi, temp->durasi);
		temp = temp->next;
		i++;
	}
	
	int input;
	printf("\n");
	printf("Tekan [1] untuk menambahkan lagu pada playlist\n");
	printf("Tekan [0] untuk kembali ke menu\n");
	printf("Input: ");
	scanf("%d", &input); fflush(stdin);
	switch(input) {
		case 1: {
			int nomor;
			printf("\nTambah Playlist\n");
			printf("---------------\n");
			printf("Masukkan nomor untuk lagu: ");
			scanf("%d", &nomor); fflush(stdin);
			
			if(nomor>=i || nomor == 0) {
				printf("Nomor lagu tidak tersedia.");	
			} else {	
				temp = head;
				for(i=1; i<nomor; i++) {
					temp = temp->next;
				}
				pnode = (Playlist*) malloc(sizeof(Playlist));
				strcpy(pnode->judul, temp->judul);
				strcpy(pnode->penyanyi, temp->penyanyi);
				strcpy(pnode->durasi, temp->durasi);
				pnode->next = NULL;
			  
				if(phead == NULL) {
			    	pnode->prev = NULL;
			    	phead = pnode;
				} else {
			    	ptail->next = pnode;
			    	pnode->prev = ptail;
				}
				ptail = pnode;
				ptail->next = NULL;
					
				printf("Berhasil menambahkan playlist");
			}
			getchar();
			break;
		}
		case 0:
			break;
		default: {
			printf("Angka yang Anda masukkan salah");
			getchar();
			break;
		}
	}
}

void tambah() {
	char judul[25];
	char penyanyi[25];
	char durasi[5];
	
	system("cls");
	printf("Tambah Lagu\n");
	printf("-----------\n");
	printf("Judul Lagu: "); scanf("%[^\n]", judul); fflush(stdin);
	printf("Penyanyi: "); scanf("%[^\n]", penyanyi); fflush(stdin);
	printf("Durasi: "); scanf("%[^\n]", durasi); fflush(stdin);
	
	FILE *fout = fopen("musik.txt", "a");
		fprintf(fout, "%s#%s#%s\n", judul, penyanyi, durasi);
	fclose(fout);
	printf("\nLagu berhasil ditambahkan!");
	getchar();
}

void playlist() {
	system("cls");
	printf("My Playlist\n\n");

	if(phead == NULL) {
		printf("Playlist kosong");
	} else {
		printf("No   Judul               Penyanyi            Durasi \n");
		printf("----------------------------------------------------\n");
		int i=1;
		
		pnode = phead;
		while(pnode != NULL) {
			printf("%-4d %-19s %-21s %s\n", i, pnode->judul, pnode->penyanyi, pnode->durasi);
			pnode = pnode->next;
			i++;
		}
	}
	
	getchar();
}

int main() {
	int pilihan = 1;
	do{
		system("cls");
		printf("======================\n");
		printf("        Dotify        \n");
		printf("======================\n");
		printf("1. List Lagu\n");
		printf("2. Tambah Lagu\n");
		printf("3. My Playlist\n");
		printf("4. Keluar\n");
		printf("Pilihan menu: ");
		scanf("%d", &pilihan); fflush(stdin);
	
		switch(pilihan) {
			case 1:
				list();
				break;
			case 2:
				tambah();
				break;
			case 3:
				playlist();
				break;
			case 4:
				break;
			default: {
				printf("Menu tidak dikenali. Mohon masukkan nomor menu kembali.");
				getchar();
				break;
			}
		}
	} while(pilihan != 4);

	return 0;
}

