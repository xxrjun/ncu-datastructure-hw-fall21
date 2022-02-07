#include <iostream>
#include <string>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(){
        next = nullptr;
    }
    Node(int key){
        val = key;
        next = nullptr;
    }
};

int size = 0;

void addBack(Node *front, int key);
void addFront(Node *front, int key);
void addIndex(Node *front, int index, int val);
void deleteIndex(Node *front, int index);
void printList(Node *front);
int getSize();

int main(){
    Node *front = new Node();
    
    string command;
    while(cin >> command){
        if(command == "exit"){
            printList(front);
            break;
        }  
        else{
            int index = 0, key = 0;
            if(command == "addBack"){
                cin >> key;
                addBack(front, key);
            }
            else if (command == "addFront"){
                cin >> key;
                addFront(front, key);
            }
            else if (command == "addIndex"){
                cin >> index >> key;
                addIndex(front, index, key);
            }
            else if (command == "deleteIndex"){
                cin >> index;
                deleteIndex(front, index);
            }
        }
    }
}

void addBack(Node *front, int key){
    Node *cur = front->next;
    if(front->next == nullptr){
        front->next = new Node(key);
    }
    else{
        while(cur->next != nullptr)
            cur = cur->next;
        cur->next = new Node(key);
    }
    size++;
    
}
void addFront(Node *front, int key){
    if(front->next == nullptr)
        front->next = new Node(key);
    else{
        Node *tmp = front->next;
        Node *newNode = new Node(key);
        front->next = newNode;
        newNode->next = tmp;
    }
    size++;
}
void addIndex(Node *front, int index, int key){
    int listSize = getSize();
    if(index > listSize)
        return;
    else if(index == listSize - 1){
        addBack(front, key);
        return;
    }

    int cur_index= 0;
    Node *cur = front->next;
    Node *prev = front;
    
    while(cur_index <= listSize){
        if(cur_index == index){
            Node *newNode = new Node(key);
            prev->next = newNode;
            newNode->next = cur;
            size++;
            return;
        }
        prev = cur;
        cur = cur->next;
        cur_index++;
    }
    
}
void deleteIndex(Node *front, int index){
    int listSize = getSize();
     
    if(index > listSize)
        return;
    
    int cur_index= 0;
    Node *cur = front->next;
    Node *prev = front; 
    while(cur_index < listSize){
        if(cur_index == index){
            Node *tmp = cur;
            prev->next = cur->next;
            delete(tmp);
            size--;
            return;
        }
        prev = cur;
        cur = cur->next;
        cur_index++;
    }
}

void printList(Node *front){
    if(front->next == nullptr)
        cout << "null" << endl;
    else{
        Node *cur = front->next;
        while(cur != nullptr){
            cout << cur->val << "-->";
            cur = cur->next;
        }
        cout << "null" << endl;
    }
    
}

int getSize(){
    return size;
}