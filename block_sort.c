//
// Created by misha on 22.11.2023.
//
#include <stdio.h>

void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1];
    int R[n2];

    for (int i=0; i<n1; i++)
        L[i] = arr[start + i];

    for (int i=0; i<n2; i++)
        R[i] = arr[mid + i + 1];

    int l_i=0; int r_i=0; int m_i=start;

    while (l_i < n1 && r_i < n2){
        if (L[l_i] < R[r_i]){
            arr[m_i] = L[l_i];
            l_i++;
        } else {
            arr[m_i] = R[r_i];
            r_i++;
        }
        m_i++;
    }
    while (l_i < n1){
        arr[m_i] = L[l_i];
        l_i++;
        m_i++;
    }
    while (r_i < n2){
        arr[m_i] = R[r_i];
        r_i++;
        m_i++;
    }
}

void merge_sort(int arr[], int start, int end){
    if (start < end){
        int mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void merge_blocks(int arr[], int arr_len, int blocks_amt, int block_len){

    for (int i = 0; i < blocks_amt; i++){
        int start = i * block_len;
        int mid = (i + 1) * block_len;
        int end = (i + 2) * block_len;
        if (end >= arr_len) {
            end = arr_len;
            merge(arr, start, mid, end - 1);
            break;
        }
        merge(arr, start, mid - 1, end - 1);
    }
}

void block_sort(int arr[], int arr_len, int block_len){
    int blocks_amt = arr_len / block_len + 1;
    for (int i=0; i<blocks_amt; i++){
        int start = i * block_len;
        int end = (i + 1) * block_len - 1;
        if (end > arr_len) end = arr_len - 1;

        merge_sort(arr, start, end);
    }

    for (int i = 1; i < blocks_amt; i++) {
        int mid = i * block_len - 1;
        int end = (i + 1) * block_len - 1;
        if (end >= arr_len) end = arr_len - 1;

        merge(arr, 0, mid, end);
    }
}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    block_sort(arr, arr_len, 3);
    printArray(arr, arr_len);

    return 0;
}
