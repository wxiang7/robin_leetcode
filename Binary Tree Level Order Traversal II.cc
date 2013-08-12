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
    vector<vector<int> > levelOrderBottom(TreeNode *root) { 
        vector<vector<int> > res; 
        if (root == NULL) return res; 
        vector<TreeNode*> level[2]; 
        bool last = false, current; 
        level[0].push_back(root); 
        while (!level[last].empty()) { 
            current = !last; 
            level[current].clear(); 
            vector<int> add; 
            add.reserve(level[last].size()); 
            for (auto& node : level[last]) { 
                add.push_back(node->val); 
                if (node->left) level[current].push_back(node->left); 
                if (node->right) level[current].push_back(node->right); 
            } 
            res.push_back(add); 
            last = current; 
        } 
        std::reverse(res.begin(), res.end()); 
        return res; 
    } 
}; 