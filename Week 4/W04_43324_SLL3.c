#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// #1 Siapkan tipe data untuk Linked List
typedef struct Mahasiswa {
	char nama[100];
	char jurusan[30];
	int nim;
	//*next digunakan untuk menunjuk ke node selanjutnya
	struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa *createNewNode(int nim, char *nama, char *jurusan) {
	Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
	newNode->nim = nim;
	strcpy(newNode->nama, nama);
	strcpy(newNode->jurusan, jurusan);
	newNode->next = NULL;
	return newNode;
}

void printLinkedList(Mahasiswa *head) {
	Mahasiswa *temp;
	//Menyiapkan variabel yang akan berjalan dalam Linked List
	temp = head; //Set temp ke list paling awal
	int i = 1;
	while(temp != NULL) {
		//Lakukan iterasi hingga tidak menemukan node selanjutnya
		printf("Data ke %d\n", i);
		printf("NIM     : %d\n", temp->nim);
		printf("Nama    : %s\n", temp->nama);
		printf("Jurusan : %s\n\n", temp->jurusan);
		temp = temp->next;
		i++;
	}
}

int main() {
	Mahasiswa *head, *node;
	head = NULL;
	node = (Mahasiswa*) malloc(sizeof(Mahasiswa));
	
	node->nim = 14026;
	strcpy(node->nama, "James Christian Wira");
	strcpy(node->jurusan, "Informatika");
	head = node;
	//Code di atas merupakan code dari Tutorial 1.1
	//yang dihilangkan komentarnya
	
	//#1 Tambahkan *tail untuk menunjuk node terakhir
	Mahasiswa *tail;
	tail = node;
	
	//#2 Buat node baru. Pembuatan node baru dapat menggunakan
	//variabel node yang sama namun melakukan ulang malloc
	
	//Mahasiswa *newNode;
	//Jika tidak ingin menggunakan variabel node yang sudah ada
	node = createNewNode(17492, "Matthew Evans", "Informatika");
	//#3 Jika tidak ingin menggunakan variavel node yang sudah ada
	tail->next = node; //#3.1 Set tail->next = node;
	tail = node; //#3.2 Set tail = node; untuk mengembalikan
	//posisi tail ke paling akhir
	
	//#4 Jika penambahan node dilakukan di depan
	//Penggunaan tail tidak dibutuhkan
	node = createNewNode(13633, "Justin Susanto", "Informatika");
	node->next = head; //#4.1 Set node->next = head;
	head = node; //#4.2 Set head = node; untuk mengembalikan
	//posisi head ke paling awal
	
	printLinkedList(head);

/*	
	//Delete Posisi Awal
	node = createNewNode(13633, "Justin Susanto", "Informatika");
	node->next = head;
	head = node;
	
	printf("Data SEBELUM di hapus\n");
	printLinkedList(head);
	
	Mahasiswa *trash; //Menyiapkan variabel untuk menghapus memory
	trash = head;
	head = head->next;
	free(trash);
	
	printf("Data SETELAH di hapus\n");
	printLinkedList(head);
	
*/

/*
	//Delete posisi akhir
	Mahasiswa *trash;
	trash = head;
	while(trash->next != tail) {
		trash = trash->next;
	}
	tail = trash;
	trash = tail->next;
	tail->next = NULL;
	free(trash);
	
	printf("Data SETELAH dihapus\n");
	printLinkedList(head);
*/

///*
	//Delete posisi tengah
	Mahasiswa *trash, *temp;
	trash = head;
	while(strcmp(trash->next->nama, "James Christian Wira") == 1) {
		printf("%s\n", trash->nama);
		trash = trash->next;
	}
	if(trash->nim == head->nim) printf("true\n");
	else printf("false\n");
	temp = trash;
	trash = trash->next;
	temp->next = trash->next;
	trash->next = NULL;
	free(trash);
	
	printf("Data SETELAH dihapus\n");
	printLinkedList(head);
//*/		
		
	return 0;
}

