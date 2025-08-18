#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        qsort(arr, n, sizeof(int), compare);
        int mid = (n - 1) / 2;
        swap(&arr[mid], &arr[n - 1]);
        int start = mid + 1, end = n - 2;
        while (start <= end)
        {
            swap(&arr[start], &arr[end]);
            start++;
            end--;
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
