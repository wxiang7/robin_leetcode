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
    ListNode *rotateRight(ListNode *head, int k) { 
        if (head == NULL || k == 0) return head; 
         
        ListNode pivot(0); 
        pivot.next = head; 
         
        ListNode *first = &pivot 
                ,*second = first; 
         
        int count = 0; 
        while (second->next) { 
            ++count; 
            second = second->next; 
        } 
        k = (k-1) % count + 1; 
         
        second = first; 
        while (second->next) { 
            second = second->next; 
            if (k > 0) { 
                --k; 
            } else { 
                first = first->next; 
            } 
        } 
         
        if (first != second && first != &pivot) { 
            second->next = head; 
            head = first->next; 
            first->next = NULL;     
        } 
         
        return head; 
    } 
}; 