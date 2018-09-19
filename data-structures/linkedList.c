#include <stdlib.h>
#include <stdio.h>

//linked list node defn
struct node {
    int data;
    struct node *next;
};

//print list data
void display(struct node *head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node *p = head;
    while (p->next != NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
} 

//create initial list node
struct node *newListNode(int data) {
    struct node *p = (struct node*) malloc(sizeof(struct node));
    if (p != NULL) {
        p->data = data;
        p->next = NULL;
    }
    return p;
}

//add to the front of the list
struct node *addFront(struct node* head, int data) {
    struct node *p = newListNode(data);
    if (p == NULL) {
        printf("error adding node\n");
        return head;
    }
    p->next = head;
    return p;
}

//add to the back of the list
struct node *addBack(struct node* head, int data) {
    if (head == NULL) {
        head = newListNode(data);
        return head;
    }
    struct node *p = head;
    while (p->next != NULL) p = p->next;
    p->next = newListNode(data);
    return head;
}

//find address of element in list
struct node* find(struct node *head, int data) {
    for (struct node *p = head; p != NULL; p = p->next) {
        if (p->data == data) {
            return p;
        }
    }
    return NULL;
}

//find index of element in list 
int findIndex(struct node *head, int data) {
    return (int) (find(head, data) - head);
}

int main() {
    //linked list
    printf("\nLinked List ---------------------------\n");
    struct node *p = NULL;
    printf("\nadd integers 0-9 to front of empty list.\n");
    for (int i = 0; i < 10; i++) p = addFront(p, i);
    printf("list_0: ");
    display(p);

    struct node *p1 = NULL;
    printf("\nadd integers 0-9 to back of empty list.\n");
    for (int i = 0; i < 10; i++) p1 = addBack(p1, i);
    printf("list_1: ");
    display(p1);
    printf("\n");

    printf("address of head node list_1: %p\n", p1);
    printf("address of node with data value 7: %p\n", find(p1, 7));
    printf("index of node with data value 7: %d\n\n", findIndex(p1, 7));
    return 0;
}

/*
Program output:
Linked List ---------------------------

add integers 0-9 to front of empty list.
list_0: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

add integers 0-9 to back of empty list.
list_1: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

address of head node list_1: 0x7fb40ed000a0
address of node with data value 7: 0x7fb40ed00110
index of node with data value 7: 7

*/