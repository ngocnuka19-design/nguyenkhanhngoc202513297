#include <iostream>

using namespace std;

typedef struct
{
    int value;
    int pos;
} prefix_sum;

void merge_sort (prefix_sum arr[], int length);
void merge_sort_recursive (prefix_sum arr[], int left, int right);
void merge_sorted_array (prefix_sum arr[], int left, int middle, int right);

void merge_sort_prefix (prefix_sum prefix[], int length, int arr[]){
    merge_sort(prefix, length);
    
    bool found = false;
    int i = 0;

    while (i < length - 1){  
        int j = i +1;
        while (j < length && prefix[i].value == prefix[j].value) j++;
        if (j - i > 1){
            found = true;
            for (int a = i; a < j; a++){
                for (int b = a + 1; b < j; b++){
                    int start = min(prefix[a].pos, prefix[b].pos) +1;
                    int end = max (prefix[a].pos, prefix[b].pos);
                    cout << "{ ";

                    for (int k = start; k <= end; k++){
                        cout << arr[k] << " ";
                    }
                    
                    cout << "}" << endl;
                }
            }
        } 
    i = j;
   }
   if (found == false) cout << "No zero-sum subarray exists.";
}


void merge_sort (prefix_sum arr[], int length){
    merge_sort_recursive (arr, 0, length -1);
}

void merge_sort_recursive (prefix_sum arr[], int left, int right){
    if (left < right) {
        int middle = (left + right) /2;

        merge_sort_recursive (arr, left, middle);
        merge_sort_recursive (arr, middle +1, right);

        merge_sorted_array (arr, left, middle, right);
    }
}

void merge_sorted_array (prefix_sum arr[], int left, int middle, int right){
    int left_length = middle - left + 1;
    int right_length = right - middle;

    prefix_sum left_arr [left_length];
    prefix_sum right_arr [right_length];

    for (int i = 0; i < left_length; i++){
        left_arr[i] = arr[i + left];
    }

    for (int i = 0; i < right_length; i++){
        right_arr[i] = arr[middle + 1 + i];
    }

    int left_id, right_id, arr_id = left;
    for (left_id = 0, right_id = 0; arr_id < right + 1; arr_id++){
        if (left_id < left_length
        && ((right_id >= right_length) 
        || ((left_arr[left_id].value <= right_arr[right_id].value)))){
            arr[arr_id] = left_arr[left_id++];
        }
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

    prefix_sum prefix[n + 1];
    prefix[0] = {0, -1};
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + A[i];

        prefix[i + 1] = {sum, i}; 
    }

    merge_sort_prefix(prefix, n + 1, A);
    return 0;
}