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
    int reported; 
    pair<TreeNode*, TreeNode*> abnormal[2]; 
    void traverse(TreeNode* mid, TreeNode* &pre) { 
        if (mid->left) traverse(mid->left, pre); 
        if (pre && pre->val > mid->val) 
            abnormal[reported++] = make_pair(pre, mid); 
        pre = mid; 
        if (mid->right) traverse(mid->right, pre); 
    } 
     
public: 
    void recoverTree(TreeNode *root) { 
        reported = 0; 
        TreeNode* pre = NULL; 
        traverse(root, pre); 
        TreeNode *first, *second; 
        if (reported == 1) { 
            first = abnormal[0].first; 
            second = abnormal[0].second; 
        } else { 
            first = abnormal[0].first; 
            second = abnormal[1].second; 
        } 
        int tmp = first->val; 
        first->val = second->val; 
        second->val = tmp; 
    } 
};