#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50], major[35], nim[12];
    float task, midterm, finalterm, total;
    char grade[5];
} Student;

int charVal(char a[])
{
    int val = atoi(a);
    return val;
}

void swap(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void sort(Student students[], int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        for (j = n; j >= 1; j--)
        {
            if (charVal(students[j].nim) < charVal(students[j - 1].nim))
                swap(&students[j], &students[j - 1]);
        }
    }
}

int search(Student students[], int size, char key[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(key, students[i].nim) == 0)
        {
            return i;
        }
    }
    return -1;
}

void input()
{
    system("cls");
    char name[50], major[35], nim[12];
    float task, midterm, finalterm, total = 0;
    char grade[5];

    printf("  Insert Student Information  \n");
    printf("------------------------------\n");
    printf("NIM         : ");
    scanf("%[^\n]", &nim);
    fflush(stdin);
    printf("Name        : ");
    scanf("%[^\n]s", &name);
    fflush(stdin);
    printf("Major       : ");
    scanf("%[^\n]s", &major);
    fflush(stdin);

    printf("\n");
    printf("     Insert Student Score     \n");
    printf("------------------------------\n");
    printf("Task        : ");
    scanf("%f", &task);
    fflush(stdin);
    printf("Mid Term    : ");
    scanf("%f", &midterm);
    fflush(stdin);
    printf("Final Term  : ");
    scanf("%f", &finalterm);
    fflush(stdin);

    total = (0.3 * task + 0.3 * midterm + 0.4 * finalterm);
    if (total >= 95)
        strcpy(grade, "A+");
    else if (total >= 85)
        strcpy(grade, "A");
    else if (total >= 80)
        strcpy(grade, "A-");
    else if (total >= 75)
        strcpy(grade, "B+");
    else if (total >= 70)
        strcpy(grade, "B");
    else if (total >= 65)
        strcpy(grade, "C");
    else if (total >= 60)
        strcpy(grade, "C-");
    else if (total >= 55)
        strcpy(grade, "D");
    else
        strcpy(grade, "E");
    printf("\nFinal Score : %.2f\n", total);
    printf("Grade       : %s\n\n", grade);

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

void show(int i, Student students[])
{
    int x;
    system("cls");
    printf("                 List of Student Information                         \n");
    printf("---------------------------------------------------------------------\n");
    printf("|No.|             Name             |      Major       |     NIM     |\n");
    printf("---------------------------------------------------------------------\n");

    for (x = 0; x < i; x++)
    {
        printf("|%-3d| %-28s | %-16s | %-11s |\n", x + 1, students[x].name, students[x].major, students[x].nim);
    }
    printf("---------------------------------------------------------------------\n");
    getchar();
}

void score(int i, Student students[])
{
    int x;
    system("cls");
    printf("                    List of Student Information                     \n");
    printf("--------------------------------------------------------------------\n");
    printf("|No.|     NIM     |  Task  | Mid Term | Final Term | Total | Grade |\n");
    printf("--------------------------------------------------------------------\n");

    for (x = 0; x < i; x++)
    {
        printf("|%-3d| %-11s | %-6.2f | %-8.2f | %-10.2f | %-6.2f| %-5s |\n", x + 1, students[x].nim, students[x].task, students[x].midterm, students[x].finalterm, students[x].total, students[x].grade);
    }
    printf("--------------------------------------------------------------------\n");
    getchar();
}

void detail(int i, Student students[])
{
    sort(students, i);

    int x;
    system("cls");
    printf("                  Sorted List of Student Information                 \n");
    printf("---------------------------------------------------------------------\n");
    printf("|No.|             Name             |      Major       |     NIM     |\n");
    printf("---------------------------------------------------------------------\n");

    for (x = 0; x < i; x++)
    {
        printf("|%-3d| %-28s | %-16s | %-11s |\n", x + 1, students[x].name, students[x].major, students[x].nim);
    }
    printf("---------------------------------------------------------------------\n");

    int found = 0;
    char nim[12];
    printf("Cari NIM: ");
    scanf("%s", nim);
    fflush(stdin);

    found = search(students, i, nim);

    if (found != -1)
    {
        printf("\nMahasiswa dengan NIM %s ditemukan pada index ke %d\n", nim, found);
        printf("---------------------------------------------------------------------\n");
        printf("|%-3d| %-28s | %-16s | %-11s |\n", found, students[found].name, students[found].major, students[found].nim);
        printf("---------------------------------------------------------------------\n");
    }
    else
    {
        printf("\nMahasiswa dengan NIM %s tidak ditemukan", nim);
    }

    getchar();
}

int main()
{
    Student students[100];
    int i, pilihan = 1;
    do
    {
        i = 0;
        FILE *fp = fopen("dataMahasiswa.txt", "r");
        while (!feof(fp))
        {
            Student newStudent;
            fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", newStudent.nim, newStudent.name, newStudent.major);
            students[i] = newStudent;
            i++;
        }
        fclose(fp);

        i = 0;
        FILE *fnilai = fopen("nilaiMahasiswa.txt", "r");
        while (!feof(fnilai))
        {
            Student newStudent;
            fscanf(fnilai, "%[^#]#%f#%f#%f#%f#%[^\n]\n", newStudent.nim, &newStudent.task, &newStudent.midterm, &newStudent.finalterm, &newStudent.total, &newStudent.grade);
            students[i] = newStudent;
            i++;
        }
        fclose(fnilai);

        system("cls");
        printf("Welcome to simple student database (%d/100)\n", i);
        printf("1. Input new student\n");
        printf("2. Show all students\n");
        printf("3. Show all scores\n");
        printf("4. Show student detail\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        if (pilihan == 0)
            break;

        switch (pilihan)
        {
        case 1:
        {
            if (i < 100)
            {
                input();
            }
            else
            {
                printf("Database is full\n");
                printf("Press any key to continue");
                getchar();
            }
            break;
        }
        case 2:
            show(i, students);
            break;
        case 3:
            score(i, students);
            break;
        case 4:
            detail(i, students);
            break;
        default:
        {
            printf("\nInput salah!");
            getchar();
        }
        }
    } while (pilihan != 0);

    return 0;
}
