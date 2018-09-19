#include <stdlib.h>
#include <stdio.h>

//hash table implemetation using array of llists

//hash table record defn
struct record {
    int key;
    int value;
    struct record *next;
};

int hash(int key) {
    return key % 97;
}

struct record **newHashTable() {
    struct record **t = (struct record**) malloc(sizeof(struct record*) * 97);
    for (int i = 0; i < 97; i++) *(t + i) = NULL;
    return t;
}

struct record *newRecord(int key, int value) {
    struct record *p = (struct record*) malloc(sizeof(struct record));
    if (p != NULL) {
        p->key = key;
        p->value = value;
    }
    return p;
}

void put(struct record **t, int key, int value) {
    struct record *p = newRecord(key, value);
    int h = hash(key);
    struct record *i = *(t + h);
    if (i == NULL) {
       *(t + h) = p;
       return;
    }
    while (i != NULL) {
        if (i->key == key) {
            i->value = value;
            return;
        }
        i = i->next;
    }
    *i = *p;
}



struct record *get(struct record **t, int key) {
    struct record *i = *(t + hash(key));
    if (i == NULL) {
        return NULL;
    }
    while (i->key != key) {
        i = i->next;
    }
    return i;
}

/*
void delete() {

}
*/

//print array fn
void printArr(int* nums, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", *(nums + i));
        if (i != length - 1) {
           printf(",");
        } else {
           printf("\n");
        }
    }
}

int main() {
    //hash table
    printf("Hash Table--------------------------\n\n");
    printf("simple int k,v pair hash table implementated with array of llists \n");
    printf("Here the hash table is used to count the ");
    printf("frequency\nof nums in an int array\n\n");
    struct record **t = newHashTable();
    int data[36] = {0,3,7,6,1,2,1,2,3,4,5,5,4,9,7,1,3,2,4,3,6,5,4,7,6,9,0,0,4,2,8,5,6,9,7,1};
    printf("update count for integers ");
    printArr(data, 36);
    printf("\n");
    for (int i = 0; i < 36; i++) {
        struct record *c = get(t, *(data + i));
        int num = *(data + i);
        int count = c == NULL ? 1 : c->value + 1;
        put(t, num, count);
    }
    printf("frequency of ints 0-9 after update: \n");
    for (int i = 0; i < 10; i++) {
        struct record *c = get(t, i);
        
        int num = i;
        int count = c == NULL ? 0 : c->value;
        printf("num: %d, count: %d\n", num, count);
    }
    printf("\n");
}


/*
Program output:
Hash Table--------------------------

simple int k,v pair hash table implementated with array of llists 
Here the hash table is used to count the frequency
of nums in an int array

update count for integers 0,3,7,6,1,2,1,2,3,4,5,5,4,9,7,1,3,2,4,3,6,5,4,7,6,9,0,0,4,2,8,5,6,9,7,1

frequency of ints 0-9 after update: 
num: 0, count: 3
num: 1, count: 4
num: 2, count: 4
num: 3, count: 4
num: 4, count: 5
num: 5, count: 4
num: 6, count: 4
num: 7, count: 4
num: 8, count: 1
num: 9, count: 3

*/

