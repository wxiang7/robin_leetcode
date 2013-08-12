/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    inline ListNode *seekAndReverse(ListNode* pivot, int k, bool check_k) {
        if (pivot->next == NULL || pivot->next->next == NULL)
            return NULL;
        
        int counter = k;
        ListNode *next = pivot->next, *nnext = next->next, *tmp, *onext = next;
        while ((--counter) > 0 && next && nnext) {
            tmp = nnext->next;
            nnext->next = next;
            pivot->next = nnext;
            next = nnext;
            nnext = tmp;
        }
        onext->next = nnext;
        
        if (check_k && counter > 0) {
            seekAndReverse(pivot, k, false);
            onext = NULL;
        }
        
        return onext;
    }
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) {
            return head;
        }
        
        ListNode pivot(0), *pivot_ptr = &pivot;
        pivot.next = head;
        while (pivot_ptr) {
            pivot_ptr = seekAndReverse(pivot_ptr, k, true);
        }
        
        return pivot.next;
    }
};
