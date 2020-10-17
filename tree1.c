#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *right, *left;
} Node;

typedef struct Tree
{
    struct Node *head;

} Tree;

Node *createNode(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Insert(Tree *tree, Node *node)
{
    if (!tree->head)
    {
        tree->head = node;
        return;
    }
    Node *leaf = tree->head;
    while (1)
    {
        if (node->data > leaf->data)
        {
            if (leaf->right)
            {
                leaf = leaf->right;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (leaf->left)
            {
                leaf = leaf->left;
            }
            else
            {

                break;
            }
        }
    }
    if (node->data > leaf->data)
    {
        leaf->right = node;
    }
    else
    {
        leaf->left = node;
    }
}

Node *Search(Tree *tree, int data)
{

    if (!tree->head)
    {
        return 0;
    }
    Node *leaf = tree->head;
    while (1)
    {
        if (!leaf)
        {
            return 0;
        }

        if (data == leaf->data)
        {
            return leaf;
        }

        if (data > leaf->data)
        {
            leaf = leaf->right;
        }
        else
        {
            leaf = leaf->left;
        }
    }
}

int Delete(Tree *tree, int a)
{
   
    Node *p = tree->head;
    if (Search(tree, a))
    { 
        Node *q = NULL; // q指向要删除的节点
        if (a < p->data)
        {
            q = p->left;
        }
        else
        {
            q = p->right;
        }

        if (q->left == NULL && q->right == NULL)
        { //叶子节点，直接删除
            if (a < p->data)
                p->left = NULL;
            else
                p->right = NULL;
        }
        else if ((q->left == NULL && q->right != NULL) || (q->left != NULL && q->right == NULL))
        {
            // 只有左子树或者只有右子树
            Node *r = (q->left == NULL ? q->right : q->left); // 指向q不为空的子树
            if (a < p->data)
                p->left = r;
            else
                p->right = r;
        }
        else
        { // 既有左子树又有右子树
            // 这里选择左子树最大的节点作为父节点
            Node *r = q->left;
            // 判断r的右子树是否为空
            if (r->right == NULL)
            { // 右子树为空
                p->left = r;
                r->right = q->right;
            }
            else
            { // 右子树不为空
                Node *r1 = r;
                Node *r1_father = r;
                // 寻找最右子树
                while (r1->right != NULL)
                {
                    r1_father = r1;
                    r1 = r1->right;
                }
               
                r1_father->right = r1->left;
                r1->left = r;
                r1->right = q->right;
                p->left = r1;
            }
        }
        free(q);
        q = NULL;
        return 0;
    }
    return 1;
}

void printNode(Node *node)
{
    if (node != NULL)
    {

        printNode(node->left);
        printf("%d \n", node->data);
        printNode(node->right);
    }
}

void printTree(Tree *tree)
{
    if (tree->head == NULL)
    {
        return;
    }
    printNode(tree->head);
}

int main(int argc, char const *argv[])
{
    Tree *tree = malloc(sizeof(Tree));
    tree->head = NULL;

    Insert(tree, createNode(3));
    Insert(tree, createNode(1));
    Insert(tree, createNode(4));
    Insert(tree, createNode(2));
    Insert(tree, createNode(5));
    Delete(tree,1);
    
    printTree(tree);
    return 0;
}
