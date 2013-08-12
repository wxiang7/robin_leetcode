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
    ListNode *deleteDuplicates(ListNode *head) {  
        ListNode pivot(0)   
              , *ptr = &pivot   
              , *check = NULL  
              , *next 
              , *tmp; 
        bool is_dup = false; 
        pivot.next = head; 
        while (ptr->next != NULL) {   
            next = ptr->next;   
            int val = next->val;   
            if (check == NULL || val != check->next->val) { // new node 
                if (is_dup) { 
                    tmp = check->next; 
                    check->next = tmp->next; 
                    delete tmp; 
                    is_dup = false; 
                } else { 
                    check = ptr; 
                } 
                ptr = next; 
            } else { // delete dup ptr->next node   
                is_dup = true; 
                ptr->next = next->next; 
                delete next;   
            }   
        }   
        if (is_dup) { 
            tmp = check->next; 
            check->next = tmp->next; 
            delete tmp; 
        } 
        return pivot.next;  
    }  
};