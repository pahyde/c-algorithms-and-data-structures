#include <stdlib.h>
#include <stdio.h>

//binary tree node defn
struct node {
    int data;
    struct node *left;
    struct node *right;
};

//print tree elements sorted ascending
void displaySortedTreeElements(struct node *tnode) {
    if (tnode == NULL) return;
    displaySortedTreeElements(tnode->left);
    printf("%d ", tnode->data);
    displaySortedTreeElements(tnode->right);
} 

//create initial tree node
struct node *newTreeNode(int data) {
    struct node *p = (struct node*) malloc(sizeof(struct node));
    if (p != NULL) {
        p->data  = data;
        p->left  = NULL;
        p->right = NULL;
    }
    return p;
}

//add new tree node 
struct node *addNode(struct node *tnode, int data) {
    if (tnode == NULL) return newTreeNode(data);
    
    if (data < tnode->data) {
        tnode->left = addNode(tnode->left, data);
    } else if (data > tnode->data) {
        tnode->right = addNode(tnode->right, data);
    } 
    return tnode;
}

int delNodes(struct node *tnode) {
    if (tnode == NULL) return 0;
    
    int count = 1 + delNodes(tnode->left) + delNodes(tnode->right);
    free(tnode);
    return count;
}

int main() {
    printf("Binary Search Tree ---------------------\n\n");
    printf("add integers 2,4,0,7,5,6,3,9,8,1 to tree.\n");
    struct node *p = NULL;
    int nums[10] = {2,4,0,7,5,6,3,9,8,1};
    for (int i = 0; i < 10; i++) p = addNode(p, *(nums + i));
    printf("tree values sorted: ");
    displaySortedTreeElements(p);

    printf("\n\ndelete and free all tree nodes from memory.\n");
    printf("tree nodes deleted: %d\n", delNodes(p));
    p = NULL;
    printf("tree values after deletion: ");
    displaySortedTreeElements(p);
    printf("\n\n");
    return 0;
}
