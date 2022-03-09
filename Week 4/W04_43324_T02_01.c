#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct Student{
	char name[50];
	char major[35];
	char nim[12];
	float task, midterm, finalterm, total;
	char grade[3];
	struct Student *next, *prev;
} *head, *tail, *node;

void input() {
	char nim[12];
	char name[50];
	char major[35];
	float task, midterm, finalterm, total=0;
	char grade[3];
	
	system("cls");
	printf("  Insert Student Information  \n");
	printf("------------------------------\n");
	printf("NIM         : ");
	scanf("%[^\n]", &nim); fflush(stdin);
	printf("Name        : ");
	scanf("%[^\n]s", &name); fflush(stdin);
	printf("Major       : ");
	scanf("%[^\n]s", &major); fflush(stdin);
	
	printf("\n");
	printf("     Insert Student Score     \n");
	printf("------------------------------\n");
	printf("Task        : ");
	scanf("%f", &task); fflush(stdin);
	printf("Mid Term    : ");
	scanf("%f", &midterm);fflush(stdin);
	printf("Final Term  : ");
	scanf("%f", &finalterm);fflush(stdin);
	
	total=(0.3*task + 0.3*midterm + 0.4*finalterm);
	if(total >= 95)
		strcpy(grade, "A+");
	else if(total >=85)
		strcpy(grade, "A");
	else if(total >= 80)
		strcpy(grade, "A-");
	else if(total >= 75)
		strcpy(grade, "B+");
	else if(total >= 70)
		strcpy(grade, "B");
	else if(total >= 65)
		strcpy(grade, "C");
	else if(total >= 60)
		strcpy(grade, "C-");
	else if(total >= 55)
		strcpy(grade, "D");
	else
		strcpy(grade, "E");
	printf("\nFinal Score : %.2f\n",total);
	printf("Grade       : %s\n\n",grade);
	
	FILE *fout = fopen("dataMahasiswa.txt", "a");
		fprintf(fout, "%s#%s#%s\n", nim, name, major);
	fclose(fout);
	
	FILE *fout2 = fopen("nilaiMahasiswa.txt", "a");
		fprintf(fout2, "%s#%.0f#%.0f#%.0f#%.2f#%s\n", nim, task, midterm, finalterm, total, grade);
	fclose(fout2);
	
	printf("Inserting data\n");
	printf("New students added\n");
	printf("Press any key to continue\n");
	getchar();
}

void show(struct Student *head) {
	system("cls");
	printf("                 List of Student Information                         \n");
	printf("---------------------------------------------------------------------\n");
	printf("|No.|             Name             |      Major       |     NIM     |\n");
	printf("---------------------------------------------------------------------\n");

	struct Student *temp;
	temp = head;
	int i=1;
	while(temp != NULL) {
		printf("|%-3d| %-28s | %-16s | %-11s |\n", i, temp->name, temp->major, temp->nim);
		temp = temp->next;
		i++;
	}
	printf("---------------------------------------------------------------------\n");
	getchar();
}

void score(struct Student *head, struct Student *tail, struct Student *node) {	
	head = NULL;
	FILE *fnilai = fopen("nilaiMahasiswa.txt", "r");
	while(!feof(fnilai)) {
		node = (struct Student*)malloc(sizeof(struct Student));
		fscanf(fnilai, "%[^#]#%f#%f#%f#%f#%[^\n]\n", node->nim, &node->task, &node->midterm, &node->finalterm, &node->total, &node->grade);
		node->next = NULL;
		
		if(head == NULL) {
			node->prev = NULL;
			head = node;
			tail = node;
		}
		else {
			node->next = NULL;
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}
	fclose(fnilai);
	system("cls");
	printf("                    List of Student Information                     \n");
	printf("--------------------------------------------------------------------\n");
	printf("|No.|     NIM     |  Task  | Mid Term | Final Term | Total | Grade |\n");
	printf("--------------------------------------------------------------------\n");
	
	struct Student *temp;
	temp = head;
	int i=1;
	while(temp != NULL) {
		printf("|%-3d| %-11s | %-6.2f | %-8.2f | %-10.2f | %-6.2f| %-5s |\n", i, temp->nim, temp->task, temp->midterm, temp->finalterm, temp->total, temp->grade);
		temp = temp->next;
		i++;
	}
	printf("--------------------------------------------------------------------\n");
	getchar();
}

// \/ Kode Failed XD \/
//void del(Student **head, Student **tail) {
//	char tnim[12];
//	printf("\nEnter the NIM you want to delete: ");
//	scanf("%s", &tnim);
//	
//	Student *trash, *temp, *temp2, *tempBefore, *tempAfter;
//	trash = *head;
//	while(strcmp(trash->nim, tnim) != 0) {
//		trash = trash->next;
//	}
//	if(trash->next == NULL) {
//		trash = *tail;
//		*tail = trash->prev;
//		(*tail)->next = NULL;
//		free(trash);
//	} else {
//		tempBefore = trash->prev;
//		tempAfter = trash->next;
//		tempBefore->next = tempAfter;
//		tempAfter->prev = tempBefore;
//		trash->prev = NULL;
//		trash->next = NULL;
//		free(trash);
//	}
//
//	temp = *head;
//	FILE *fout = fopen("dataMahasiswa.txt", "w");
//		while(temp != NULL) {
//			fprintf(fout, "%s#%s#%s\n", temp->nim, temp->name, temp->major);
//			temp = temp->next;
//		}
//	fclose(fout);
//	
//	temp2 = *head;
//	FILE *fout2 = fopen("nilaiMahasiswa.txt", "w");
//		while(temp2 != NULL) {
//			fprintf(fout2, "%s#%.0f#%.0f#%.0f#%.2f#%s\n", temp2->nim, temp2->task, temp2->midterm, temp2->finalterm, temp2->total, temp2->grade);
//			temp2 = temp2->next;
//		}
//	fclose(fout2);
//	
//	printf("\nData deleted for student NIM %s\n", tnim);
//	printf("Press any key to continue\n");
//	getchar();
//	getchar();
//}

int main() {
	int i, pilihan=1;
	do
	{		
		i=0;
		head = NULL;
		FILE *fp = fopen("dataMahasiswa.txt", "r");
		while(!feof(fp)) {
			node = (struct Student*)malloc(sizeof(struct Student));
			fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", node->nim, node->name, node->major);
			node->next = NULL;
			
			if(head == NULL) {
				node->prev = NULL;
				head = node;
				tail = node;
			}
			else {
				node->next = NULL;
				node->prev = tail;
				tail->next = node;
				tail = node;
			}
			i++;
		}
		fclose(fp);
		
		system("cls");
		printf("Welcome to simple student database (%d Student(s) Added)\n", i);
		printf("1. Input new student\n");
		printf("2. Show all students\n");
		printf("3. Show all scores\n");
//		printf("4. Delete data\n");	//Gak jadi
		printf("0. Exit\n");
		printf("Choose: ");
		scanf("%d", &pilihan); fflush(stdin);
		
		switch(pilihan) {
			case 0:
				break;
			case 1: {
				input();
				break;
			}
			case 2:
				show(head);
				break;
			case 3: {
				score(head, tail, node);
				break;
			}
//			Gak jadi
//			case 4: {
//				del(&head, &tail);
//				break;
//			}
			default:
				printf("\nInvalid option");
				getchar();
				break;
		}
	}
	while(pilihan != 0);

	return 0;
}

