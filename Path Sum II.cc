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
    vector<vector<int> > res; 
    vector<int> current; 
     
    void checkPathSum(TreeNode *root, int sum) { 
        if (root != NULL) { 
            if (root->left == NULL && root->right == NULL && sum == root->val) { 
                current.push_back(root->val); 
                res.push_back(current); 
                current.pop_back(); 
            } else { 
                current.push_back(root->val); 
                if (root->left) checkPathSum(root->left, sum - root->val); 
                if (root->right) checkPathSum(root->right, sum - root->val); 
                current.pop_back(); 
            } 
        } 
    } 
     
public: 
    vector<vector<int> > pathSum(TreeNode *root, int sum) { 
        res.clear(); 
        current.clear(); 
        checkPathSum(root, sum); 
        return res; 
    } 
};