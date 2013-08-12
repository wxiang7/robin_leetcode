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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode pivot(0);
        pivot.next = head;
        
        ListNode *first = &pivot, *second = first->next, *next, *tmp;
        while (first->next && second->next) {
            next = second->next;
            first->next = next;
            second->next = next->next;
            next->next = second;
            first = second;
            second = first->next;
        };
        
        return pivot.next;
    }
};
