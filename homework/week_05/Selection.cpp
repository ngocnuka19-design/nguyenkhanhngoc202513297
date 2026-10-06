#include <iostream>

using namespace std;

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
    
    for (int i = 0; i < n; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++){
            if(A[j] < A[min]) min = j;
        }

        int temp = A[i]; A[i] = A[min]; A[min] = temp;

        for (int k = 0; k < n; k++) {
        cout << A[k] << "   ";
        }

        cout << "\n";
    }

}