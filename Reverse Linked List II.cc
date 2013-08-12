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
    ListNode *reverseBetween(ListNode *head, int m, int n) { 
        ListNode pivot(0); 
        ListNode *first = &pivot 
               , *second 
               , *next 
               , *tmp; 
     
        pivot.next = head; 
        if (m < n) { 
            for (int i = 1; i < m; ++i) first = first->next; 
            second = first->next; 
            next = second->next; 
            for (int i = 0; i < n-m; ++i) { 
                tmp = next->next; 
                next->next = second; 
                if (i < n-m-1) { 
                    second = next; 
                    next = tmp; 
                } 
            } 
            second = first->next; 
            first->next = next; 
            second->next = tmp;    
        } 
 
 
        return pivot.next; 
    } 
}; 