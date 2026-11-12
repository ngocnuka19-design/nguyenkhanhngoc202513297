#include <iostream>

using namespace std;

int main (){
    int n;
    cin >> n;

    int A[n];

    for(int i = 0; i < n; i++){
        cin >> A[i]; 
    }

    int max_length = 0;
    int result[n] = {0};

    for (int i = 0; i < n; i++){
        int min = A[i];
        int max = A[i];

        int visted[n] = {0};

        for (int j = i; j < n; j++){
            if (A[j] > max) max = A[j];
            if (A[j] < min) min = A[j];

            bool duplicate = false;

            for (int k = i; k < j; k++){
                if (A[k] == A[j]){
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) break;

            if (max_length < (max - min + 1) && (max - min + 1) == j - i + 1){
                max_length = max - min + 1;
                for (int k = 0; k < max_length; k++){
                    result[k] = A[i + k];
                }
            }
        }
    }
    for (int i = 0; i < max_length; i++){
        cout << result[i] << "  ";
    }
    return 0;
}
