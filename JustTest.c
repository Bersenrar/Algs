//
// Created by misha on 24.11.2023.
//
#include <stdio.h>

void printArr(int A[], int n){
    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void insertion_sort(int arr[], int arr_len){
    for (int i=1; i<arr_len; i++) {
        int key = arr[i];
        int j = i - 1;
        for (; j >= 0 && key < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void shell_sort(int arr[], int arr_len){
    for (int step = arr_len/2; step > 0; step /= 2){
        for (int main_index = step; main_index < arr_len; main_index++){
            for (int back_index = main_index - step; back_index >= 0 && arr[main_index] < arr[back_index]; back_index -= step){
                int tmp = arr[main_index];
                arr[main_index] = arr[back_index];
                arr[back_index] = tmp;
            }
        }
    }
}

int main(){
    int arr[] = {3, 1, 5, 5, 4, 1, 3, 9, -30, 20, 31};
    int arr_len = 11;
    printArr(arr, arr_len);
    shell_sort(arr, arr_len);
    printArr(arr, arr_len);
    return 0;
}