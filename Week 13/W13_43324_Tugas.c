#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char major[35];
    char nim[12];
} Student;

typedef struct
{
    char nim[12];
    float tugas, uts, uas, total;
    char grade[3];
} Score;

void readData(Student students[], int *counter)
{
    int i = 0;
    FILE *fp = fopen("dataMahasiswa.txt", "r");
    while (!feof(fp))
    {
        Student std;
        fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", std.nim, std.name, std.major);
        students[i] = std;
        *counter = i;
        i++;
    }
    fclose(fp);
}

void readScore(Score scores[])
{
    int i = 0;
    FILE *fp = fopen("nilaiMahasiswa.txt", "r");
    while (!feof(fp))
    {
        Score scr;
        fscanf(fp, "%[^#]#%f#%f#%f#%f#%[^\n]\n", scr.nim, &scr.tugas, &scr.uts, &scr.uas, &scr.total, scr.grade);
        scores[i] = scr;
        i++;
    }
    fclose(fp);
}

int charVal(char a[])
{
    int val = atoi(a);
    return val;
}

void swap(Score *a, Score *b)
{
    Score temp = *a;
    *a = *b;
    *b = temp;
}

void sort(Score scores[], int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        for (j = n; j >= 1; j--)
        {
            if (charVal(scores[j].nim) < charVal(scores[j - 1].nim))
                swap(&scores[j], &scores[j - 1]);
        }
    }
}

int search(Score scores[], int size, char key[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(key, scores[i].nim) == 0)
        {
            return i;
        }
    }
    return -1;
}

char *getGrade(float total)
{
    if (total >= 95)
        return "A+";
    else if (total >= 85 && total < 95)
        return "A";
    else if (total >= 80 && total < 85)
        return "A-";
    else if (total >= 75 && total < 80)
        return "B+";
    else if (total >= 70 && total < 75)
        return "B";
    else if (total >= 65 && total < 70)
        return "C+";
    else if (total >= 60 && total < 65)
        return "C";
    else if (total >= 55 && total < 60)
        return "D";
    else
        return "E";
}

void insertStudent(int *currentStudent, Student allStudents[])
{
    Student nStudent;
    Score nScore;
    system("cls");
    printf("  Insert Student Information  \n");
    printf("------------------------------\n");
    printf("NIM         : ");
    scanf("%[^\n]", nStudent.nim);
    getchar();
    printf("Name        : ");
    scanf("%[^\n]", nStudent.name);
    getchar();
    printf("Major       : ");
    scanf("%[^\n]", nStudent.major);
    getchar();

    printf("\n  Insert Student Score  \n");
    printf("------------------------------\n");
    printf("Task        : ");
    scanf("%f", &nScore.tugas);
    printf("Mid Term    : ");
    scanf("%f", &nScore.uts);
    printf("Final Term  : ");
    scanf("%f", &nScore.uas);

    nScore.total = nScore.tugas * 0.3 + nScore.uts * 0.3 + nScore.uas * 0.4;
    strcpy(nScore.grade, getGrade(nScore.total));

    printf("Final Score : %.2f\n", nScore.total);
    printf("Grade       : %s\n", nScore.grade);

    printf("Inserting data\n");
    allStudents[*currentStudent] = nStudent;

    FILE *fout = fopen("dataMahasiswa.txt", "a+");
    fprintf(fout, "%s#%s#%s\n", nStudent.nim, nStudent.name, nStudent.major);
    fclose(fout);

    FILE *foutTugas = fopen("nilaiMahasiswa.txt", "a+");
    fprintf(foutTugas, "%s#%2.f#%2.f#%2.f#%2.f#%s\n", nStudent.nim, nScore.tugas, nScore.uts, nScore.uas, nScore.total, nScore.grade);
    fclose(foutTugas);

    *currentStudent++;

    getchar();

    printf("New students added\nPress any key to continue\n");
    getchar();
}

