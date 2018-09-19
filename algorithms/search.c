#include <stdlib.h>
#include <stdio.h>

//linear search
//useful when searching unsorted data
int linearSearch(int *nums, int length, int target) {
    for (int i = 0; i < length; i++) {
        if (*(nums + i) == target) {
            return i;
        }
    }
    return -1;
}

//binary search
//only applicable when searching sorted data

//recursive 
int binSearchRec(int *nums, int length, int target) {
    if (length == 0) {
        return -1;
    }
    //midpoint, round up
    int m = length / 2;
    if (target == *(nums + m)) {
        //target found
        return m;
    } else if (target < *(nums + m)) {
        //search left
        return binSearchRec(nums, m, target);
    } else if (target > *(nums + m)) {
        //search right
        int subIndex = binSearchRec(nums + m + 1, m - ((length+1) % 2), target);
        return subIndex > -1 ? m + 1 + subIndex : -1;
    }
    return -1;
}

//iterative
int binSearchIter(int *nums, int length, int target) {
    int i = 0, j = length;
    while(i < j) {
        //midpoint, round up
        int m = (i + j) / 2;
        if (target == *(nums + m)) {
            //target found
            return m;
        } else if (target < *(nums + m)) {
            //search left
            j = m;
        } else if (target > *(nums + m)) {
            //search right
            i = m + 1;
        }
    }
    return -1;
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
    printf("\nlinear search\n");
    printf("data unsorted: ");
    printArr(data, 10);
    printf("linear search int 7: %d\n", linearSearch(data, 10, 7));
    printf("linear search int -5: %d\n\n", linearSearch(data, 10, -5));
    
    //binary search O(log(n))
    int sdata[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("binary search (recursive)\n");
    printf("data sorted: ");
    printArr(sdata, 10);
    printf("binary search int 7: %d\n", binSearchRec(sdata, 10, 7));
    printf("binary search int 1: %d\n", binSearchRec(sdata, 10, 1));
    printf("binary search int -5: %d\n\n", binSearchRec(sdata, 10, -5));

    printf("binary search (iterative)\n");
    printf("data sorted: ");
    printArr(sdata, 10);
    printf("binary search int 7: %d\n", binSearchIter(sdata, 10, 7));
    printf("binary search int 1: %d\n", binSearchIter(sdata, 10, 1));
    printf("binary search int -5: %d\n\n", binSearchIter(sdata, 10, -5));

    return 0;
}

/*
Program output:

linear search
data unsorted: 0, 3, 4, 2, 8, 5, 6, 9, 7, 1
linear search int 7: 8
linear search int -5: -1

binary search (recursive)
data sorted: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
binary search int 7: 7
binary search int 1: 1
binary search int -5: -1

binary search (iterative)
data sorted: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
binary search int 7: 7
binary search int 1: 1
binary search int -5: -1

*/


