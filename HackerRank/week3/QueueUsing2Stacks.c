#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

int isEmpty(Node *top) { return top == NULL; }

void push(Node **top, int v)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = v;
    n->next = *top;
    *top = n;
}

int pop(Node **top)
{
    Node *t = *top;
    int v = t->val;
    *top = t->next;
    free(t);
    return v;
}

int peek(Node *top) { return top->val; }

void transfer(Node **from, Node **to)
{
    while (!isEmpty(*from))
    {
        push(to, pop(from));
    }
}

int main(void)
{
    int q;
    if (scanf("%d", &q) != 1)
        return 0;

    Node *in = NULL;
    Node *out = NULL;
    while (q--)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int x;
            scanf("%d", &x);
            push(&in, x);
        }
        else if (type == 2)
        {
            if (isEmpty(out))
                transfer(&in, &out);
            if (!isEmpty(out))
                pop(&out);
        }
        else if (type == 3)
        {
            if (isEmpty(out))
                transfer(&in, &out);
            if (!isEmpty(out))
                printf("%d\n", peek(out));
        }
    }
    while (!isEmpty(in))
        pop(&in);
    while (!isEmpty(out))
        pop(&out);
    return 0;
}
