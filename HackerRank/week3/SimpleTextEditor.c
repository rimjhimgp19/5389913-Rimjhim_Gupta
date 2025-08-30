#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_dup(const char *s)
{
    size_t n = strlen(s);
    char *r = malloc(n + 1);
    if (!r)
        exit(EXIT_FAILURE);
    memcpy(r, s, n + 1);
    return r;
}

int main()
{
    int Q;
    if (scanf("%d", &Q) != 1)
        return 0;
    char **stack = malloc((Q + 5) * sizeof(char *));
    int top = -1;
    char *s = str_dup("");
    size_t len = 0;

    for (int i = 0; i < Q; ++i)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            char W[100000 + 5];
            scanf("%s", W);
            stack[++top] = str_dup(s);
            size_t add = strlen(W);
            s = realloc(s, len + add + 1);
            if (!s)
                exit(EXIT_FAILURE);
            memcpy(s + len, W, add + 1);
            len += add;
        }
        else if (type == 2)
        {
            int k;
            scanf("%d", &k);
            stack[++top] = str_dup(s);

            if ((size_t)k <= len)
            {
                len -= k;
                s[len] = '\0';
                s = realloc(s, len + 1);
                if (!s)
                    exit(EXIT_FAILURE);
            }
            else
            {
                len = 0;
                free(s);
                s = str_dup("");
            }
        }
        else if (type == 3)
        {
            int k;
            scanf("%d", &k);
            if (k >= 1 && (size_t)k <= len)
            {
                putchar(s[k - 1]);
                putchar('\n');
            }
            else
            {
            }
        }
        else if (type == 4)
        {
            if (top >= 0)
            {
                free(s);
                s = stack[top--];
                len = strlen(s);
            }
        }
    }
    free(s);
    for (int i = 0; i <= top; ++i)
        free(stack[i]);
    free(stack);

    return 0;
}
