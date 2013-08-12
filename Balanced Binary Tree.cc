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
    bool checkBalanced(TreeNode *root, int *height) { 
        if (root == NULL) { 
            *height = 0; 
            return true; 
        } else { 
            int left, right; 
            if (!checkBalanced(root->left, &left) || !checkBalanced(root->right, &right)) { 
                return false; 
            } else { 
                if (abs(left-right) <= 1) { 
                    *height = std::max(left, right) + 1; 
                    return true; 
                } else { 
                    return false; 
                } 
            } 
        } 
    } 
 
 
public: 
    bool isBalanced(TreeNode *root) { 
        int height; 
        return checkBalanced(root, &height); 
    } 
}; 