#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char nama[50];
	char nim[20];
	struct Student *next;
} Student;

Student *alphead[26];
Student *trash;

void cari() {
	char nama[3];
	char namatemp[3];
	int i=1, x;
	system("cls");
	printf("================================================\n");
	printf("                Cari Mahasiswa                  \n");
	printf("================================================\n");
	printf("Masukkan 3 huruf inisial nama yang ingin dicari:\n");
	scanf("%s", nama); fflush(stdin);
	
	if(nama[0] >='a' && nama[0] <='z') {
		printf("Anak berinisial %s tidak ditemukan!\n", nama);
	} else {
		for(i=65; i<91; i++) {
			if(nama[0] == i)
				x = i-65;
		}
		Student *temp = alphead[x];
		
		i=1;
		if(temp == NULL) {
			printf("Anak berinisial %s tidak ditemukan!\n", nama);
		} else {
	        while(temp != NULL) {
	        	strncpy(namatemp, temp->nama, 3);
	        	if(strcmp(namatemp, nama) == 0) {
	        		printf("Mahasiswa #%d\n", i);
		        	printf("Nama: %s\n", temp->nama);
		        	printf("NIM: %s\n", temp->nim);
		        	printf("--------------------------------\n");
		        	i++;
				}
	        	temp = temp->next;
			}
			if(strcmp(namatemp, nama) != 0 && i == 1)
				printf("Anak berinisial %s tidak ditemukan!\n", nama);
		}	
	}

	printf("Tekan tombol apapun untuk melanjutkan...");
	getchar();
}

void hapus() {
	int i, x;
	char nama[50];
	system("cls");
	printf("================================================\n");
	printf("                Hapus Mahasiswa                 \n");
	printf("================================================\n");
	printf("Masukkan nama mahasiswa : ");
	scanf("%[^\n]", nama); fflush(stdin);
	
	if(nama[0] >='a' && nama[0] <='z') {
		printf("Anak berinisial %s tidak ditemukan!\n", nama);
	} else {
		for(i=65; i<91; i++) {
			if(nama[0] == i)
				x = i-65;
		}
		trash = alphead[x];
		Student *trashB = trash;
		
		if(trash == NULL) {
			printf("Anak berinisial %s tidak ditemukan!\n", nama);
		} else {
			while(trash->next != NULL && strcmp(trash->nama, nama) != 0) {
				trashB = trash;
				trash = trash->next;
			}
			
			if(strcmp(trash->nama, nama) != 0) {
				printf("Anak berinisial %s tidak ditemukan!\n", nama);
			} else {
				if(strcmp(trashB->nama, trash->nama) != 0) {
					if(trash->next == NULL) {
						trashB->next = NULL;
					} else {
						trashB->next = trash->next;	
					}
				}
				trash->next = NULL;
				free(trash);
				printf("Mahasiswa dengan nama %s berhasil dihapus\n", nama);
			}
		}
	}
	
	
	FILE *fupdate = fopen("datamhs.txt", "w");
		for(i=0; i<26; i++) {
			trash = alphead[i];
			while(trash != NULL) {
				fprintf(fupdate, "%s-%s\n", trash->nim, trash->nama);
				trash = trash->next;	
			}
		}
	fclose(fupdate);
	
	printf("Tekan tombol apapun untuk melanjutkan...");
	getchar();
}

void tambah() {
	char nama[50];
	char nim[20];
	system("cls");
	printf("================================================\n");
	printf("               Tambah Mahasiswa                 \n");
	printf("================================================\n");
	printf("Masukkan nama mahasiswa baru: ");
	scanf("%[^\n]", nama); fflush(stdin);
	printf("Masukkan NIM mahasiswa baru: ");
	scanf("%[^\n]", nim); fflush(stdin);
	
	FILE *fout = fopen("datamhs.txt", "a");
		fprintf(fout, "%s-%s\n", nim, nama);
	fclose(fout);
	printf("Mahasiswa baru telah dimasukkan!\n");
	printf("Tekan tombol apapun untuk melanjutkan...");
	getchar();
}

void insertToChain(char nim[], char nama[], Student **head) {
	Student *ptr = (*head);
	Student *node = (Student*)malloc(sizeof(Student));
	strcpy(node->nim, nim);
	strcpy(node->nama, nama);
	node->next = NULL;
	if(*head == NULL) {
		*head = node;
	}
	else{
		while(ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = node;
	}
}

int main() {
	int pilihan=1, i;
	char nama[50], nim[20];
	Student *alphabet[26];
	Student *head;
	do {
		system("cls");
		for(i=0; i<26; i++){
			alphabet[i] = NULL;
		}
		
		head = NULL;
		FILE *fp = fopen("datamhs.txt", "r");
		while(!feof(fp)) {
			fscanf(fp, "%[^-]-%[^\n]\n", nim, nama);
			int x;
			for(i=65; i<91; i++) {
				if(nama[0] == i)
					x = i-65;
			}
			insertToChain(nim, nama, &alphabet[x]);
		}
		fclose(fp);
		
		for(i=0; i<26; i++){
			alphead[i] = alphabet[i];
		}
		
		printf("================================================\n");
		printf("               Daftar Mahasiswa                 \n");
		printf("================================================\n");
		printf("(1). Cari Mahasiswa\n");
		printf("(2). Delete Mahasiswa\n");
		printf("(3). Tambah Mahasiswa\n");
		printf("(0). Exit\n");
		printf("Pilih :");
		scanf("%d", &pilihan); fflush(stdin);
		
		if(pilihan == 0)
			break;
		switch(pilihan) {
			case 1:{
				cari();
				break;
			}
			case 2:{
				hapus();
				break;
			}
			case 3:{
				tambah();
				break;
			}
			default:{
				printf("Input Salah!");
				getchar();
				break;
			}
		}
	} while (pilihan != 0);
	return 0;
}

