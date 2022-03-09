#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void convert(int pilihan, char kalimat[500])
{
	int i;
	
	switch(pilihan)
	{
		case 1:
			for(i=0; kalimat[i]!='\0'; i++)
			{
				if(kalimat[i]>='a' && kalimat[i]<='z')
					kalimat[i]-=32;
			}
			break;
		case 2:
			for(i=0; kalimat[i]!='\0'; i++)
			{
				if(kalimat[i]>='A' && kalimat[i]<='Z')
					kalimat[i]+=32;
			}
			break;
		case 3:
			for(i=0; kalimat[i]!='\0'; i++)
			{
				if(kalimat[i]>='a' && kalimat[i]<='z')
					kalimat[i]-=32;
				else if(kalimat[i]>='A' && kalimat[i]<='Z')
					kalimat[i]+=32;
			}
			break;
	}
}

int main()
{
	char kalimat[500];
	int pilihan=1;
	
	do
	{
		system("cls");
		printf("Program Pengubah Karakter\n");
		printf("1. Uppercase\n");
		printf("2. Lowercase\n");
		printf("3. Switching\n");
		printf("4. Keluar\n");
		printf("Pilihan : ");
		scanf("%d", &pilihan);
		fflush(stdin);
		
		if(pilihan>=1 && pilihan<4)
		{
			printf("Masukkan kata: ");
			gets(kalimat);
			convert(pilihan,kalimat);
			printf("%s",kalimat);
			getch();
		}
	}
	while(pilihan >=1 && pilihan<4);
	
	return 0;
}

