//
// Created by misha on 24.11.2023.
//
#include <stdio.h>

void printArr(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int find_min(int arr[], int arr_len){
    int current_min = arr[0];
    for (int i=1; i<arr_len; i++)
        if (arr[i] < current_min)
            current_min = arr[i];
    return current_min;
}

int find_max(int arr[], int arr_len){
    int current_max = arr[0];
    for (int i=1; i<arr_len; i++)
        if (arr[i] > current_max)
            current_max = arr[i];
    return current_max;
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

    int l_i = 0; int r_i = 0; int m_i = start;

    while (l_i < n1 && r_i < n2){
        if (L[l_i] <= R[r_i]){
            arr[m_i] = L[l_i];
            l_i++;
        }else{
            arr[m_i] = R[r_i];
            r_i++;
        }
        m_i++;
    }
    while (l_i<n1){
        arr[m_i] = L[l_i];
        l_i++;
        m_i++;
    }
    while (r_i<n2){
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

void block_sort(int arr[], int arr_len){
    int min = find_min(arr, arr_len);
    int max = find_max(arr, arr_len);

    int mid = arr_len / 2;

    int FirstBlock[mid];
    int SecondBlock[mid];

    int b_1_size = 0;
    int b_2_size = 0;

    for (int i=0; i<arr_len; i++){
        if (2 * ((arr[i] - min) / (max - min + 1)) == 0){
            FirstBlock[b_1_size] = arr[i];
            b_1_size++;
        } else{
            SecondBlock[b_2_size] = arr[i];
            b_2_size++;
        }
    }

    merge_sort(FirstBlock, 0, b_1_size-1);
    merge_sort(SecondBlock, 0, b_2_size-1);

    int i_1 = 0; int i_2 = 0; int m_i = 0;

    while (i_1 < b_1_size){
        arr[m_i] = FirstBlock[i_1];
        i_1++;
        m_i++;
    }

    while (i_2 < b_2_size){
        arr[m_i] = SecondBlock[i_2];
        i_2++;
        m_i++;
    }

}

int main(){
    int arr[] = {5, 3, 17, 19, 16, 20, 18, 15};
    int arr_len = 8;
    printArr(arr, arr_len);
    block_sort(arr, arr_len);
    printArr(arr, arr_len);
    return 0;
}
