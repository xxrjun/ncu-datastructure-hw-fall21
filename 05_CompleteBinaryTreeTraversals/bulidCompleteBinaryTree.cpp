
#include <iostream>
#include <queue>
using namespace std;
 
// A Binary Tree Node
struct TreeNode
{
    int data;
    TreeNode *left, *right;
 
    TreeNode(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// A Linked List Node
struct ListNode
{
    int data;
    ListNode* next;
 
    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
 
// Utility function to create a new node with the given data and
// pushes it onto the list's front
ListNode* push(ListNode* head, int data)
{
    ListNode* node = new ListNode(data);
    node->next = head;
    head = node;
    return head;
}
 
// Function to perform preorder traversal on a given binary tree.
void preorder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
 
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}
 
// Function to construct a complete binary tree from a given linked list
TreeNode* convertListToBinaryTree(ListNode* head)
{
    // base case
    if (head == nullptr) {
        return nullptr;
    }
 
    // create the root using the first node of the linked list
    TreeNode* root = new TreeNode(head->data);
 
    // move the head pointer to the next node
    head = head->next;
 
    // create a queue to store tree pointers and enqueue the root node
    queue<TreeNode*> q;
    q.push(root);
 
    // loop till the end of the linked list is reached
    while (head)
    {
        // dequeue front node
        TreeNode* front = q.front();
        q.pop();
 
        // create a left child from the next node in the linked list and enqueue it
        front->left = new TreeNode(head->data);
        q.push(front->left);
 
        // move the head pointer to the next node
        head = head->next;
 
        // if the linked list did not reach its end
        if (head != nullptr)
        {
            // create the right child from the next node in the linked list and
            // enqueue it
            front->right = new TreeNode(head->data);
            q.push(front->right);
 
            // move the head pointer to the next node
            head = head->next;
        }
    }
 
    // return root of the constructed binary tree
    return root;
}
 
int main()
{
    ListNode* head = nullptr;
    int n = 6;
 
    // construct a linked list
    for (int i = n; i > 0; i--) {
        head = push(head, i);
    }
 
    TreeNode* root = convertListToBinaryTree(head);
    preorder(root);
 
    return 0;
}