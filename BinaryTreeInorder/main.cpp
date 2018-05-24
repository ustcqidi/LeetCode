//
//  main.cpp
//  BinaryTreeInorder
//
//  Created by 仓颉 on 16/2/27.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>;
#include <unordered_map>

using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        
        if(root == NULL)
            return inorder;
        
        if(root->left == NULL && root->right == NULL) {
            inorder.push_back(root->val);
            return inorder;
        }
        
        vector<TreeNode*> mStack;
        unordered_map<TreeNode*, int> flags;
        
        if(root->left) {
            mStack.push_back(root);
            mStack.push_back(root->left);
        } else {
            mStack.push_back(root);
        }
        
        while(!mStack.empty()) {
            TreeNode *tmp = mStack.back();
            
            if(tmp->left && flags[tmp->left] != 1) {
                mStack.push_back(tmp->left);
                flags[tmp->left] = 1;
            } else {
                mStack.pop_back();
                inorder.push_back(tmp->val);
                
                if(tmp->right && flags[tmp->right] != 1) {
                    mStack.push_back(tmp->right);
                    flags[tmp->right] = 1;
                }
                
            }
        }
        
        return inorder;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    
    n1->left = n2;
//    n1->right = n2;
//    n2->left = n3;

    s.inorderTraversal(n1);
    
    std::cout << "Hello, World!\n";
    return 0;
}
