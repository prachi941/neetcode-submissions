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

        if(head == NULL || head->next == NULL){
            return;
        }
        
        // Find middle
        ListNode*slow = head;
        ListNode*fast = head;

        while(fast->next && fast->next->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* curr = slow->next; // similar to ListNode*curr = head; // slow->next is head of reversed LL
        slow->next = NULL;

        ListNode*prev = NULL;
        ListNode*next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Merge two halves
        ListNode*first = head;
        ListNode*sec = prev; // in reversing prev is the new head

        while(sec) {

            ListNode* t1 = first->next;
            ListNode* t2 = sec->next;

            first->next = sec;
            sec->next = t1;

            first = t1;
            sec = t2;
        }
    }
};