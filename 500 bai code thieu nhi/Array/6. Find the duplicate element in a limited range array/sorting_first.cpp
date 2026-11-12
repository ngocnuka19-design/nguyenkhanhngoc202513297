#include <iostream>

using namespace std;


void merge_sort (int arr[], int length);
void merge_sort_recursive (int arr[], int left, int right);
void merge_sorted_array (int arr [], int left, int middle, int right);

void merge_sort (int arr [], int length){
    merge_sort_recursive (arr, 0, length - 1);
}

void merge_sort_recursive (int arr [], int left, int right){
    if (left < right) {
        int middle = (right + left) / 2;

        merge_sort_recursive (arr, left, middle);
        merge_sort_recursive (arr, middle + 1, right);

        // When merge, merge 2 array into 1, so only call merge sorted arr once
        merge_sorted_array (arr, left, middle, right);
    }
}

void merge_sorted_array (int arr [], int left, int middle, int right){
    int left_length = middle - left + 1;
    int right_length = right - middle;

    int lefr_arr [left_length];
    int right_arr [right_length];
    
    for (int i = 0; i < left_length; i++){
        lefr_arr[i] = arr[left + i];
    }

    for (int i = 0; i < right_length; i++){
        right_arr[i] = arr[middle + 1 + i];
    }
    
    int left_id, right_id, arr_id = left;
    for (left_id = 0, right_id = 0, arr_id = left; arr_id <= right; arr_id++){
        if((left_id < left_length)
            && (right_id >= right_length 
            || lefr_arr[left_id] < right_arr[right_id]))
            arr[arr_id] = lefr_arr[left_id++];

        else arr[arr_id] = right_arr[right_id++];
    }
}

int main (){
    int n;
    cin >> n;

    int A[n];

    for(int i = 0; i < n; i++){
        cin >> A[i]; 
    }

    merge_sort(A, n);

    for (int i = 0; i < n-1; i++){
        if(A[i] == A[i+1]) {
            cout << "The duplicate element is: " << A[i];
            return 0;
        }
    }
}