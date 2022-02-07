#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int data;
    Node *link;
    Node()
    {
        link = nullptr;
    }
    Node(int key)
    {
        data = key;
        link = nullptr;
    }
};
void addBack(Node *front, int input);
void addFront(Node *front, int key);
void addIndex(Node *front, int index, int key);
void deleteIndex(Node *front, int index);
void printList(Node *front);
int getsize();
int size = 0;
int main()
{
    Node *front = new Node();
    Node *rear = new Node();
    string command;
    while (cin >> command)
    {
        if (command == "exit")
        {
            break;
        }
        else
        {
            int input = 0, index = 0;
            if (command == "addBack")
            {

                cin >> input;
                addBack(front, input);
            }
            else if (command == "addFront")
            {
                cin >> input;
                addFront(front, input);
            }
            else if (command == "addIndex")
            {
                cin >> index >> input;
                addIndex(front, index, input);
            }
            else if (command == "deleteIndex")
            {
                cin >> index;
                deleteIndex(front, index);
            }
        }
    }
    printList(front);
}
void addBack(Node *front, int key)
{
    Node *cur = front->link;
    if (front->link == nullptr)
    {
        front->link = new Node(key);
    }
    else
    {
        while (cur->link != nullptr)
        {
            cur = cur->link;
        }
        cur->link = new Node(key);
    }
    size++;
}
void addFront(Node *front, int key)
{
    Node *temp = new Node(key);
    Node *cur = front->link;
    if (front->link == nullptr)
    {
        front->link = new Node(key);
    }
    else
    {
        temp->link = front->link;
        front->link = temp;
    }
    size++;
}
void addIndex(Node *front, int index, int key)
{
    if (getsize() > index) // how about add in the end of queue
    {
        Node *cur = front->link;
        Node *temp = new Node(key);
        if (front->link == nullptr) // size = 0, how to come in this block?
        {
            if (index == 0)
            {
                front->link = new Node(key); // temp?
            }
        }
        else
        {
            if (index == 0)
            {
                temp->link = front->link;
                front->link = temp;
            }
            else
            {
                for (int i = 0; i < index - 1; i++)
                {
                    cur = cur->link;
                }
                temp->link = cur->link;
                cur->link = temp;
            }
        }
        size++;
    }

}
void deleteIndex(Node *front, int index)
{
    if (getsize() > index)
    {
        Node *cur = front->link;
        Node *becur = front->link;
        Node *temp = new Node();
        if (front->link == nullptr)
        {
            front->link = nullptr;
        }
        else
        {
            if (index == 0)
            {
                cur = cur->link;
                front->link = cur;
            }
            else
            {
                for (int i = 0; i < index; i++)
                {
                    cur = cur->link;
                }
                for (int i = 0; i < index - 1; i++)
                {
                    becur = becur->link;
                }
                becur->link = cur->link;
            }
        }
        size--;
    }
 
}
void printList(Node *front)
{
    if (front->link == nullptr)
        cout << "null" << endl;
    else
    {
        Node *cur = front->link;
        while (cur != nullptr)
        {
            cout << cur->data << "-->";
            cur = cur->link;
        }
        
    }
    cout << "null" << endl;
    
}
int getsize()
{
    return size;
}