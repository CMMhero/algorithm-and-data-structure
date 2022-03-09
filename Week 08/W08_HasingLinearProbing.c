#include <stdio.h>
#include <stdbool.h>

void hashFunction(int input, int hashTable[]);

int main() {
	// #1 Create the Hash Table
	int HashT[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int inputKey;
	
	while (1) {
		printf("Input a number: ");
		scanf("%d", &inputKey);
		printf("Processing in Hash Fucntion\n");
		
		hashFunction(inputKey, HashT);
		
		//Print Hasil
		int i;
		printf("current Hash Table: ");
		for (i = 0; i < 10; i++) {
			printf("[%d]", HashT[i]);
		}
		printf("\n\n");
	}
	
	return 0;
}

// #2 Create the Hash Function
void hashFunction(int input, int hashTable[]) {
	int hash;
	bool check = false;
	hash = input % 10;
	int temp = hash;
	while (1){ 
		if (hashTable[temp] == 0){
			printf("Inserting data to Hash Table\n");
			hashTable[temp] = input;
			break;
		}
		temp++;
		if (hash == temp) {
			printf("HashTable Full\n");
			break;
		}
		if (temp > 9) {
			temp = 0;
		}
	}
}





