#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void perkalian(int m1[3][3],int m2[3][3])
{
	int i,j,k,hasil=0;
	int m3[3][3];

	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			for(k=0; k<3; k++)
			{
				hasil += m1[i][k]*m2[k][j];
			}
			m3[i][j]=hasil;
			hasil=0;
		}
	}
	
	printf("\nHasil dari perkalian:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ",m3[i][j]);
		}
		printf("\n");
	}
	getch();
}

void penjumlahan(int m1[3][3],int m2[3][3])
{
	int i,j,hasil=0;
	int m4[3][3];
	
	printf("\nHasil dari penjumlahan:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			hasil += m1[i][j]+m2[i][j];
			m4[i][j]=hasil;
			printf("%d ",m4[i][j]);
			hasil=0;
		}
		printf("\n");
	}
	getch();
}

void transpose(int m1[3][3],int m2[3][3])
{
	int i,j,hasil=0;
	int m5[3][3],m6[3][3];
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			m5[j][i]=m1[i][j];
		}
	}
	
	printf("\nHasil Transpose Matrix Pertama:\n");
		for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ",m5[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			m6[j][i]=m2[i][j];
		}
	}
	
	printf("\nHasil Transpose Matrix Kedua:\n");
		for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ",m6[i][j]);
		}
		printf("\n");
	}
	
	getch();
}

int main()
{
	int m1[3][3],m2[3][3];
	int i,j,pilihan;
	
	printf("Masukkan Matrix Pertama (3 x 3)\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	printf("Masukkan Matrix Kedua (3 x 3)\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}
	
	do
	{
		system("cls");
		printf("1. Perkalian Dua Buah Matrix\n");
		printf("2. Penjumlahan Dua Buah Matrix\n");
		printf("3. Transpose Dua Buah Matrix\n");
		printf("4. Keluar\n");
		printf("Pilihan : ");
		scanf("%d", &pilihan);
		
		if(pilihan==1)
			perkalian(m1,m2);
		else if(pilihan==2)
			penjumlahan(m1,m2);
		else if(pilihan==3)
			transpose(m1,m2);
	}
	while(pilihan >=1 && pilihan<4);
	
	return 0;
}
