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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return head;
        ListNode *first = head, *second = head;
        int counter = 1;
        while (second->next) {
            if (counter > n) {
                first = first->next;
            }
            second = second->next;
            counter++;
        }
        
        if (counter == n) { // remove head
            first = head->next;
            delete head;
            return first;
        } else if (counter > n) {
            second = first->next->next;
            delete first->next;
            first->next = second;
            return head;
        }
    }
};