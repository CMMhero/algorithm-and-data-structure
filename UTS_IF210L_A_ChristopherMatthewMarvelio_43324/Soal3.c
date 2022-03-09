/*
Nama: Christopher Matthew Marvelio
NIM : 00000043324
Kelas : A
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node {
	char huruf[1];
	struct Node *left, *right;
} Node;

void insert (Node **root, char input[]) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	if(*root == NULL) {
		strcpy(newNode->huruf, input);
        newNode->left = NULL;
        newNode->right = NULL;
        (*root) = newNode;
        (*root)->left = NULL;
        (*root)->right = NULL;
	}
    else if(strcmp(input, (*root)->huruf) < 0)
        insert(&(*root)->left, input);
    else if(strcmp(input, (*root)->huruf) > 0)
        insert(&(*root)->right, input);
}

void preorder(Node *root) {
	if(root != NULL) {
		printf("%s ", root->huruf);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node *root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%s ", root->huruf);
		inorder(root->right);
	}
}

void postorder(Node *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%s ", root->huruf);
	}
}

int main() {
	char input[1];
	Node *root = NULL;
	do {
		printf("Input: ");
		scanf("%s", input);
		if(strcmp(input, "#") == 0)
			break;
		insert(&root, input);
		
		printf("PreOrder  : "); preorder(root);
		printf("\nInOrder   : "); inorder(root);
		printf("\nPostOrder : "); postorder(root);
		printf("\n\n");
	} while(strcmp(input, "#") != 0);

	return 0;
}

