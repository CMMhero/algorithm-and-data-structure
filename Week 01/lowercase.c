#include <stdio.h>
int main()
{
	char kalimat[1000];
	printf("\n");
	printf("Masukkan kata: ");
	scanf("%[^\n]", &kalimat);

	int i;
	for (i = 0; kalimat[i] != '\0'; i++)
	{
		if (kalimat[i] >= 'A' && kalimat[i] <= 'Z')
			kalimat[i] += 32;
	}
	printf("%s", kalimat);

	return 0;
}
