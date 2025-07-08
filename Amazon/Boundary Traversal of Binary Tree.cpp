Given a root of Binary Tree, perform the boundary traversal of the tree. 
The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.
The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered from left-to-right, and the reverse order of the right boundary.
The left boundary is the set of nodes defined by the following:
The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
If a node in the left boundary and has a left child, then the left child is in the left boundary.
If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
The leftmost leaf is not in the left boundary.
The right boundary is similar to the left boundary, except it is the right side of the root's right subtree. Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.

Input : root = [1, 2, 3, 4, 5, 6, 7, null, null, 8, 9]
Output : [1, 2, 4, 8, 9, 6, 7, 3]

Input : root = [1, 2, null, 4, 9, 6, 5, 3, null, null, null, null, null, 7, 8]
Output : [1, 2, 4, 6, 5, 7, 8]

  
Better Solution :
TC: O(H) + O(N) + O(H)= O(N)
SC: O(N) (due to output) + O(H) (auxiliary space for recursion & temp vector)

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    
    Node(int data){
        this->data= data;
        this->left= nullptr;
        this->right= nullptr;
    }
};

bool isLeaf(Node *root){
    return (root->left==nullptr && root->right==nullptr);
}

void leftside(Node *root, vector<int> &res){
    Node *cur= root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur= cur->left;
        else cur= cur->right;
    }
}

void leafnodes(Node *root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    
    if(root->left) leafnodes(root->left, res);
    if(root->right) leafnodes(root->right, res);
}

void rightside(Node *root, vector<int> &res){
    Node *cur= root->right;
    vector<int> temp;

    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur= cur->right;
        else cur= cur->left;
    }
    
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

vector<int> func(Node *root){
    vector<int> res;
    if(root==nullptr) return res;
    
    if(!isLeaf(root)) res.push_back(root->data);
    leftside(root, res);
    leafnodes(root, res);
    rightside(root, res);
    
    return res;
}

int main(){
    Node *root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    
    vector<int> res= func(root);
    for(int i: res){
        cout<<i<<" ";
    }
    return 0;
}


Optimal Solution :

