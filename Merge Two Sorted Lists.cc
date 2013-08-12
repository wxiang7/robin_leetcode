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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) { 
        ListNode pivot(0), *head = &pivot; 
        while (l1 || l2) { 
            if (l1 == NULL || (l2 && l2->val < l1->val)) { 
                head->next = l2; 
                l2 = l2->next; 
                head->next->next = NULL; 
            } else { 
                head->next = l1; 
                l1 = l1->next; 
                head->next->next = NULL; 
            } 
            head = head->next; 
        } 
        return pivot.next; 
    } 
};