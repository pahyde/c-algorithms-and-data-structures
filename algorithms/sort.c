#include <stdlib.h>
#include <stdio.h>

//insertion sort
void insertionSort(int *nums, int length) {
    for (int i = 1; i < length; i++) {
        int p = *(nums + i);
        int j = i - 1;
        while (j >= 0 && *(nums + j) > p) {
            *(nums + j + 1) = *(nums + j);
            j -= 1;
        }
        *(nums + j + 1) = p;
    }
}

//merge sort
void merge(int *nums, int *l, int n1, int *r, int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        *(nums + k++) = *(l+i) < *(r+j) ? *(l + i++) : *(r + j++);
    }
    while (i < n1) *(nums + k++) = *(l + i++);
    while (j < n2) *(nums + k++) = *(r + j++);
}

void mergeSort(int *nums, int length) {
    if (length > 1) {
        int m = length / 2, n1 = m, n2 = length - m;
        //malloc for l, r side of array
        int *l = (int*) malloc(sizeof(int) * n1);
        int *r = (int*) malloc(sizeof(int) * n2);
        //fill l, r
        for (int i = 0; i < m; i++) *(l + i) = *(nums + i);
        for (int i = m; i < length; i++) *(r + i - m) = *(nums + i);
        //mergeSort l, r
        mergeSort(l, n1);
        mergeSort(r, n2);
        //merge nums, l, r
        merge(nums, l, n1, r, n2);
    }
}

//print array fn
void printArr(int* nums, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", *(nums + i));
        if (i != length - 1) {
           printf(", ");
        } else {
           printf("\n");
        }
    }
}

int main() {
    //linear search O(n)
    int data[10] = {0,3,4,2,8,5,6,9,7,1};
    printf("\ninsertion sort\n");
    printf("data unsorted: ");
    printArr(data, 10);
    insertionSort(data, 10);
    printf("sorted:        ");
    printArr(data, 10);

    //merge search O(logn)
    int data1[10] = {0,3,4,2,8,5,6,9,7,1};
    printf("\nmerge sort\n");
    printf("data unsorted: ");
    printArr(data1, 10);
    mergeSort(data1, 10);
    printf("sorted:        ");
    printArr(data1, 10);
    printf("\n");
    return 0;
}