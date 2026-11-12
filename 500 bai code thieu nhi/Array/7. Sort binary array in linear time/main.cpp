#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;

    int input[n];

    for(int i = 0; i < n; i++){
        cin >> input[i]; 
    }

    int length = sizeof(input) / sizeof(input[0]);
    int count = 0;

    for (int i = 0; i < length; i++){
        if (input[i] == 0) count++;
    }

    int output [length] = {0};
    for (int i = 0 + count; i < length; i++){
        output [i] = 1;
    }

    for (int i = 0; i < length; i++){
        cout << output[i] <<"    ";
    }
    return 0;
}