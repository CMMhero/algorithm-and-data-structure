#include <stdio.h>
#include <math.h>

int jumpSearch(int *arr, int size, int key)
{
    int start, jump, i;

    start = 0;
    jump = sqrt(size);
    printf("\nAkar kuadrat terdekat dari %d = %d\n", size, jump);

    while (arr[jump] <= key && jump < size)
    {
        start = jump;
        jump += sqrt(size);
        if (jump > size - 1)
            jump = size;
    }

    for (i = start; i < jump; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

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

void printArray(int *arr, int size)
{
    int i = 0;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int numbers[] = {2, 4, 3, 123, 23, 56, 7895, 456, 342, 67, 2345};
    int size = sizeof(numbers) / 4;
    int searchKey;
    int found = 0;

    printf("Array before sorting: ");
    printArray(numbers, size);
    shellSort(numbers, size);
    printf("Array after sorting: ");
    printArray(numbers, size);

    printf("\nMasukkan angka yang ingin dicari: ");
    scanf("%d", &searchKey);

    found = jumpSearch(numbers, size, searchKey);

    if (found != -1)
    {
        printf("Angka %d ditemukan pada index %d", searchKey, found);
    }
    else
    {
        printf("Angka %d tidak ditemukan pada array numbers", searchKey);
    }

    return 0;
}