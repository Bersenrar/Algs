//
// Created by misha on 22.11.2023.
//
#include <stdio.h>

void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++){
        int current_min_index = i;

        for (int j=i+1; j<arr_len; j++)
            if (arr[current_min_index] > arr[j])
                current_min_index = j;

        if (current_min_index != i){
            int tmp = arr[current_min_index];
            arr[current_min_index] = arr[i];
            arr[i] = tmp;
        }
    }
}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    selection_sort(arr, arr_len);
    printArray(arr, arr_len);

    return 0;
}
