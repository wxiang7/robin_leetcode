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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) { 
        int n = inorder.size(); 
        if (n == 0) return NULL; 
        TreeNode* root = new TreeNode(0); 
        queue<tuple<TreeNode*, int, int, int> > status; 
        status.push(make_tuple(root, 0, 0, n)); 
        while (!status.empty()) { 
            tuple<TreeNode*, int, int, int>& front = status.front(); 
            TreeNode* cur = std::get<0>(front); 
            int is = std::get<1>(front); 
            int ps = std::get<2>(front); 
            int len = std::get<3>(front); 
            int offset = 0; 
            cur->val = postorder[ps+len-1]; 
            while (inorder[offset+is] != cur->val) ++offset; 
            if (offset > 0) { 
                cur->left = new TreeNode(0); 
                status.push(make_tuple(cur->left, is, ps, offset)); 
            } 
            if (len-1 > offset) { 
                cur->right = new TreeNode(0); 
                status.push(make_tuple(cur->right, is+offset+1, ps+offset, len-1-offset)); 
            } 
            status.pop(); 
        } 
        return root; 
    } 
}; 