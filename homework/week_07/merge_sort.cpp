#include <iostream>

using namespace std;

void print_arr (int arr[], int left, int right){
    int length = right - left + 1;
    for (int i = 0; i < length; i++) {
       cout << arr[left + i] << "   ";
    }
    cout << endl;
}

void merge_sort (int arr[], int length);
void merge_sort_recursive (int arr[], int left, int right);
void merge_sorted_array (int arr [], int left, int middle, int right);

void merge_sort (int arr [], int length){
    merge_sort_recursive (arr, 0, length - 1);
}

void merge_sort_recursive (int arr [], int left, int right){
    if (left < right) {
        int middle = (right + left) / 2;

        cout << "Divide: ";
        print_arr (arr, left, right);

        merge_sort_recursive (arr, left, middle);
        merge_sort_recursive (arr, middle + 1, right);

        // When merge, merge 2 array into 1, so only call merge sorted arr once
        merge_sorted_array (arr, left, middle, right);

        cout << "Merge: ";
        print_arr (arr, left, right);
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

    for (int k = 0; k < n; k++) {
        cout << A[k] << "   ";
        }
    cout << "\n" << "The above is printing the initial array" << "\n";

    merge_sort (A, n);
    return 0;
}

