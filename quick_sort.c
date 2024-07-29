//
// Created by misha on 22.11.2023.
//
#include <stdio.h>

void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int start, int end){
    int low = start;
    int top = end-1;
    int pivot = arr[end];

    while (low <= top){

        while (low <= top && arr[low] < pivot) low++;
        while (low <= top && arr[top] > pivot) top--;

        if (low <= top) {
            int tmp = arr[low];
            arr[low] = arr[top];
            arr[top] = tmp;
            low++;
            top--;
        }
    }

    arr[end] = arr[low];
    arr[low] = pivot;
    return low;
}

void quick_sort(int arr[], int start, int end){
    if (start < end){
        int p = partition(arr, start, end);
        quick_sort(arr, start, p-1);
        quick_sort(arr, p+1, end);
    }
}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    quick_sort(arr, 0, arr_len-1);
    printArray(arr, arr_len);

    return 0;
}

