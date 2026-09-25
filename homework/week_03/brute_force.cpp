#include <iostream>
using namespace std;

int main (){
    int input[6] = {8, 7, 2, 5, 3, 1};
    bool found = 0;
    int target = 10;

    for (int i = 0; i < 6; i++){
        for (int j = i+1; j < 6; j ++){
            if (target - input[j] == input [i]){
                cout << "Pair found (" << input [i] << "," << input[j] <<") \n";
                found = true;
            }
        }
    }
    if (found == false) cout << "Pair not found";
    return 0;
}