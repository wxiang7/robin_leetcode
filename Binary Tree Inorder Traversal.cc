/** 
 * Definition for binary tree 
 * struct TreeNode { 
 *     int val; 
 *     TreeNode *left; 
 *     TreeNode *right; 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
 * }; 
 */ 
class Solution { 
public: 
    vector<int> inorderTraversal(TreeNode *root) { 
        vector<int> res; 
        if (root != NULL) { 
            vector<int> left = inorderTraversal(root->left); 
            for (auto v : left) { 
                res.push_back(v); 
            } 
            res.push_back(root->val); 
            vector<int> right = inorderTraversal(root->right); 
            for (auto v : right) { 
                res.push_back(v); 
            } 
        } 
        return res; 
    } 
};