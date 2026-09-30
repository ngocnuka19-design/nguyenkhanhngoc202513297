#include <iostream>

using namespace std;

void transfer (char org, char end, int &step){
    cout << "Moving disk form " << org << " to " << end << "\n";
    step++;
};

void Tower_of_Hanoi (int num_disk, char org, char mid, char end, int &step){
    if (num_disk == 1) transfer (org, end, step);
    else {
        Tower_of_Hanoi (num_disk - 1, org, end, mid, step); 
        // A -> B with C as temp so "end" in between
        transfer (org, end, step);
        // A -> C
        Tower_of_Hanoi (num_disk - 1, mid, org, end, step);
        // B -> C with A as temp so "A" in the betwenn
    }
}

int main () {
    int n, step = 0;
    cin >> n;
    Tower_of_Hanoi (n, 'A', 'B', 'C', step);
    cout << step;
    return 0;
}