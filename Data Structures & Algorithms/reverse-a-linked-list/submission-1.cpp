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
    ListNode* reverseList(ListNode* head) { 

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL; 

    while(curr != NULL) { 

        //for preserving further connected nodes; so we don't lose them after arranging the connections 
        next = curr -> next;

        //reversing connections
        curr -> next = prev;

        //for further iterations
        prev = curr;
        curr = next;

       }

       return prev; // new head
    }
    
};
