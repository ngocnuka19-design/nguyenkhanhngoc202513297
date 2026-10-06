#include <iostream>

using namespace std;

void swap(int *x, int *y){
    int temp = *x; *x = *y; *y = temp;
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

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++){
            if (A[i] < A[j]) swap(&A[i], &A[j]);
        }
        for (int k = 0; k < n; k++) {
        cout << A[k] << "   ";
        }
        cout << "\n";
    }
    
}