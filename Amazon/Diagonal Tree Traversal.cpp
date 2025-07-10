Question: https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
Input:
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output: [8, 10, 14, 3, 6, 7, 13, 1, 4]

TC: O(n), SC: O(n)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition of binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *cur = q.front(); q.pop();
            while(cur){
                if(cur->left) q.push(cur->left);
                ans.push_back(cur->data);
                cur = cur->right;
            }
        }
        return ans;
    }
};

int main() {
    /*
        Example tree:
               8
             /   \
            3     10
           / \      \
          1   6      14
             / \    /
            4   7  13

        Diagonal traversal: 8 10 14 3 6 7 13 1 4
    */

    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Solution sol;
    vector<int> res = sol.diagonal(root);

    cout << "Diagonal Traversal: ";
    for(int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
