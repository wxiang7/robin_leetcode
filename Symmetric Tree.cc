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
    bool isSymmetric(TreeNode *root) { 
        if (root == NULL) return true; 
        int depth = 0; 
        stack<tuple<TreeNode*, TreeNode*, int> > status; 
         
        status.push(make_tuple(root, root, 0)); 
        while (depth >= 0) { 
            TreeNode *left, *right; 
            tuple<TreeNode*, TreeNode*, int>& top = status.top(); 
            int step = std::get<2>(top); 
            if (step == 3) { 
                status.pop(); 
                --depth; 
            } else { 
                left = std::get<0>(top); 
                right = std::get<1>(top); 
                TreeNode *lnext, *rnext; 
                std::get<2>(top) += 1; 
                if (step == 0 || step == 2) { 
                    lnext = step == 0 ? left->left : left->right; 
                    rnext = step == 0 ? right->right : right->left; 
                    if (lnext == NULL && rnext == NULL) { 
                        continue; 
                    } else if (lnext == NULL || rnext == NULL  
                            || lnext->val != rnext->val) { 
                        return false; 
                    } else { 
                        ++depth; 
                        status.push(make_tuple(lnext, rnext, 0)); 
                    } 
                } 
            } 
        } 
        return true; 
    } 
};