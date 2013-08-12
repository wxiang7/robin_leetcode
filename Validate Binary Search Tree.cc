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
    bool validate(TreeNode *root, int *min, int *max) { 
        if (root == NULL) { 
            return true; 
        } else { 
            int lmin = root->val, lmax = root->val; 
            if (root->left && (!validate(root->left, &lmin, &lmax) || lmax >= root->val)) return false; 
            *min = lmin; 
            int rmin = root->val, rmax = root->val; 
            if (root->right && (!validate(root->right, &rmin, &rmax) || rmin <= root->val)) return false; 
            *max = rmax; 
            return true; 
        } 
    } 
     
public: 
    bool isValidBST(TreeNode *root) { 
        int min, max; 
        return validate(root, &min, &max); 
    } 
};