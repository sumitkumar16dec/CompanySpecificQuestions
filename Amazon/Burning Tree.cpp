Question: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

Input:
          1
        /   \
       5     3
        \   / \
         4 10  6
        / \
       9   2
Start= 3
  
Output: 4

Note: If-else order must be this only, otherwise wrong answer will come
TC: O(n), SC: O(n)
https://youtu.be/1gNbNxbokxc

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val= data;
        left= nullptr;
        right= nullptr;
    }
};

class Solution {
private:
    int maxDis=0;

public:
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return maxDis;
    }

    int dfs(TreeNode *root, int start){
        if(!root) return 0;

        int left= dfs(root->left, start);
        int right= dfs(root->right, start);
        int depth=0;
        
        if(root->val==start){
            maxDis= max(left,right);
            depth=-1;
        }
        else if(left>=0 && right>=0) depth=max(left,right)+1;
        else{
            maxDis= max(maxDis, (abs(left)+abs(right)));
            depth= min(left,right)-1;
        }
        return depth;
    }
};

int main(){
    TreeNode *root= new TreeNode(1);
    root->left= new TreeNode(5);
    root->right= new TreeNode(3);
    root->left->left= nullptr;
    root->left->right= new TreeNode(4);
    root->right->left= new TreeNode(10);
    root->right->right= new TreeNode(6);
    root->left->right->left= new TreeNode(9);
    root->left->right->right= new TreeNode(2);
    
    Solution sol;
    int minTime= sol.amountOfTime(root, 3);
    cout<<minTime;
    
    return 0;
}
