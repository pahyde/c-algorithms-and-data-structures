#include <stdlib.h>
#include <stdio.h>

//stack node defn
struct node {
    int data;
    struct node *next;
};

void display(struct node *p) {
    if (p == NULL) return;

    display(p->next);
    printf("%d ", p->data);
}

struct node *newStackNode(int data) {
    struct node *p = (struct node*) malloc(sizeof(struct node));
    if (p != NULL) {
        p->data = data;
        p->next = NULL;
    }
    return p;
}

void push(struct node **p, int data) {
    struct node *sp = newStackNode(data);
    sp->next = *p;
    *p = sp;
}

int pop(struct node **p) {
    if (*p == NULL) {
        printf("error: nothing to pop.\n");
        return -1;
    }
    int popped = (*p)->data;
    *p = (*p)->next;
    return popped;
}

int main() {
    printf("\nStack (llist implementation) ---------------------------\n");
    struct node *p = NULL;
    
    printf("\npush integers 0-9 to the stack.\n");
    for (int i = 0; i < 10; i++) push(&p, i);
    printf("stack: ");
    display(p);

    printf("\n\npop 5 values from the stack.\n");
    printf("popped values: ");
    for (int i = 0; i < 5; i++) printf("%d ", pop(&p));
    printf("\nstack: ");
    display(p);
    printf("\n\n");
}




