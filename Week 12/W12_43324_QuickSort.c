#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *bil, int l, int r)
{
    int pivot = bil[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        if (bil[j] <= pivot)
        {
            i++;

            swap(&bil[i], &bil[j]);
        }
    }

    swap(&bil[i + 1], &bil[r]);

    return (i + 1);
}

void quickSort(int *bil, int l, int r)
{
    if (l < r)
    {
        int pi = partition(bil, l, r);

        quickSort(bil, l, pi - 1);
        quickSort(bil, pi + 1, r);
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

    quickSort(bil, 0, n - 1);

    printf("Hasil quick sort:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bil[i]);
    }

    free(bil);

    return 0;
}