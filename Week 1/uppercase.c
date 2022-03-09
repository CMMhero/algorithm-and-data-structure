#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	char kalimat[500];
	printf("Masukkan kata: ");
	gets(kalimat);
	
	int i;
	for(i=0; kalimat[i]!='\0'; i++)
	{
		if(kalimat[i]>='a' && kalimat[i]<='z')
			kalimat[i]-=32;
		printf("%c", kalimat[i]);
	}
//	printf("%s", kalimat);
	getch();
	return 0;
}

