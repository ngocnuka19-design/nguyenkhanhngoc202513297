#include <iostream>

using namespace std;

void merge_sort (int arr[], int length);
void merge_sort_recursive (int arr[], int left, int right);
void merge_sorted_arrays (int arr[], int left, int middle, int right);
void twopointer (int arr[], int length, int target) {
    int left = 0, right = length - 1;
    while (left < right){
        if (arr[left] + arr[right] < target) left++;
        else if (arr [left] + arr[right] > target) right--;
        else {
            cout << "Pair found (" << arr [left] << "," << arr[right] <<") \n";
            left++; right--;
            }
    }
}

int main (){ 
    int input[6] = {8, 7, 2, 5, 3, 1};
    int length = 6;
    int target = 10;

    merge_sort (input, length);

    twopointer (input, length, target);
    
    return 0;
}

void merge_sort (int arr[], int length) {
    merge_sort_recursive (arr, 0, length -1);
}

void merge_sort_recursive(int arr[], int left, int right){
    if (left < right) {
    int middle = (left + right) /2;

    merge_sort_recursive (arr, left, middle);
    merge_sort_recursive (arr, middle + 1, right);

    merge_sorted_arrays (arr, left, middle, right);
    }
}

void merge_sorted_arrays (int arr[], int left, int middle, int right){
    int left_length = middle - left + 1;
    int right_length = right - middle;

    int i, j, arr_id;
    int left_array [left_length];
    int right_array [right_length];

    for (i = 0; i < left_length; i++) {
        left_array[i] = arr[left + i];
    }
    for (i = 0; i < right_length; i++) {
        right_array[i] = arr[middle + 1 +i];
    }

    for (i = 0, j = 0, arr_id = left; arr_id <= right; arr_id++) {
        if((i < left_length) && 
            (left_array[i] <= right_array[j] || j >= right_length)){
                arr[arr_id] = left_array[i]; i++;
        }
        else {arr[arr_id] = right_array[j]; j++;}
    }
}

