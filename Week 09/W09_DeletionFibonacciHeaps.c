#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h> 

// Buat sebuah struct untuk merepresentasikan node dalam heap
typedef struct node { 
	struct node* parent; // Parent pointer
	struct node* child; // Child pointer
	struct node* left; // Pointer ke node di kiri
	struct node* right; // Pointer ke node di kanan
	int key; // Value sebuah node
	int degree; // Degree sebuah node
	char mark; // Tanda hitam atau putih sebuah node
	char c; // Flag untuk membantu saat dalam function Find
} node; 

// Membuat variabel "mini" sebagai minimum pointer
struct node* mini = NULL;

// Mendeklarasikan jumlah node dalam heap
int no_of_nodes = 0;

// Function untuk memasukkan node ke dalam Heap 
void insertion(int val){ 
	struct node* new_node = (node*)malloc(sizeof(node));
	new_node->key = val;
	new_node->degree = 0;
	new_node->mark = 'W';
	new_node->c = 'N';
	new_node->parent = NULL; 
	new_node->child = NULL; 
	new_node->left = new_node; 
	new_node->right = new_node; 
	if (mini != NULL) { 
		(mini->left)->right = new_node; 
		new_node->right = mini; 
		new_node->left = mini->left;
		mini->left = new_node; 
		if (new_node->key < mini->key) mini = new_node; 
	}
	else { 
		mini = new_node; 
	}
	no_of_nodes++;
}

// Menghubungkan node heap dengan hubungan parent-child 
void Fibonnaci_link(struct node* ptr2, struct node* ptr1) {
	(ptr2->left)->right = ptr2->right; 
	(ptr2->right)->left = ptr2->left; 
	
	if (ptr1->right == ptr1) mini = ptr1; 
	
	ptr2->left = ptr2; 
	ptr2->right = ptr2; 
	ptr2->parent = ptr1; 
	
	if (ptr1->child == NULL) ptr1->child = ptr2;
	 
	ptr2->right = ptr1->child; 
	ptr2->left = (ptr1->child)->left;
	((ptr1->child)->left)->right = ptr2;
	(ptr1->child)->left = ptr2;
	
	if (ptr2->key < (ptr1->child)->key) ptr1->child = ptr2; 
	
	ptr1->degree++;
}

// Menggabungkan heap
void Consolidate() {
	int temp1; 
	int i;
	float temp2 = (log(no_of_nodes)) / (log(2)); 
	int temp3 = temp2; 
	struct node* arr[temp3]; 
	for (i = 0; i <= temp3; i++) arr[i] = NULL; 
	
	node* ptr1 = mini;
	node* ptr2;
	node* ptr3;
	node* ptr4 = ptr1;
	do {
		ptr4 = ptr4->right;
		temp1 = ptr1->degree;
		while(arr[temp1] != NULL) {
			ptr2 = arr[temp1];
			if (ptr1->key > ptr2->key) {
				ptr3 = ptr1;
				ptr1 = ptr2;
				ptr2 = ptr3;
			}
			if (ptr2 == mini) mini = ptr1;
			Fibonnaci_link(ptr2, ptr1);
			if (ptr1->right == ptr1) mini = ptr1;
			arr[temp1] = NULL;
			temp1++;
		}
		arr[temp1] = ptr1;
		ptr1 = ptr1->right;
	} while (ptr1 != mini);
	
	mini = NULL;
	int j;
	for (j = 0; j <= temp3; j++) {
		if (arr[j] != NULL) {
			arr[j]->left = arr[j];
			arr[j]->right = arr[j];
			if(mini != NULL) {
				(mini->left)->right = arr[j];
				arr[j]->right = mini;
				arr[j]->left = mini->left;
				mini->left = arr[j];
				if (arr[j]->key < mini->key) mini = arr[j];
			}
			else {
				mini = arr[j];
			}
			if(mini == NULL) mini = arr[j];
			else if (arr[j]->key < mini->key) mini = arr[j];
		}
	}
}

