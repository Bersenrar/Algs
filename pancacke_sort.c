//
// Created by misha on 22.11.2023.
//
#include <stdio.h>

void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int find_max_index(int arr[], int end){
    int current_max_i = 0;
    for (int i=1; i<=end; i++)
        if (arr[i] > arr[current_max_i])
            current_max_i = i;
    return current_max_i;
}

void flip(int arr[],int start, int end){
    for (int i=start, j=end; i < j; i++, j--){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void pancake_sort(int arr[], int arr_len){
    for (int i=arr_len-1; i>0; i--){
        int max = find_max_index(arr, i);
        flip(arr, 0, max);
        flip(arr, 0, i);
    }
}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    pancake_sort(arr, arr_len);
    printArray(arr, arr_len);

    return 0;
}