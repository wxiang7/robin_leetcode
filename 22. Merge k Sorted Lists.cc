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
    ListNode *mergeTwoLists(ListNode* list_a, ListNode* list_b) {
        ListNode *pivot = new ListNode(0), *ptr = pivot;
        while (list_a != NULL || list_b != NULL) {
            if (list_a == NULL || (list_a != NULL && list_b != NULL && list_a->val > list_b->val)) {
                ptr->next = list_b;
                list_b = list_b->next;
                ptr = ptr->next;
                ptr->next = NULL;
            } else if (list_b == NULL || (list_a != NULL && list_b != NULL && list_a->val <= list_b->val)) {
                ptr->next = list_a;
                list_a = list_a->next;
                ptr = ptr->next;
                ptr->next = NULL;
            }
        }
        ptr = pivot->next;
        delete pivot;
        return ptr;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return NULL;
        } else if (lists.size() == 1) {
            return lists[0];
        } else {
            int half = lists.size() / 2;
            vector<ListNode*> left, right;
            for (int i = 0; i < half; ++i) {
                left.push_back(lists[i]);
                right.push_back(lists[i+half]);
            }
            ListNode* left_list = mergeKLists(left);
            ListNode* right_list = mergeKLists(right);
            ListNode* merged = mergeTwoLists(left_list, right_list);
            if (lists.size() % 2 == 1)
              merged = mergeTwoLists(merged, lists[lists.size()-1]);
            return merged;
        }
    }
};

