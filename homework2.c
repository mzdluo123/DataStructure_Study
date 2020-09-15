#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

Stack *newStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Node *newNode(char data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void pushStack(Stack *stack, Node *node)
{
    node->next = stack->top;
    stack->top = node;
}

Node *popStack(Stack *stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }
    Node *node = stack->top;
    stack->top = node->next;
    return node;
}

unsigned char check(char *str, unsigned int length)
{
    Stack *stack = newStack();
    for (size_t i = 0; i < length; i++)
    {
        char ch = *(str + i);
        if (ch == '(')
        {
            Node *node = newNode(ch);
            pushStack(stack,node);
            continue;
        }
        if (ch == ')')
        {
           Node *node = popStack(stack);
           if (node == NULL)
           {
               return 0;
           }
           
        }
    }
    if (stack->top == NULL)
    {
       return 1;
    }
    return 0;
    
}

int main(int argc, char const *argv[])
{
    /* code */
    printf("%d\n", check("(())",4));
    printf("%d\n", check("(()",3));
    printf("%d\n", check("(()))",5));
    return 0;
}