void showAllStudents(int *current, Student allStudents[])
{
    readData(allStudents, &*current);

    int i = 0;
    system("cls");
    printf("                 List of Student Information                \n");
    printf("---------------------------------------------------------------------\n");
    printf("|No.|             Name             |      Major       |     NIM     |\n");
    printf("---------------------------------------------------------------------\n");
    if (*current == 0)
    {
        printf("              There are no student record\n               Press any key to continue\n");
        getchar();
        return;
    }
    for (i = 0; i < *current + 1; i++)
    {
        printf("|%-3d| %-29s| %-16s | %-11s |\n", i + 1, allStudents[i].name, allStudents[i].major, allStudents[i].nim);
    }
    printf("---------------------------------------------------------------------\n");

    getchar();
}

void showAllScores(int studentCount, Score scores[])
{
    readScore(scores);

    int i = 0;
    system("cls");
    printf("                    List of Student Information                     \n");
    printf("--------------------------------------------------------------------\n");
    printf("|No.|     NIM     |  Task  | Mid Term | Final Term | Total | Grade |\n");
    printf("--------------------------------------------------------------------\n");
    if (studentCount == 0)
    {
        printf("              There are no score record\n               Press any key to continue\n");
        getchar();
        return;
    }
    for (i = 0; i < studentCount + 1; i++)
    {
        printf("|%-3d| %-11s | %-6.2f | %-8.2f | %-10.2f | %-6.2f| %-5s |\n", i + 1, scores[i].nim, scores[i].tugas, scores[i].uts, scores[i].uas, scores[i].total, scores[i].grade);
    }
    printf("--------------------------------------------------------------------\n");

    getchar();
}

void showStudentDetail(int studentCount, Score scores[])
{
    readScore(scores);
    sort(scores, studentCount);

    int i = 0;
    system("cls");
    printf("                 Sorted List of Student Information                 \n");
    printf("--------------------------------------------------------------------\n");
    printf("|No.|     NIM     |  Task  | Mid Term | Final Term | Total | Grade |\n");
    printf("--------------------------------------------------------------------\n");
    if (studentCount == 0)
    {
        printf("              There are no score record\n               Press any key to continue\n");
        getchar();
        return;
    }
    for (i = 0; i < studentCount + 1; i++)
    {
        printf("|%-3d| %-11s | %-6.2f | %-8.2f | %-10.2f | %-6.2f| %-5s |\n", i + 1, scores[i].nim, scores[i].tugas, scores[i].uts, scores[i].uas, scores[i].total, scores[i].grade);
    }
    printf("--------------------------------------------------------------------\n");

    int found = 0;
    char nim[12];
    printf("Enter the NIM you want to search: ");
    scanf("%s", nim);
    fflush(stdin);

    found = search(scores, i, nim);

    if (found != -1)
    {
        printf("\nStudent with NIM %s found in index no.%d\n", nim, found);
        printf("--------------------------------------------------------------------\n");
        printf("|%-3d| %-11s | %-6.2f | %-8.2f | %-10.2f | %-6.2f| %-5s |\n", found, scores[found].nim, scores[found].tugas, scores[found].uts, scores[found].uas, scores[found].total, scores[found].grade);
        printf("--------------------------------------------------------------------\n");
    }
    else
    {
        printf("\nThere's no student with NIM %s", nim);
    }

    getchar();
}

int main()
{
    int i = 0, choose;
    int studentCount = 0, totalStudent = 100;
    Student students[100];
    Score scores[100];

    do
    {
        readData(students, &studentCount);
        system("cls");
        printf("Welcome to simple student database (%d/%d)\n", studentCount + 1, totalStudent);
        printf("1. Input new student\n");
        printf("2. Show all students\n");
        printf("3. Show all scores\n");
        printf("4. Show student detail\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choose);
        getchar();
        if (choose == 0)
            break;

        switch (choose)
        {
        case 2:
            showAllStudents(&studentCount, students);
            break;
        case 1:
            if (studentCount == totalStudent)
            {
                printf("Database is full\nPress any key to continue");
                getchar();
                continue;
            }
            insertStudent(&studentCount, students);
            break;
        case 3:
            showAllScores(studentCount, scores);
            break;
        case 4:
            showStudentDetail(studentCount, scores);
            break;
        default:
            printf("Option invalid!\nPress any key to continue");
            getchar();
            break;
        }
    } while (1);

    return 0;
}
