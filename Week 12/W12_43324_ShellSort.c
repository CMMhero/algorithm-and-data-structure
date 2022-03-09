#include <stdio.h>
#include <stdlib.h>

void shellSort(int *bil, int n)
{
    int i, j, gap;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            int temp = bil[i];

            for (j = i; j >= gap && bil[j - gap] > temp; j -= gap)
            {
                bil[j] = bil[j - gap];
            }

            bil[j] = temp;
        }
    }
}

int main()
{
    int i, n, *bil;

    printf("Banyak bilangan: ");
    scanf("%d", &n);
    fflush(stdin);
    bil = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        printf("Input bilangan ke-%d: ", i + 1);
        scanf("%d", &bil[i]);
        fflush(stdin);
    }

    shellSort(bil, n);

    printf("Hasil shell sort:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bil[i]);
    }

    free(bil);

    return 0;
}