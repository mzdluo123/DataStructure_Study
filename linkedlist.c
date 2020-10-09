#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0


typedef struct node {
    int data;
    struct node *next;
} Node;
typedef struct LinkedList {
    struct node *head;
}LinkedList;


Node *createNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

unsigned char insert(LinkedList *list, int index, Node *data) {

    if (list == NULL || data == NULL) {
        return ERROR;
    }
    Node *tmp = list->head;
    if (index == 0){
        data->next = list->head;
        list->head = data;
        return OK;
    }
    for (int i = 0; i < index; ++i) {
        tmp = tmp->next;
        if (tmp == NULL) {
            return ERROR;
        }
    }
    Node *next = tmp->next;
    tmp->next = data;
    data->next = next;


    return OK;
}
unsigned char delete(LinkedList *list,int index){
    if (list == NULL || list->head == NULL){
        return ERROR;
    }
    Node * tmp = list->head;
    if (index == 0){
        Node *del = list->head;
        list->head = list->head->next;
        free(del);
        return OK;
    }
    for (int i = 0; i < index -1 ; ++i) {
        tmp = tmp->next;
        if (tmp == NULL){
            return ERROR;
        }
    }
    Node *del = tmp->next;
    tmp->next = del->next;
    free(del);

    return OK;

}

void printLinkedList(LinkedList *list) {

    Node *tmp = list->head;
    while (1) {
        if (tmp == NULL) {
            return;
        }
        printf("%d \n", tmp->data);
        tmp = tmp->next;
    }
}

Node* get(LinkedList *list, int index){
    if (list == NULL || list->head == NULL){
        return ERROR;
    }

    Node *tmp = list->head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->next;
        if (tmp == NULL){
            return NULL;
        }
    }
    return tmp;
}

void reversePerNode(LinkedList *list,Node *node){
    if (node == NULL){
        return;
    }
    if (node->next == NULL){
        list->head = node;
        return;
    }
    reversePerNode(list,node->next);
    node->next->next = node;
    node->next = NULL;
}

void reverse(LinkedList *list){
    if (list==NULL){
        return;
    }
    reversePerNode(list,list->head);

}

int main(int argc, char const *argv[]) {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->head = createNode(0);
    printf("insert\n");
    insert(linkedList, 0, createNode(1));
    insert(linkedList, 0, createNode(2));
    insert(linkedList, 1, createNode(3));
    printLinkedList(linkedList);
    printf("delete\n");
    delete(linkedList , 3);
    printLinkedList(linkedList);
    printf("find at index 2 is %d\n",get(linkedList,2)->data);
    printf("reverse\n");
    reverse(linkedList);
    printLinkedList(linkedList);
    return 0;
}
