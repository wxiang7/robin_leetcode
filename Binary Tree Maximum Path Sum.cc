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
    int max_sum; 
    int singlePathSum(TreeNode *root) { 
        if (root == NULL) return 0; 
        int left = singlePathSum(root->left) 
          , right = singlePathSum(root->right); 
        max_sum = max(max_sum, root->val + left + right); 
        return max(0, max(root->val+right, root->val+left)); 
    } 
     
public: 
    int maxPathSum(TreeNode *root) { 
        max_sum = numeric_limits<int>::min(); 
        singlePathSum(root); 
        return max_sum; 
    } 
};