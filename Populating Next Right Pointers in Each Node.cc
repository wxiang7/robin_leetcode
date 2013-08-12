/** 
* Definition for binary tree with next pointer. 
* struct TreeLinkNode { 
*  int val; 
*  TreeLinkNode *left, *right, *next; 
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {} 
* }; 
*/ 
class Solution { 
public: 
    void connect(TreeLinkNode *root) { 
        if (root == NULL) return; 
        int len = 1; 
        TreeLinkNode *head = root, *ptr, *last; 
        while (head->left) { 
            ptr = head; 
            last = NULL; 
            for (int i = 0; i < len; ++i) { 
                if (last) last->right->next = ptr->left; 
                ptr->left->next = ptr->right; 
                last = ptr; 
                ptr = ptr->next; 
            } 
            head = head->left; 
            len <<= 1; 
        } 
    } 
}; 