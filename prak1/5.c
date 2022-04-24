#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct stackNode_t
{
    int data;
    struct stackNode_t *next, *prev;
} StackNode;

typedef struct stack_t
{
    StackNode *_top, *_rear;
    unsigned _size;
} Stack;

void init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
    stack->_rear = NULL;
}

bool isEmpty(Stack *stack)
{
    return (stack->_top == NULL && stack->_rear == NULL);
}

void push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode)
    {
        stack->_size++;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (isEmpty(stack))
        {
            stack->_top = newNode;
            stack->_rear = newNode;
        }
        else
        {
            stack->_rear->prev = newNode;
            newNode->next = stack->_rear;
            stack->_rear = newNode;
        }
    }
}

void down(Stack *stack)
{
    stack->_top = stack->_top->prev;
    return;
}

void up(Stack *stack)
{
    stack->_top = stack->_top->next;
    return;
}

int top(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->_top->data;
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++)
    {
        int max, ka, kb;
        scanf("%d %d %d", &max, &ka, &kb);
        int ka_dup = ka;
        int kb_dup = kb;
        Stack a, b, a1, b1;
        init(&a);
        init(&b);
        init(&a1);
        init(&b1);
        int j;
        for (j = 0; j < ka; j++)
        {
            int num;
            scanf("%d", &num);
            push(&a, num);
            push(&a1, num);
        }
        for (j = 0; j < kb; j++)
        {
            int num;
            scanf("%d", &num);
            push(&b, num);
            push(&b1, num);
        }
        int total = 0, count = 0;
        while (ka--)
        {
            if (top(&a) + total > max)
            {
                up(&a);
                break;
            }
            total += top(&a);
            count++;
            if (ka != 0)
            {
                down(&a);
            }
        }
        int count_a = count;
        int result = count;
        while (kb--)
        {
            total += top(&b);
            count++;
            down(&b);
            while (total > max)
            {
                if (count_a > 0)
                {
                    total -= top(&a);
                    up(&a);
                    count--;
                    count_a--;
                }
                else
                {
                    break;
                }
            }
            if (total <= max && result < count)
            {
                result = count;
            }
        }
        printf("%d pitik\n", result);
        int ada = 0;
        if (!result)
        {
            ada = 1;
            printf("GOJOOO-kunn wetengku lesu :(\n");
        }
        else if (result % 2 == 0)
        {
            while (ka_dup--)
            {
                if (top(&a1) % 2 == 0)
                {
                    ada++;
                    if (ada == 1)
                    {
                        printf("NUM =>");
                    }
                    printf("%d ", top(&a1));
                }
                down(&a1);
                if (ada != 0 && ka_dup == 0)
                {
                    printf("\n");
                }
            }
        }
        else
        {
            while (kb_dup--)
            {
                if (top(&b1) % 2 != 0)
                {
                    ada++;
                    if (ada == 1)
                    {
                        printf("NUM =>");
                    }
                    printf("%d ", top(&b1));
                }
                down(&b1);
                if (ada != 0 && kb_dup == 0)
                {
                    printf("\n");
                }
            }
        }
        if (!ada)
        {
            printf("Nihil\n");
        }
    }
}
