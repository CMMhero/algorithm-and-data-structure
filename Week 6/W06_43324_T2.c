#include <stdio.h>
#include <string.h>

int top = -1;
char stack[10];
 
void push(char input) {
	top++;
	stack[top] = input;
}
 
void pop() {
	printf("%c", stack[top]);
	top--;
}

void koreksi(char input[]) {
	int i;
    int len = strlen(input)-1;
    
    printf("Input  : %s\n", input);
    printf("Output : ");
    
    for(i=len; i>=0; i--) {
		if(input[i] >= 'a' &&  input[i] <= 'z') {
			push(input[i]);
		} else if(input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-') {
			pop();
			push(input[i]);
			pop();
		}
	}
	while(top != -1)
		pop();
		
	printf("\n\n");
}

int main() {
	char input[10];
	strcpy(input, "-*+abcd"); koreksi(input);
	strcpy(input, "*+ab+cd"); koreksi(input);
	strcpy(input, "+/ab/cd"); koreksi(input);

	return 0;
}
