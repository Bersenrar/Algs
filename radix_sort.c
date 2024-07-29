//
// Created by misha on 22.11.2023.
//
#include <stdio.h>
#include <math.h>
void printArray(int arr[], int arr_len){
    for (int i=0; i<arr_len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int get_digit(int num, int digit_counter){
    return (int) (num / pow(10, digit_counter)) % 10;
}

int find_max(int arr[], int arr_len){
    int current_max = arr[0];
    for (int i=1; i<arr_len; i++)
        if (arr[i] > current_max)
            current_max = arr[i];
    return current_max;
}

int count_digits(int n){
    int k = 0;
    while (n > 0){
        n /= 10;
        k++;
    }
    return k;
}

void radix_sort(int arr[], int arr_len){
    int digits_counting_arr[10];
    int buffer[arr_len];

    int digits_amt = count_digits(find_max(arr, arr_len));

    for (int curr_digit=0; curr_digit < digits_amt; curr_digit++){
        for (int j=0; j < 10; j++)
            digits_counting_arr[j] = 0;

        for (int j=0; j<arr_len; j++)
            digits_counting_arr[get_digit(arr[j], curr_digit)]++;

        for (int j = 1; j < 10; j++)
            digits_counting_arr[j] += digits_counting_arr[j - 1];

        for (int j= arr_len - 1; j >= 0; j--){
            buffer[digits_counting_arr[get_digit(arr[j], curr_digit)] - 1] = arr[j];
            digits_counting_arr[get_digit(arr[j], curr_digit)]--;
        }

        for (int j=0; j < arr_len; j++)
            arr[j] = buffer[j];
    }
}

int main(void){
    int arr[] = {53, 77, 89, 521, 424, 646, 777, 1, 2, 3};
    int arr_len = 10;

    printArray(arr, arr_len);
    radix_sort(arr, arr_len);
    printArray(arr, arr_len);

    return 0;
}
