#include <iostream>
#include <vector>
using namespace std;

struct TODO{
    string todo;
    int prior;
    TODO(string t, int p){
        todo = t;
        prior = p;
    }
};

int main(){
    int n;
    cin >> n;

    vector<TODO*> heap(n + 1);
    string todo;
    int p;
    cin >>  todo >> p;

    int cur = 0, last = 0;
    heap[cur] = new TODO(todo, p);
    for(int i = 1 ; i < n ; i++){
        cin >> todo >> p;
        cur = ++last;
        while((cur != 0) && p > heap[cur / 2]->prior ){
            heap[cur] = heap[cur / 2];
            cur /= 2;
        }
        heap[cur] = new TODO(todo, p);
        // while((last % 2 == 0) && (cur != 0) && (heap[last]->prior > heap[last - 1]->prior)){
        //     TODO* tmp = heap[last];
        //     heap[last] = heap[last - 1];
        //     heap[last - 1] = tmp;
        // }
    }

    for(int i = 0 ; i < n ; i++)
            cout << heap[i]->prior << " ";
    cout << endl;

    cout << "First three things to do:" << endl;
    cout << heap[0]->todo << endl;
    cout << heap[1]->todo << endl;
    int third = 2;
    
    if(3 < n && heap[3]->prior> heap[third]->prior)
        third = 3;
    if(4 < n && heap[4]->prior > heap[third]->prior)
        third = 4;
    cout << heap[third]->todo << endl;
}

/*
12
a 3
b 4
c 5
d 898
e 8
f 11
g 2
h 3
i 0
j 100
k 66
l 100
*/
