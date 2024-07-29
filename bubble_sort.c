//
// Created by misha on 22.11.2023.
//
#include <stdio.h>

void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubble_sort(int arr[], int arr_len){
    for (int i=1; i<arr_len; i++)
        for (int j=i; j>0 && arr[j] < arr[j-1]; j--){
            int tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
        }
}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    bubble_sort(arr, arr_len);
    printArray(arr, arr_len);

    return 0;
}
