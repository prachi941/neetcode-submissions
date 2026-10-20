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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while(list1 != nullptr || list2 != nullptr || carry != 0) {

            int x = (list1 != nullptr) ? list1->val : 0;
            int y = (list2 != nullptr) ? list2->val : 0;

            int sum = x + y + carry;

            carry = sum / 10;
            int digit = sum % 10;

            curr->next = new ListNode(digit);
            curr = curr->next;

            if(list1 != nullptr) {
                list1 = list1->next;
            } 

            if(list2 != nullptr) {
                list2 = list2->next;
            }
        }

        return dummy.next;
    }
};
