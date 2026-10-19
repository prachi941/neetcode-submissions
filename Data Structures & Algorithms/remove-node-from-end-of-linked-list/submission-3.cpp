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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        int count = 0;
        ListNode* curr = head;
        
        while(curr != NULL) {
            curr = curr->next;
            count++;
        }

        curr = &dummy;

        for(int i = 0; i < count - n; i++) {
            curr = curr->next;
        }

        ListNode* tar = curr->next;
        
        curr->next = tar->next;

        return dummy.next;
    }
};
