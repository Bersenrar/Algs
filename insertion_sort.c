//
// Created by misha on 22.11.2023.
//
//
// Created by misha on 22.11.2023.
//
#include <stdio.h>

void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion_sort(int arr[], int arr_len){
    for (int i=1; i<arr_len; i++){

        int key = arr[i];
        int j = i-1;

        for (; j >= 0 && key < arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    insertion_sort(arr, arr_len);
    printArray(arr, arr_len);

    return 0;
}
