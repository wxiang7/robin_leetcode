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
    int minDepth(TreeNode *root) { 
        if (root == NULL) return 0; 
        int min_depth = numeric_limits<int>::max(); 
        queue<pair<TreeNode*, int> > status; 
        status.push(make_pair(root, 1)); 
        while (!status.empty()) { 
            pair<TreeNode*, int>& front = status.front(); 
            TreeNode* node = front.first; 
            int depth = front.second; 
            if (node->left == NULL && node->right == NULL) { 
                min_depth = std::min(depth, min_depth); 
            } else { 
                if (node->left) status.push(make_pair(node->left, depth+1)); 
                if (node->right) status.push(make_pair(node->right, depth+1)); 
            } 
            status.pop(); 
        } 
        return min_depth; 
    } 
}; 