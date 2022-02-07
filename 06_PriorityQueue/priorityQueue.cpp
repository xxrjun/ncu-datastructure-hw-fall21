#include <iostream>
#include <vector>
using namespace std;

struct ToDo{
    string todo;
    int priority;
    ToDo(string t, int p){
        todo = t;
        priority = p;
    }
};

void swap(ToDo &t1, ToDo &t2){
    ToDo tmp = t1;
    t1 = t2;
    t2 = tmp;

}
vector<ToDo*> MaxHeapify(vector<ToDo*> heap, int index, int last){
    int l = 2 * index, r = 2 * index + 1;
    int largest;
    if (l <= last && heap[l]->priority > heap[index]->priority)
        largest = l;
    else
        largest = index;

    if (r <= last && heap[r]->priority > heap[largest]->priority)
        largest = r;
    
    if (largest != index) {                 // 如果目前node的Key不是三者中的最大      
        swap(heap[largest], heap[index]);   // 就調換node與三者中Key最大的node之位置     
        heap = MaxHeapify(heap, largest , last);       // 調整新的subtree成Max Heap
    }
    return heap;
        
}


int main(){
    int n = 0;
    cin >> n;

    vector<ToDo*> heap(n + 1);
    int elementCount = 0;
    string t;
    int p;

    // inserting
    cin >> t >> p;
    ToDo* toDo = new ToDo(t, p);
    heap[1] = toDo;
    elementCount++;
    for(int i = elementCount + 1 ; i <= n; i++){
        cin >> t >> p;
        toDo = new ToDo(t, p);
        heap[i] = toDo;
        elementCount++;
    }

    // MaxHeapify
    for(int i = (elementCount / 2) ; i >= 1 ; i--){
        heap = MaxHeapify(heap, i, elementCount);
    }
   
    // for(int i = 1 ; i <= elementCount ; i++)
    //     cout << heap[i]->priority << " ";
    // cout << endl;

    cout << "First three things to do:" << endl;
    cout << heap[1]->todo << endl;
    int third;
    if(heap[2]->priority > heap[3]->priority){
        cout << heap[2]->todo << endl;
        third = 3;
    }
    else{
        cout << heap[3]->todo << endl;
        third = 2;
    }
    
    if(4 <= elementCount && heap[4]->priority > heap[third]->priority)
        third = 4;
    if(5 <= elementCount && heap[5]->priority > heap[third]->priority)
        third = 5;
    cout << heap[third]->todo << endl;
}

/*
12
a 100
b 3
c 8
d 102
e 521
f 1251
g 15
h 125
i 36
j 136
k 125
l 132
*/