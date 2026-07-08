// You are using GCC
#include <iostream>
using namespace std;

struct Node{
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

Node* insertNode(Node* root,int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data<root->data) root->left = insertNode(root->left,data);
    else if(data>root->data) root->right = insertNode(root->right,data);
    return root;
}

Node* search(Node* root,int key){
    if(root==NULL || root->data==key) return root;
    if(key<root->data) return search(root->left,key);
    return search(root->right,key);
}

Node* deleteNode(Node* root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right = deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
}
int main(){
    Node* root = new Node();
    root=insertNode(root,1);
    root=insertNode(root,2);
    root=insertNode(root,3);
    root=insertNode(root,4);
    root=insertNode(root,5);
    Node* found = search(root,1);
    cout << found->data;
    
}
