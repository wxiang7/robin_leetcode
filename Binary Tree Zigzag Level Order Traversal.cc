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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) { 
        vector<vector<int> > res;  
        if (root == NULL) return res;  
        vector<TreeNode*> level[2];  
        bool last = false;  
        level[0].push_back(root);  
        while (level[last].size()) {  
            bool current = !last;   
            level[current].clear();  
            for (auto& node : level[last]) {   
                if (node->left) {  
                    level[current].push_back(node->left);  
                }  
                if (node->right) {  
                    level[current].push_back(node->right);  
                }  
            } 
            vector<int> add;  
            add.reserve(level[last].size()); 
            if (current) { 
                for (vector<TreeNode*>::iterator it = level[last].begin(); 
                    it != level[last].end(); ++it) { 
                    add.push_back((*it)->val);     
                } 
            } else { 
                for (vector<TreeNode*>::reverse_iterator it = level[last].rbegin(); 
                    it != level[last].rend(); ++it) { 
                    add.push_back((*it)->val);     
                } 
            } 
            res.push_back(add);  
            last = current;  
        }  
        return res;  
    } 
};