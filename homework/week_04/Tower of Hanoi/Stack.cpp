#include <iostream>

using namespace std;

template <typename T>

class My_Stack {
    private: 
        T* arr;
        int capacity;
        int topId;

    void resize(){
        int new_cap = capacity *2;
        T* new_arr = new T[new_cap];
        for (int i = 0; i < capacity; i++){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_cap;
    }

    public: 
    My_Stack (int cap){
        capacity = cap;
        arr = new T[capacity];
        topId = -1;
    }
    ~My_Stack(){delete[] arr;}

    bool empty (){
        return topId == -1;
    }

    int size (){
        return (topId + 1);
    }

    void pop (){
        if(empty()) return;
        topId--;
    }

    T& top (){
        return arr[topId];
    }

    void push (const T& value){
        if (topId == capacity -1) resize();
        topId++;
        arr[topId] = value;
    }
};

struct task {
    int num_disk;
    char org, mid, end;
};

void transfer (char org, char end, int &step){
    cout << "Moving disk from " << org << " to " << end << "\n";
    step++;
}

void Tower_of_Hanoi (int num_disk, char org, char mid, char end, int &step){
    My_Stack <task> st(100);
    st.push ({num_disk, org, mid, end});
    
    while (!st.empty()){
        task temp = st.top();
        st.pop();
        if (temp.num_disk == 1) transfer(temp.org, temp.end, step);
        // Since stack is LIFO, the order would be flipped
        else {
            st.push({temp.num_disk -1, temp.mid, temp.org, temp.end});
            st.push({1, temp.org, temp.mid, temp.end});
            st.push({temp.num_disk - 1, temp.org, temp.end, temp.mid});
        }
    }
} 
int main (){
    int n, step = 0;
    cin >> n;
    Tower_of_Hanoi (n, 'A', 'B', 'C', step);
    cout << step;
    return 0;
}