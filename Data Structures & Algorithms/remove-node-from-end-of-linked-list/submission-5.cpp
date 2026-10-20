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



//one pass approach
//Done using slow-fast pointers
//first we advance fast pointer to given n steps ahead starting from dummy node
//then until fast not reaches last node we advance both slow and fast one step at a time 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};
