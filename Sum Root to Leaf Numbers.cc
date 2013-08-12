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
private: 
    int res; 
    void traverse(TreeNode *root, int current) { 
        if (root == NULL) return; 
        if (root->left == NULL && root->right == NULL) { 
            res += current*10 + root->val; 
        } else { 
            if (root->left) traverse(root->left, current*10 + root->val); 
            if (root->right) traverse(root->right, current*10 + root->val); 
        } 
    } 
     
public: 
    int sumNumbers(TreeNode *root) { 
        res = 0; 
        traverse(root, 0); 
        return res; 
    } 
}; 