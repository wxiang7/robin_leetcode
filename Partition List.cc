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
    ListNode *partition(ListNode *head, int x) { 
        ListNode left_pivot(0) 
               , right_pivot(0); 
        ListNode *left = &left_pivot 
               , *right = &right_pivot; 
        while (head) { 
            if (head->val < x) { 
                left->next = head; 
                head = head->next; 
                left = left->next; 
                left->next = NULL; 
            } else { 
                right->next = head; 
                head = head->next; 
                right = right->next; 
                right->next = NULL; 
            } 
        } 
        left->next = right_pivot.next; 
        return left_pivot.next; 
    } 
};