// Function untuk mengeluarkan nilai minimum dari heap
void Extract_min() {
	if (mini == NULL) printf("The heap is empty\n");
	else {
		node* temp = mini;
		node* pntr;
		pntr = temp;
		node* x = NULL;
		if (temp->child != NULL) {
			x = temp->child;
			do {
				pntr = x->right;
				(mini->left)->right = x;
				x->right = mini;
				x->left = mini->left;
				mini->left = x;
				if (x->key < mini->key) mini = x;
				x->parent = NULL;
				x = pntr;
			} while (pntr != temp->child);
		}
		(temp->left)->right = temp->right;
		(temp->right)->left = temp->left;
		mini = temp->right;
		if (temp == temp->right && temp->child == NULL) mini = NULL;
		else {
			mini = temp->right;
			Consolidate();
		}
		no_of_nodes--;
	}
}

// Memutuskan sebuah node dalam heap untuk diletakkan dalam daftar root
void Cut(struct node* found, struct node* temp)
{
	if (found == found->right) temp->child = NULL;
	
	(found->left)->right = found->right; 
	(found->right)->left = found->left; 
	if (found == temp->child) temp->child = found->right;
	
	temp->degree = temp->degree - 1; 
	found->right = found; 
	found->left = found; 
	(mini->left)->right = found; 
	found->right = mini; 
	found->left = mini->left; 
	mini->left = found; 
	found->parent = NULL; 
	found->mark = 'B';
}

// Function rekursif untuk Cut
void Cascase_cut(struct node* temp) {
	node* ptr5 = temp->parent; 
	if (ptr5 != NULL) { 
		if (temp->mark == 'W') {
			temp->mark = 'B';
		}
		else {
			Cut(temp, ptr5); 
			Cascase_cut(ptr5);
		}
	}
}

// Function untuk menurunkan value node dalam heap 
void Decrease_key(struct node* found, int val) {
	if (mini == NULL) printf("The Heap is Empty\n");
	
	if (found == NULL) printf("Node not found in the Heap\n");
	
	found->key = val;
	
	struct node* temp = found->parent; 
	if (temp != NULL && found->key < temp->key) {
		Cut(found, temp); 
		Cascase_cut(temp);
	}
	if (found->key < mini->key)
		mini = found;
}

// Function untuk mencari suatu node 
void Find(struct node* mini, int old_val, int val) {
	struct node* found = NULL; 
	node* temp5 = mini; 
	temp5->c = 'Y'; 
	node* found_ptr = NULL; 
	if (temp5->key == old_val) {
		found_ptr = temp5; 
		temp5->c = 'N'; 
		found = found_ptr; 
		Decrease_key(found, val);
	}
	if (found_ptr == NULL) { 
		if (temp5->child != NULL)
			Find(temp5->child, old_val, val); 
		if ((temp5->right)->c != 'Y')
			Find(temp5->right, old_val, val);
	}
	temp5->c = 'N'; 
	found = found_ptr;
}

// Menghapus node dari heap
void Deletion(int val) {
	if (mini == NULL) printf("The heap is empty\n"); 
	else {
		// Menurunkan value dalam node menajadi 
		Find(mini, val, 0);
		
		// Memanggil function Extract_min untuk 
		// menghapus nilai minimum dalam node 
		Extract_min(); 
		printf("Key Deleted\n");
	}
}

// Function untuk menampilkan isi Heap 
void display() { 
	node* ptr = mini; 
	if (ptr == NULL) printf("The Heap is Empty\n"); 
	
	else{ 
		printf("The root nodes of Heap are: \n"); 
		do { 
			printf("%d", ptr->key); 
			ptr = ptr->right; 
			if (ptr != mini) { 
				printf("-->");
			}
		} while (ptr != mini && ptr->right != NULL); 
	printf("\nThe heap has %d nodes\n\n", no_of_nodes);
	}
}

int main() {
	// Membuat heap dan memasukan 3 node ke dalamnya 
	printf("Creating an initial heap\n"); 
	insertion(5); 
	insertion(2); 
	insertion(8);
	
	// Menampilkan heap 
	display();
	
	// Mengeluarkan nilai minimum dari heap 
	printf("Extracting min\n"); 
	Extract_min(); 
	display();
	
	// Mengurangi node dengan value 8 menjadi 7 
	printf("Decrease value of 8 to 7\n"); 
	Find(mini, 8, 7); 
	display();
	
	// Menghapus node dengan value 7 
	printf("Delete the node 7\n"); 
	Deletion(7); 
	display();
	
	return 0;
}


