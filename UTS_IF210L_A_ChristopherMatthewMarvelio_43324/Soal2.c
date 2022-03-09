/*
Nama: Christopher Matthew Marvelio
NIM : 00000043324
Kelas : A
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Country1 {
	char negara[12];
	struct Country1 *next;
} Country1;

typedef struct Country2 {
	char negara[12];
	struct Country2 *next;
} Country2;

Country1 *head, *tail, *node;
Country2 *chead, *ctail, *cnode;

void insertC1(char a[]) {
	node = (Country1*) malloc(sizeof(Country1));
	strcpy(node->negara, a);
    node->next = NULL;
    
    if(head == NULL)
        head = node;
    else
        tail->next = node;
    tail = node;
}

void insertC2(char b[]) {
	cnode = (Country2*) malloc(sizeof(Country2));
	strcpy(cnode->negara, b);
    cnode->next = NULL;
    
    if(chead == NULL)
        chead = cnode;
    else
        ctail->next = cnode;
    ctail = cnode;
}

int main() {
	insertC1("Afrika");
	insertC1("Amerika");
	insertC1("Belanda");
	insertC1("Perancis");
	insertC1("Italia");
	insertC1("Spanyol");
	insertC1("Portugal");
	insertC1("Swiss");
	insertC1("Denmark");
	insertC1("Jerman");
	
	insertC2("Jepang");
	insertC2("Swiss");
	insertC2("Afrika");
	insertC2("Belgia");
	insertC2("Jerman");
	insertC2("Swedia");
	insertC2("Korea");
	insertC2("Australia");
	
	Country1 *temp = head;
	Country2 *ctemp = chead;
	printf("Queue 1: ");
	while(temp != NULL) {
		printf("%s ", temp->negara);
		temp = temp->next;
	}
	printf("\nQueue 2: ");
	while(ctemp != NULL) {
		printf("%s ", ctemp->negara);
		ctemp = ctemp->next;
	}
	printf("\n");

	temp = head;
	ctemp = head;
	printf("\nNegara yang sama: ");
	while(temp != NULL) {
		ctemp = chead;
		while(ctemp != NULL) {
			if(strcmp(temp->negara, ctemp->negara) == 0) {
				printf("%s ", temp->negara);
			}
			ctemp = ctemp->next;
		}
		temp = temp->next;
	}
	
	return 0;
}

