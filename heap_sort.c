//
// Created by misha on 22.11.2023.
//
#include <stdio.h>

void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void heapify(int arr[], int root_i, int end){

    int left_node_i = root_i * 2 + 1;
    int right_node_i = root_i * 2 + 2;

    int largest = root_i;

    if (left_node_i < end && arr[left_node_i] > arr[largest])
        largest = left_node_i;

    if (right_node_i < end && arr[right_node_i] > arr[largest])
        largest = right_node_i;

    if (largest != root_i){
        int tmp = arr[root_i];
        arr[root_i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, largest, end);
    }
}

void heap_sort(int arr[], int arr_len){

    for (int j = arr_len - 1; j >= 0; j--)
        heapify(arr, j, arr_len);

    for (int i=arr_len-1; i>0; i--){
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        heapify(arr, 0, i);
    }
}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    heap_sort(arr, arr_len);
    printArray(arr, arr_len);

    return 0;
}
