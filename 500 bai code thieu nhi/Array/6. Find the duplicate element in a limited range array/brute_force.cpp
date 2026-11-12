#include <iostream>

using namespace std;

int main (){
    int input[] = {1, 2, 3, 4, 4};
    int length = sizeof(input)/sizeof(input[0]);

    for (int i = 0; i < length; i++){
        for (int j = i+1; j < length; j++){
            if (input[i] == input[j]){
                cout << "The duplicate element is: " << input[i];
                return 0;
            }
        }
    }
}