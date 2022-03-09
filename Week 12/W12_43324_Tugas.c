#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *bil, int n)
{
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int i, j;

    for (i = 1; i < n; i++)
    {
        for (j = n; j >= 1; j--)
        {
            if (bil[j] < bil[j - 1])
                swap(&bil[j], &bil[j - 1]);
        }
    }

    printf("\nHasil bubble sort: (Descending)\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", bil[i]);
    }

    getchar();
}

void selectionSort(int *bil, int n)
{
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = i;

        for (j = i + 1; j < n; j++)
        {
            if (bil[j] < bil[temp])
            {
                temp = j;
            }
        }

        if (temp != i)
        {
            swap(&bil[temp], &bil[i]);
        }
    }

    printf("\nHasil selection sort: (Descending)\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", bil[i]);
    }

    getchar();
}

void insertionSort(int *bil, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = bil[i];

        for (j = i - 1; j >= 0 && bil[j] > temp; j--)
        {
            bil[j + 1] = bil[j];
        }

        bil[j + 1] = temp;
    }

    printf("\nHasil insertion sort: (Descending)\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", bil[i]);
    }

    getchar();
}

void radixSort(int *bil, int n)
{
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

    void sort(int *bil, int n)
    {
        int maks = bil[0];
        for (int i = 1; i < n; i++)
            if (bil[i] > maks)
                maks = bil[i];

        for (int exp = 1; maks / exp > 0; exp *= 10)
            bucketSort(bil, n, exp);
    }

    int i;
    sort(bil, n);

    printf("\nHasil radix sort: (Descending)\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", bil[i]);
    }
    getchar();
}

void quickSort(int *bil, int n)
{
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

    void sort(int *bil, int l, int r)
    {
        if (l < r)
        {
            int pi = partition(bil, l, r);

            sort(bil, l, pi - 1);
            sort(bil, pi + 1, r);
        }
    }

    int i;
    printf("\nHasil quick sort: (Descending)\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", bil[i]);
    }

    getchar();
}

void mergeSort(int *bil, int n)
{
    void merge(int *bil, int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1];
        int R[n2];
        for (i = 0; i < n1; i++)
        {
            L[i] = bil[l + i];
        }

        for (j = 0; j < n2; j++)
        {
            R[j] = bil[m + 1 + j];
        }

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                bil[k] = L[i];
                i++;
            }
            else
            {
                bil[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            bil[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            bil[k] = R[j];
            j++;
            k++;
        }
    }

    void sort(int *bil, int l, int r)
    {
        if (l < r)
        {
            int m = (l + r) / 2;

            sort(bil, l, m);
            sort(bil, m + 1, r);

            merge(bil, l, m, r);
        }
    }

    int i;
    sort(bil, 0, n - 1);

    printf("\nHasil merge sort: (Descending)\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", bil[i]);
    }

    getchar();
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

    printf("\nHasil shell sort: (Descending)\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", bil[i]);
    }

    getchar();
}

void heapSort(int *bil, int n)
{
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int heapify(int *bil, int n, int i)
    {
        int maks = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && bil[l] > bil[maks])
        {
            maks = l;
        }

        if (r < n && bil[r] > bil[maks])
        {
            maks = r;
        }

        if (maks != i)
        {
            swap(&bil[i], &bil[maks]);

            heapify(bil, n, maks);
        }
    }

    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(bil, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        swap(&bil[0], &bil[i]);
        heapify(bil, i, 0);
    }

    printf("\nHasil heap sort: (Descending)\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", bil[i]);
    }

    getchar();
}

int main()
{
    int pilihan;
    int i, n, *bil;

    printf("  PROGRAM SORTING  \n");
    printf("===================\n");
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

    do
    {
        system("cls");
        printf("  Menu Sorting  \n");
        printf("================\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Radix Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Merge Sort\n");
        printf("7. Shell Sort\n");
        printf("8. Heap Sort\n");
        printf("0. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        if (pilihan == 0)
            break;

        switch (pilihan)
        {
        case 1:
            bubbleSort(bil, n);
            break;
        case 2:
            selectionSort(bil, n);
            break;
        case 3:
            insertionSort(bil, n);
            break;
        case 4:
            radixSort(bil, n);
            break;
        case 5:
            quickSort(bil, n);
            break;
        case 6:
            mergeSort(bil, n);
            break;
        case 7:
            shellSort(bil, n);
            break;
        case 8:
            heapSort(bil, n);
            break;
        default:
        {
            printf("\nInput salah!");
            getchar();
            break;
        }
        }
    } while (1);

    return 0;
}