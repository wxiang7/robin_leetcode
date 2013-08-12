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
    TreeNode* flat(TreeNode *root) { 
        if (root == NULL) return NULL; 
        TreeNode* last = root; 
        if (root->left) { 
            last = flat(root->left); 
            last->right = root->right; 
            root->right = root->left; 
            root->left = NULL; 
        } 
        if (last->right) { 
            return flat(last->right); 
        } else { 
            return last; 
        } 
    } 
     
public: 
    void flatten(TreeNode *root) { 
        flat(root); 
    } 
};