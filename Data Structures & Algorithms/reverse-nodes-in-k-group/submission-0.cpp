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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* prevGroupTail = dummy;

        while(true) {

            ListNode* kth = prevGroupTail;

            for(int i = 0; i < k; i++) {

                kth = kth -> next;

                if(kth == NULL) {
                    return dummy -> next;
                }
            }

            ListNode* groupHead = prevGroupTail -> next;
            ListNode* nextGroupHead = kth -> next;

            ListNode* prev = nextGroupHead;
            ListNode* curr = groupHead;

            while(curr != nextGroupHead) {

                ListNode* next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupTail -> next = kth;

            prevGroupTail = groupHead;
        }
        
        return dummy -> next;
    }
};
