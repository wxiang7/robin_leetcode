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
    TreeNode *sortedArrayToBST(vector<int> &num, int from, int to) { 
        if (from > to) return NULL; 
        int mid = (from + to) / 2; 
        TreeNode *res = new TreeNode(num[mid]); 
        res->left = sortedArrayToBST(num, from, mid-1); 
        res->right = sortedArrayToBST(num, mid+1, to); 
        return res; 
    } 
     
public: 
    TreeNode *sortedArrayToBST(vector<int> &num) { 
        int n = num.size(); 
        return sortedArrayToBST(num, 0, n-1); 
    } 
}; 