#include <iostream>

using namespace std;

int main (){
     int n;
    cin >> n;

    int A[n];

    for(int i = 0; i < n; i++){
        cin >> A[i]; 
    }


    int max = A [0];
    for (int i = 0; i < n -1; i++){
        if (A[i+1] > A[i]) max = A[i+1];
    }

    int visted[max] = {0};

    for (int i = 0; i < max; i++){
        if (visted[A[i]] == 1){
            cout << "The duplicate element is: " << A[i];
            return 0;
        }
        else visted [A[i]] = 1;
    }
}