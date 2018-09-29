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

//quick sort
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int* nums, int length) {
    if (length < 2) {
      return;
    }
    int pivot = *nums;
    int *i = nums + 1;
    int *j = nums + length - 1;
    while (i <= j) {
        while (i <= j && *i <= pivot) i++;
        while (i <= j && *j > pivot)  j--;
        if (i < j) {
            swap(i, j);
        } 
    }
    swap(nums, j);
    quickSort(nums, i - nums);
    quickSort(i, length - (i - nums));
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
    //linear sort O(n)
    int data[10] = {0,3,4,2,8,5,6,9,7,1};
    printf("\ninsertion sort\n");
    printf("data unsorted: ");
    printArr(data, 10);
    insertionSort(data, 10);
    printf("sorted:        ");
    printArr(data, 10);

    //merge sort O(nlogn)
    int data1[10] = {0,3,4,2,8,5,6,9,7,1};
    printf("\nmerge sort\n");
    printf("data unsorted: ");
    printArr(data1, 10);
    mergeSort(data1, 10);
    printf("sorted:        ");
    printArr(data1, 10);

    //Quick sort O(nlogn)
    int data2[10] = {0,3,4,2,8,5,6,9,7,1};
    printf("\nquick sort\n");
    printf("data unsorted: ");
    printArr(data2, 10);
    quickSort(data2, 10);
    printf("sorted:        ");
    printArr(data2, 10);
    printf("\n");
    return 0;
}

/*
Program output:

insertion sort
data unsorted: 0, 3, 4, 2, 8, 5, 6, 9, 7, 1
sorted:        0, 1, 2, 3, 4, 5, 6, 7, 8, 9

merge sort
data unsorted: 0, 3, 4, 2, 8, 5, 6, 9, 7, 1
sorted:        0, 1, 2, 3, 4, 5, 6, 7, 8, 9


quick sort
data unsorted: 0, 3, 4, 2, 8, 5, 6, 9, 7, 1
sorted:        0, 1, 2, 3, 4, 5, 6, 7, 8, 9

*/