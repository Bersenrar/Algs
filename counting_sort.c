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

int get_max(int arr[], int arr_len){
    int current_max = arr[0];
    for (int i=1; i<arr_len; i++)
        if (arr[i] > current_max)
            current_max = arr[i];
    return current_max;
}

void counting_sort(int arr[], int arr_len){
    int counting_arr_size = get_max(arr, arr_len);
    int counting_arr[counting_arr_size];

    for (int i=0; i<counting_arr_size; i++)
        counting_arr[i] = 0;

    for (int i=0; i<arr_len; i++)
        counting_arr[arr[i]]++;

    int main_index = 0;
    for (int i=0; i<arr_len; i++){
        for (int j=0; j<counting_arr[i]; j++) {
            arr[main_index] = i;
            main_index++;
        }
    }

}

int main(void){
    int arr[] = {9, 3, 9, 7, 1, 8, 4, 5, 2, 10};
    int arr_len = 10;

    printArray(arr, arr_len);
    counting_sort(arr, arr_len);
    printArray(arr, arr_len);

    return 0;
}
