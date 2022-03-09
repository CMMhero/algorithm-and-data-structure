#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[50];
	char major[35];
	char nim[12];
	float task;
	float midterm;
	float finalterm;
	float total;
	char grade[5];
}Student;

void input() {
	system("cls");
	char nim[12];
	char name[50];
	char major[35];
	float task, midterm, finalterm, total=0;
	char grade[5];
	
	printf("  Insert Student Information  \n");
	printf("------------------------------\n");
	printf("NIM         : ");
	scanf("%[^\n]", &nim);fflush(stdin);
	printf("Name        : ");
	scanf("%[^\n]s", &name);fflush(stdin);
	printf("Major       : ");
	scanf("%[^\n]s", &major);fflush(stdin);
	
	printf("\n");
	printf("     Insert Student Score     \n");
	printf("------------------------------\n");
	printf("Task        : ");
	scanf("%f", &task);fflush(stdin);
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

void show(int *i, Student students[]) {
	int x;
	system("cls");
	printf("                 List of Student Information                         \n");
	printf("---------------------------------------------------------------------\n");
	printf("|No.|             Name             |      Major       |     NIM     |\n");
	printf("---------------------------------------------------------------------\n");
	
	for(x=0; x<*i; x++) {
		printf("|%-3d| %-28s | %-16s | %-11s |\n", x+1, students[x].name, students[x].major, students[x].nim);
	}
	printf("---------------------------------------------------------------------\n");
	getchar();
}

void score(Student students[]) {
	int x, j=0;
	
	FILE *fnilai = fopen("nilaiMahasiswa.txt", "r");
	while(!feof(fnilai)) {
		Student newStudents;
		fscanf(fnilai, "%[^#]#%f#%f#%f#%f#%[^\n]\n", newStudents.nim, &newStudents.task, &newStudents.midterm, &newStudents.finalterm, &newStudents.total, &newStudents.grade);
		students[j] = newStudents;
		j++;
	}
	fclose(fnilai);
	
	system("cls");
	printf("                    List of Student Information                     \n");
	printf("--------------------------------------------------------------------\n");
	printf("|No.|     NIM     |  Task  | Mid Term | Final Term | Total | Grade |\n");
	printf("--------------------------------------------------------------------\n");
	
	for(x=0; x<j; x++) {
		printf("|%-3d| %-11s | %-6.2f | %-8.2f | %-10.2f | %-6.2f| %-5s |\n", x+1, students[x].nim, students[x].task, students[x].midterm, students[x].finalterm, students[x].total, students[x].grade);
	}
	printf("--------------------------------------------------------------------\n");
	getchar();
}

int main() {
	Student students[100];
	int i, pilihan=1;
	do
	{		
		i=0;
		FILE *fp = fopen("dataMahasiswa.txt", "r");
		while(!feof(fp)) {
			Student newStudent;
			fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", newStudent.nim, newStudent.name, newStudent.major);
			students[i] = newStudent;
			i++;
		}
		fclose(fp);
		
		system("cls");
		printf("Welcome to simple studet database (%d/100)\n", i);
		printf("1. Input new student\n");
		printf("2. Show all students\n");
		printf("3. Show all scores\n");
		printf("0. Exit\n");
		printf("Choose: ");
		scanf("%d", &pilihan);fflush(stdin);
		
		switch(pilihan) {
			case 1: {
				if(i!=100) {
					input();
				} else {
					printf("Database is full\n");
					printf("Press any key to continue");
					getchar();
				}
				break;
			}
			case 2:
				show(&i, students);
				break;
			case 3:
				score(students);
				break;
		}
	}
	while(pilihan != 0);

	return 0;
}

