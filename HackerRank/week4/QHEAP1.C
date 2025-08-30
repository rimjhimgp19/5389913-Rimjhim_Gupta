#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int Q;
    scanf("%d", &Q);

    int arr[MAXN];
    int size = 0;

    while (Q--)
    {
        int type, x;
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d", &x);
            arr[size++] = x;
        }
        else if (type == 2)
        {
            scanf("%d", &x);
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == x)
                {
                    arr[i] = arr[size - 1];
                    size--;
                    break;
                }
            }
        }
        else if (type == 3)
        {
            int min = arr[0];
            for (int i = 1; i < size; i++)
            {
                if (arr[i] < min)
                    min = arr[i];
            }
            printf("%d\n", min);
        }
    }
    return 0;
}
