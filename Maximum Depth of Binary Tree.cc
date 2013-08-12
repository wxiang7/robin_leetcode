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
    int maxDepth(TreeNode *root) { 
        if (root == NULL) return 0;  
        int depth = 1, max_depth = 0;  
        stack<pair<TreeNode*, int> > status; 
        status.push(make_pair(root, 0));  
        while (depth > 0) {  
            max_depth = std::max(max_depth, depth); 
            pair<TreeNode*, int>& top = status.top();  
            TreeNode *node;  
            int& step = std::get<1>(top);  
            if (step == 3) {  
                status.pop();  
                --depth;  
            } else {  
                node = std::get<0>(top);  
                TreeNode *next;  
                step += 1;  
                if (step == 1 || step == 3) {  
                    next = step == 1 ? node->left : node->right;   
                    if (next != NULL) {  
                        ++depth; 
                        status.push(make_pair(next, 0));  
                    }  
                }  
            }  
        }  
        return max_depth; 
    } 
};