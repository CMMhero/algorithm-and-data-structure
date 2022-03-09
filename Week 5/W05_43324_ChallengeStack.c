#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Parenthesis{
    char data;
    struct Parenthesis *next;
} Parenthesis;

void push(Parenthesis **stack, char pola) {
    Parenthesis *newPola = (Parenthesis*) malloc(sizeof(Parenthesis));
    newPola->data = pola;
    newPola->next = *stack;
    *stack = newPola;
}

int pop(Parenthesis **stack) {
    char a;
    Parenthesis *trash;
    trash = *stack;
    a = trash->data;
    *stack = trash->next;
    free(trash);
    return a;
}

int isPair(char p1,char p2){
    if(p1=='(' && p2==')')
        return 1;
    else if(p1=='{' && p2=='}')
        return 1;
    else if(p1=='[' && p2==']')
        return 1;
    else return 0;
}

int isValid(char pola[]) {
    int i;
    Parenthesis *stack = NULL;
    for(i=0; pola[i] != '\0'; i++) {
        if(pola[i]=='{' || pola[i]=='(' || pola[i]=='[') {
            push(&stack, pola[i]);
        } else if(pola[i]=='}' || pola[i]==')' || pola[i]==']') { 
            if(stack==NULL)
                return 0;
            else if(!isPair(pop(&stack), pola[i]))
                return 0;
        } else if(pola[i] != ' '){
        	return 0;
		}
    }

    if(stack==NULL)
        return 1;
    else
        return 0;
}

int main() {
	char pola[50];
	do {
		printf("Masukkan pola: ");
		gets(pola);
		
		if(strcmp(pola, "-1") == 0)
			break;
		
		if(isValid(pola))
		    printf("Valid Parenthesis expression !\n\n");
		else
		    printf("Invalid Parenthesis expression !\n\n");
	} while(strcmp(pola, "-1") != 0);
	
	return 0;
}
