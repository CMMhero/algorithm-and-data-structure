#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Number {
	int angka;
	struct Number *next;
} Number;

int isEmpty(Number *queue) {
	if(queue == NULL)
		return 1;
	else
		return 0;
}

void enqueue(Number **head, Number **tail, int angka) {
	Number *data = (Number*) malloc(sizeof(Number));
	data->angka = angka;
	data->next = NULL;

	if(isEmpty(*head)) {
		*head = data;
	} else {
		(*tail)->next = data;	
	}
	*tail = data;
}

void dequeue(Number **head) {
	if(isEmpty(*head))
		return;
	Number *trash = *head;
	*head = trash->next;
	free(trash);
}

void printnum(Number **head) {
	Number *temp = *head;
	while(temp != NULL) {
		printf("%d ", temp->angka);
		temp = temp->next;
	}
	printf("\n\n");
}

int main() {
	Number *head, *tail;
	head = tail = NULL;
	int i, angka;
	
	do {
		printf("Masukkan angka: ");
		scanf("%d", &angka);
		if(isEmpty(head)) {
			for(i=0; i<angka; i++) {
				enqueue(&head, &tail, angka);
			}
			printf("Angka yang berhasil dienqueue sebanyak %d kali : ", angka);
			printnum(&head);
		} else if(angka >= head->angka) {
			for(i=0; i<head->angka; i++) {
				enqueue(&head, &tail, angka);
			}
			printf("Angka yang berhasil dienqueue sebanyak %d kali : ", head->angka);
			printnum(&head);
		} else {
			for(i=0; i<angka; i++) {
				dequeue(&head);
			}
			printf("Angka yang berhasil didequeue sebanyak %d kali : ", angka);
			printnum(&head);
		}
	} while(!isEmpty(head));

	return 0;
}

