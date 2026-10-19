/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = l2;
        ListNode* next = NULL;
        
        while(curr != NULL) {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
        }

        l2 = prev;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 != nullptr && l2 != nullptr) {

            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;
            
            tail->next = l1;
            tail = tail->next;

            tail->next = l2;
            tail = tail->next;

            l1 = next1;
            l2 = next2;

        }

        if(l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
    }
};
