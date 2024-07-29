//
// Created by misha on 22.11.2023.
//
#include <stdio.h>

void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void shell_sort(int arr[], int arr_len){
    for (int step = arr_len / 2 - 1; step > 0; step /= 2) {
        for (int i = step; i < arr_len; i++){
            for (int j = i - step; j >= 0 && arr[i] < arr[j]; j--){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    shell_sort(arr, arr_len);
    printArray(arr, arr_len);

    return 0;
}
