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
        TreeLinkNode *head = root, *last, *next_head; 
        int count = 1; 
        while (count > 0) { 
            count = 0; 
            last = NULL; 
            while (head) { 
                if (head->left && head->right) { 
                    if (last) { 
                        last->next = head->left; 
                        head->left->next = head->right; 
                    } else { 
                        head->left->next = head->right; 
                        next_head = head->left; 
                    } 
                    count += 2; 
                    last = head->right; 
                } else if (head->left) { 
                    if (last) { 
                        last->next = head->left; 
                    } else { 
                        next_head = head->left; 
                    } 
                    count += 1; 
                    last = head->left; 
                } else if (head->right) { 
                    if (last) { 
                        last->next = head->right; 
                    } else { 
                        next_head = head->right; 
                    } 
                    count += 1; 
                    last = head->right; 
                } 
                head = head->next; 
            } 
            head = next_head; 
        } 
    } 
}; 