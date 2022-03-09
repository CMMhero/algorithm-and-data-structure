#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Mahasiswa {
	char nama[100];
	char jurusan[30];
	int nim;
	struct Mahasiswa *next, *prev; 	//prev digunakan untuk menunjuk node sebelumnya
} Mahasiswa;

void *createNewNode(int nim, char *nama, char *jurusan, Mahasiswa **tail) {
	Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
	newNode->nim = nim;
	strcpy(newNode->nama, nama);
	strcpy(newNode->jurusan, jurusan);
	newNode->next = NULL;
	//Tambahin 3 baris ini
	newNode->prev = *tail;
	(*tail)->next = newNode;
	*tail = newNode;
}

void printLinkedList(Mahasiswa *head) {
	Mahasiswa *temp;
	temp = head;
	int i = 1;
	while(temp != NULL) {
		printf("Data ke %d\n", i);
		printf("NIM     : %d\n", temp->nim);
		printf("Nama    : %s\n", temp->nama);
		printf("Jurusan : %s\n\n", temp->jurusan);
		temp = temp->next;
		i++;
	}
}

void headDeletion(Mahasiswa **head) {
	//Menyiapkan variabel untuk dihapus
	Mahasiswa *trash = *head;
	*head = trash->next; //Memindahkan head ke new head
	(*head)->prev = NULL; //Menghapus koneksi head ke node sebelumnya
	trash->next = NULL; //Menghapus koneksi node sebelumbya ke new head
	free(trash); //Menghapus trash
}

void tailDeletion(Mahasiswa **tail) {
	//Menyiapkan variabel untuk dihapus
	Mahasiswa *trash = *tail;
	*tail = trash->prev; //Memindahkan head ke new head
	(*tail)->next = NULL; //Menghapus koneksi head ke node sebelumnya
	trash->prev = NULL; //Menghapus koneksi node sebelumbya ke new head
	free(trash); //Menghapus trash
}

void middleDeletion(Mahasiswa **head, int target) {
	//Menyiapkan variabel untuk dihapus
	Mahasiswa *trash = *head, *tempBefore, *tempAfter;
	while(trash->nim != target) { //Cari sampai ketemu yang mau dihapus
		trash = trash->next;
	}
	//Sampai tahap ini, trash adalah node yang akan dihapus
	//Untuk membuktikannya, silahkan melakukan printf nim atau namanya
	tempBefore = trash->prev; //tempBefore = 1 node sebelum yang akan dihapus
	tempAfter = trash->next; //tempAfter = 1 node setelah trash
	//Menyambungkan 2 buah node yang terpisah oleh trash
	tempBefore->next = tempAfter;
	tempAfter->prev = tempBefore;
	//Menghapus koneksi trash ke Linked List
	trash->prev = NULL;
	trash->next = NULL;
	free(trash); //Menghapus trash
}

int main()
{
	Mahasiswa *head, *node, *tail;
	head = tail = NULL;
	
	node = (Mahasiswa*) malloc(sizeof(Mahasiswa));
	node->nim = 14026;
	strcpy(node->nama, "James Christian Wira");
	strcpy(node->jurusan, "Informatika");
	//Untuk pembuatan node pertama. Selalu begini
	//Atau cek apakah head == NULL? (ada Linked List atau ga)
	node->next = node->prev = NULL;
	head = node;
	tail = node;
	
	node = (Mahasiswa*) malloc(sizeof(Mahasiswa));
	node->nim = 17492;
	strcpy(node->nama, "Matthew Evans");
	strcpy(node->jurusan, "Informatika");
	node->next = NULL;
	//Penambahan yang dilakukan pada tutorial ini adalah penambahan ke belakang
	node->prev = tail; //Menunjuk ke node 'terakhir'
	tail->next = node; //'tail'->next menunjuk ke node baru
	tail = node; //Memindahkan tail ke node bari. node baru menjadi tail
	//Line 63-65 harus dilakuin terus setiap kali nambah node
	//Supaya ga diketik berkali-kali,
	//proses ini dipindahin aja ke function createNewNode
	//Yang perlu ditambahin hanya kirim tail ke function tersebut
	
	createNewNode(13633, "Justin Susanto", "Informatika", &tail);
	createNewNode(12335, "Vionie Laorensa", "Informatika", &tail);
	createNewNode(14045, "Mario Alexander", "Informatika", &tail);
	createNewNode(11440, "Leonardo Pratama", "Informatika", &tail);
	createNewNode(15840, "Handriki Kasa", "Informatika", &tail);
	createNewNode(15773, "Cindy Michelle", "Informatika", &tail);
	createNewNode(19587, "Aldric Leonardo", "Informatika", &tail);
	
	printf("All data inside linked list\n");
	printLinkedList(head);
	
	printf("All data after 2x head deletion\n");
	headDeletion(&head);
	headDeletion(&head);
	printLinkedList(head);
	
	printf("All data after 1x tail deletion\n");
	tailDeletion(&tail);
	printLinkedList(head);
	
	printf("All data after middle deletion (Mario Alexander - 14045)\n");
	middleDeletion(&head, 14045);
	printLinkedList(head);
	
	return 0;
}

