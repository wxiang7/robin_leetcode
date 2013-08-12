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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) { 
        int n = preorder.size(); 
        if (n == 0) return NULL; 
        TreeNode *root = new TreeNode(0); 
        queue<tuple<TreeNode*, int, int, int> > status; 
        status.push(make_tuple(root, 0, 0, n)); 
        while (!status.empty()) { 
            tuple<TreeNode*, int, int, int>& top = status.front(); 
            TreeNode* cur = std::get<0>(top); 
            int& ps = std::get<1>(top); 
            int& is = std::get<2>(top); 
            int& len = std::get<3>(top); 
            int offset = 0; 
            cur->val = preorder[ps]; 
            while (inorder[offset + is] != cur->val) ++offset;    
            if (offset > 0) { 
                cur->left = new TreeNode(0); 
                status.push(make_tuple(cur->left, ps+1, is, offset)); 
            } 
            if (len-1 > offset) { 
                cur->right = new TreeNode(0); 
                status.push(make_tuple(cur->right, ps+offset+1, is+offset+1, len-1-offset)); 
            } 
            status.pop(); 
        } 
        return root; 
    } 
}; 