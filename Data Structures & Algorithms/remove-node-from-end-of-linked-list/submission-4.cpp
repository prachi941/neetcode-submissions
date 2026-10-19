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

//2-pass approach 
//1st pass to count the number of nodes
//2nd pass to reach the node just before tar
//Also creation of dummy required here to handle the case for only 1 node

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode dummy(0);
        dummy.next = head;

        // Pass 1: Count nodes
        int count = 0;
        ListNode* curr = head;
        
        while(curr != NULL) {
            curr = curr->next;
            count++;
        }

        // Pass 2: Find the node before the target
        curr = &dummy;

        for(int i = 0; i < count - n; i++) {
            curr = curr->next;
        }

        //defining tar node
        ListNode* tar = curr->next;
        
         // Remove the target node by making curr->prev point to tar->next; here curr is the node just before the tar
         curr->next = tar->next;

        return dummy.next;
    }
};
