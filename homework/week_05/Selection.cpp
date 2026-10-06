#include <iostream>

using namespace std;

int main (){
    int A[13] = {101,23,57,13,25,121,87,36,13,204,111,89,59};
    // Printing the initial array
    for (int k = 0; k < 13; k++) {
        cout << A[k] << "   ";
        }
    cout << "\n" << "The above is printing the initial array" << "\n";
    
    for (int i = 0; i < 13; i++) {
        int min = i;

        for (int j = i + 1; j < 13; j++){
            if(A[j] < A[min]) min = j;
        }

        int temp = A[i]; A[i] = A[min]; A[min] = temp;

        for (int k = 0; k < 13; k++) {
        cout << A[k] << "   ";
        }

        cout << "\n";
    }

}