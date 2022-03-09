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

int main() {
	// #2 Siapkan head (kepala) dan sebuah node dari Linked List
	Mahasiswa *head, *node;
	// #3 Selalu buat head sebagai NULL;
	head = NULL;
	
	// #4 Tahap ini head sudah siap, hanya tinggal diisi dengan *node
	// Sebelum mengisinya dengan *node,
	// *node harus dialokasikan terlebih dahulu di dalam memory
	node = (Mahasiswa*) malloc(sizeof(Mahasiswa));
	
	// #5 Memasukkan data ke dalam node
	// Terdapat dua cara untuk memasukkan data ke dalam node
	// 1. Tampung terlebih dahulu dalam sebuah variabel
	//    baru setelahnya memasukkannya ke dalam node (line 33-34)
	// 2. Langsung memasukkan data ke dalam node tanpa
	//    perantara variabel lain. (line 35)
	
	// int nim = 14026;
	// node->nim = nim;
	node->nim = 14026;
	strcpy(node->nama, "James Christian Wira");
	strcpy(node->jurusan, "Informatika");
	
	// #6 INI BAGIAN PENTING
	// Set node->next sebagai NULL
	// Selalu lakukan ini setiap kali membuat node baru
	node->next = NULL;
	
	// #7 Setelah node pertama dibuat, node tersebut dapat disambungkan
	// ke head
	head = node;
	// Node pertama dalam Linked List sudah berhasil dibuat
	
	return 0;
}

