//
//  main.cpp
//  BinaryTreePaths
//
//  Created by 仓颉 on 16/2/26.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        
        vector<TreeNode*> nodes;
        
        unordered_map<TreeNode *, int> nodeFlag;
        
        
        if (root == NULL) {
            return paths;
        } else if(root->left == NULL && root->right == NULL) {
            paths.push_back(to_string(root->val));
            return paths;
        }
        
        nodes.push_back(root);
        
        while (!nodes.empty()) {
            TreeNode *node = nodes.back();
            
            if (node->left && nodeFlag[node->left] != 1) {
                nodes.push_back(node->left);
                nodeFlag[node->left] = 1;
            } else if (node->right && nodeFlag[node->right] != 1) {
                nodes.push_back(node->right);
                nodeFlag[node->right] = 1;
            } else if(node->left == NULL && node->right == NULL){ //leaf node
                TreeNode *tmp = nodes.at(0);
                string path = to_string(tmp->val);
                
                for (int i = 1; i < nodes.size(); i++) {
                    tmp = nodes.at(i);
                    path = path + "->" + to_string(tmp->val);
                }
                
                paths.push_back(path);
                nodes.pop_back();
            } else {
                nodes.pop_back();
            }
        }
        
        
        return paths;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    
    TreeNode *root = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    root->left = n2;
    root->right = n3;
    
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    
//    n2->left = n4;
    n2->right = n5;
    
   vector<string> ret = s.binaryTreePaths(root);
    
    std::cout << "Hello, World!\n";
    return 0;
}
