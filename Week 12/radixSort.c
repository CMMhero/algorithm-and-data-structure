#include <stdio.h>

int getMax(int *bil, int n)
{
    int mx = bil[0];
    for (int i = 1; i < n; i++)
        if (bil[i] > mx)
            mx = bil[i];
    return mx;
}

void bucketSort(int *bil, int n, int exp)
{
    int output[n];
    int i, bucket[10] = {0};

    for (i = 0; i < n; i++)
        bucket[(bil[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        bucket[i] += bucket[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[bucket[(bil[i] / exp) % 10] - 1] = bil[i];
        bucket[(bil[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        bil[i] = output[i];
}

void radixsort(int *bil, int n)
{
    int m = getMax(bil, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        bucketSort(bil, n, exp);
}

int main()
{
    int *bil, i, n;
    printf("Masukkan jumlah data yang akan di sort: ");
    scanf("%d", &n);
    fflush(stdin);

    for (i = 0; i < n; i++)
    {
        printf("Input bilangan ke-%d: ", i + 1);
        scanf("%d", &bil[i]);
        fflush(stdin);
    }

    radixsort(bil, n);

    printf("Hasil radix sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", bil[i]);
    }
    return 0;
}