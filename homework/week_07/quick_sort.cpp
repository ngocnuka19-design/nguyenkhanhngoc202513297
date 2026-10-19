#include <iostream>

using namespace std;

void quick_sort(int arr[], int length);
void quick_sort_recursive (int arr[], int left, int right);
int partition (int arr[], int left, int right);
void swap (int *x, int * y){
    int temp = *x; *x = *y; *y = temp;
}

void print_arr (int arr[], int left, int right){
    int length = right - left + 1;
    for (int i = 0; i < length; i++) {
       cout << arr[left + i] << "   ";
    }
    cout << endl;
}

void quick_sort (int arr[], int length){
    quick_sort_recursive (arr, 0, length -1);
}

void quick_sort_recursive (int arr[], int left, int right){
    if (left < right){
        cout << "Divide: ";
        print_arr (arr, left, right);

        int pivot_pos = partition (arr, left, right);


        cout << "Conquer: ";
        print_arr (arr, left, right);
        quick_sort_recursive (arr, left, pivot_pos - 1);
        quick_sort_recursive (arr, pivot_pos +1, right);
    }
}

int partition (int arr[], int left, int right){
    int pivot_pos = left;
    int pivot = arr[left];

    left = left + 1; // so that pivot start scanning at left + 1?

    while (left <= right){
        while (left <= right && arr[left] <= pivot) left++;
        while (left <= right && arr[right] > pivot) right--;

        if(left < right) swap (&arr[left++], &arr[right--]);
    }

    swap(&arr[pivot_pos], &arr[right]);

    return right;
}

int main (){
    int n;
    cin >> n;

    int A[n];

    for(int i = 0; i < n; i++){
        cin >> A[i]; 
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << "   ";
    }
    cout << "\n" << "The above is printing the initial array" << "\n";
    quick_sort (A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << "   ";
    }
    return 0;
}