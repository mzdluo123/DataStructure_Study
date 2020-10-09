#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct list {
    int length;
    int size;
    int *data;
} List;

List *newList() {
    List *list = malloc(sizeof(List));
    list->data = NULL;
    list->size = 1;
    list->length = 0;
    return list;
}

unsigned char extendList(List *list, int size) {
    int *newList = realloc(list->data, sizeof(int) * (list->size + size));
    if (newList != NULL) {
        list->data = newList;
        list->size += size;
        return OK;
    }
    return ERROR;
}

unsigned char insertList(List *list, int index, int data) {
    if (list == NULL) {
        return ERROR;
    }

    if (index + 1 >= list->size) {
        extendList(list, index + 1);
    }

    for (int i = list->length; i >= index; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = data;
    list->length++;
    return OK;
}

unsigned int deleteList(List *list, int index) {
    if (list == NULL) {
        return ERROR;
    }
    if (index + 1 > list->length) {
        return ERROR;
    }
    for (int i = index; i < list->length; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return OK;
}

int findData(List *list, int data) {
    if (list == NULL) {
        return -1;
    }
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == data){
            return  i;
        }
    }
    return -1;
}

void printList(List *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d \n", list->data[i]);
    }
}

int main(int argc, char const *argv[]) {
    List *list = newList();
    printf("insert\n");
    insertList(list, 0, 2);
    insertList(list, 0, 3);
    insertList(list, 1, 4);
    printList(list);
    printf("delete 1\n");
    deleteList(list, 1);
    printList(list);

    printf("find 2: %d \n",findData(list,2));
    return 0;
}
