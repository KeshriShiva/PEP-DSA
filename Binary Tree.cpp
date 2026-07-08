// You are using GCC
#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val){
    Node* node = new Node();
    node->data = val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void inOrderTraversal(Node* root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
    if(root==NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}



int main()
{
    Node* root = createNode(10);
    root->left = createNode(11);
    root->right = createNode(9);
    root->left->left = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
    cout << " In Order : ";
    inOrderTraversal(root);
    cout << "\n Pre Order: ";
    preOrderTraversal(root);
    cout << "\n Post Order: ";
    postOrderTraversal(root);
    
}
