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
    vector<TreeNode *> generate(int from, int n) { 
        vector<TreeNode *> res; 
        if (n == 0) { 
            res.push_back(NULL); 
        } else { 
            for (int i = 1; i <= n; ++i) { 
                vector<TreeNode *> left = generate(from, i-1); 
                vector<TreeNode *> right = generate(from+i, n-i); 
                for (auto& lp : left) { 
                    for (auto& rp : right) { 
                        TreeNode* node = new TreeNode(from+i-1); 
                        node->left = lp; 
                        node->right = rp; 
                        res.push_back(node); 
                    } 
                } 
            } 
        } 
        return res; 
    } 
     
public: 
    vector<TreeNode *> generateTrees(int n) { 
        return generate(1, n); 
    } 
}; 