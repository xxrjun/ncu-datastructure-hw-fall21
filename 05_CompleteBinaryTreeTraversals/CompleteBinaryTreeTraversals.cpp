#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

struct ListNode{
    int data;
    ListNode *next;
    ListNode(){

    }
    ListNode(int data){
        this->data = data;
        this->next = nullptr;
    }
};


TreeNode* converListToBinaryTree(ListNode *head){
    if(head == nullptr)
        return nullptr;

    TreeNode *root = new TreeNode(head->data);
    ListNode *curListNode = head->next;
    queue<TreeNode*> q;
    q.push(root);

    while(curListNode != nullptr){
        // doing left-children
        TreeNode *front = q.front();
        q.pop();
        front->left = new TreeNode(curListNode->data);
        q.push(front->left);
        curListNode = curListNode->next;

        // doing right-children
        if(curListNode != nullptr){
            front->right = new TreeNode(curListNode->data);
            q.push(front->right);
            curListNode = curListNode->next;
        }
    }

    return root;
}

void inorderTraversal(TreeNode *root){
    if(root == nullptr)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
    
}


int main(){
    int n;
    vector<ListNode*> v;
    ListNode *head = new ListNode();
    
    if(cin >> n){
        head->data = n;
        head->next = nullptr;
    }
    ListNode *cur = head;
   
    while(cin >> n){
        ListNode *newListNode = new ListNode(n);
        cur->next = newListNode;
        cur = cur->next;
        if(cin.get() == '\n')
            break;   
    }


    TreeNode *root = converListToBinaryTree(head);
    inorderTraversal(root);
    
}