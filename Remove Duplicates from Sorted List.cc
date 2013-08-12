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
              , *next; 
        int current = 0; 
        pivot.next = head; 
        head = ptr; 
        while (ptr->next != NULL) { 
            next = ptr->next; 
            int val = next->val; 
            if (ptr == &pivot || val != current) { // new node 
                current = val; 
                head->next = next; 
                ptr = next; 
                head = next; 
            } else { // delete node 
                head->next = next->next; 
                ptr = head; 
                delete next; 
            } 
        } 
        return pivot.next; 
    } 
};