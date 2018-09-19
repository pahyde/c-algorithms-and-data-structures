#include <stdlib.h>
#include <stdio.h>

//queue node defn
struct node {
    int data;
    struct node *next;
};

//queue defn

struct queue {
    struct node *front;
    struct node *rear;
};

void display(struct queue *p) {
    if (p == NULL) return;
    
    struct node *fp = p->front;
    while (fp != NULL) {
       printf("%d ", fp->data);  
       fp = fp->next;
    }
}

struct node *newQueueNode(int data) {
    struct node *p = (struct node*) malloc(sizeof(struct node));
    if (p != NULL) {
        p->data = data;
        p->next = NULL;
    }
    return p;
}

struct queue *newQueue() {
    struct queue *p = (struct queue*) malloc(sizeof(struct queue));
    if (p != NULL) {
        p->front = NULL;
        p->rear  = NULL;
    }
    return p;
}

void enqueue(struct queue *p, int data) {
    struct node *rp = newQueueNode(data);
    if (p->front == NULL) {
        p->front = rp;
    } else {
        p->rear->next = rp;
    }
    p->rear = rp;
}

int dequeue(struct queue *p) {
    if (p == NULL) {
        printf("error: nothing to dequeue\n");
        return -1;
    }
    int front = p->front->data;
    p->front = p->front->next;
    return front;
}

int main() {
    printf("\nQueue (llist implementation) ---------------------------\n");
    struct queue *p = newQueue();
    
    printf("\nenqueue integers 0-9 to the queue.\n");
    for (int i = 0; i < 10; i++) enqueue(p, i);
    printf("queue: ");
    display(p);

    printf("\n\ndequeue 5 values from the queue.\n");
    printf("dequeued values: ");
    for (int i = 0; i < 5; i++) printf("%d ", dequeue(p));
    printf("\nqueue: ");
    display(p);
    printf("\n\n");
}




