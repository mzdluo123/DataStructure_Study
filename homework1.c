#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNewNode(int data)
{
    Node *node = (Node* )malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int findK(int k, Node *head)
{
    Node *fast = head;
    Node *slow = head;
    Node *tmp;
    // 快指针先走k个节点
    for (int i = 0; i < k; i++)
    {
        tmp = fast->next;
        if (tmp != NULL)
        {
            fast = tmp;
        }
        else
        {
            return 0;
        }
    }
    while (1)
    {
        slow = slow->next;
        tmp = fast->next;
        if (tmp == NULL)
        {
            // 当快指针走到最后一个节点那么慢指针刚好位于倒数k个节点
            printf("%d \n", slow->data);
            return 1;
        }
        fast = tmp;
        
    }
    return 0;
}



int main(int argc, char const *argv[])
{
    Node *head = createNewNode(1);
    Node *node2 = createNewNode(2);
    Node *node3 = createNewNode(3);
    Node *node4 = createNewNode(4);
    Node *node5 = createNewNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    findK(3, head);
    
    return 0;
}
