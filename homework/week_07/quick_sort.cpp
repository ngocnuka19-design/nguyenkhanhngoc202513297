#include <iostream>

using namespace std;

void quick_sort (int arr[], int left, int right);
int quick_sorted_swap (int arr[], int left, int right);

void swap (int *x, int *y){
    int temp = *x; *x = *y; *y = temp;
}

void quick_sort (int arr[], int left, int right){
    if (left < right){
        int pivot_pos = quick_sorted_swap (arr, left, right);
        quick_sort (arr, left, pivot_pos - 1);
        quick_sort (arr, pivot_pos + 1, right);
    }
}


int quick_sorted_swap (int arr[], int left, int right){
    int pivot_pos = left;
    int pivot = arr[pivot_pos];
    int left_id = left + 1;
    int right_id = right;
    while (left_id < right_id){
        while (left_id < right_id && arr[left_id] <= pivot) left_id++;
        while (left_id < right_id && arr[right_id] >= pivot) right_id--;
        
        if (left_id < right_id){
            swap(&arr[left_id], &arr[right_id]);
            left_id++;
            right_id--;
        }
    }
    swap(&arr[pivot_pos], &arr[right_id]);
    pivot_pos = right_id;
    return pivot_pos;
}

int main () {
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

    quick_sort (A, 0, n-1);
    return 0;
}