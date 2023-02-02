#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    FILE *ptr;
    ptr = fopen("numbers.txt", "r");
    if (ptr == NULL)
    {
        printf("NO SUCH FILE\n");
        exit(0);
    }
    int tempNumber;
    int numberCount = 0;
    while (fscanf(ptr, "%d", &tempNumber) != EOF)
    {
        numberCount++;
    }
    printf("Number Count: %d\n", numberCount);
    fseek(ptr, SEEK_SET, 0);

    int *arr = (int *)malloc(numberCount * sizeof(int));
    int arr_size = numberCount;
    numberCount = 0;
    while (fscanf(ptr, "%d", &tempNumber) != EOF)
    {
        arr[numberCount] = tempNumber;
        numberCount++;
    }
    fclose(ptr);

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}