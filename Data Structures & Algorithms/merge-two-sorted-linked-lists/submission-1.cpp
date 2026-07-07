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

// tc O(n1 + n2)
// sc O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { 

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
       

        ListNode* dnode = new ListNode(-1); // dummy node
        ListNode* temp = dnode;

        while(temp1 != nullptr && temp2 != nullptr) {

            if(temp1->val < temp2->val){

                temp -> next = temp1;
                temp = temp1;
                temp1 = temp1 -> next;
            }
            else { 
                temp -> next = temp2;
                temp = temp2;
                temp2 = temp2 -> next;
            } 
        
        }

            if(temp1) { 
                temp -> next = temp1;

            } 
             else {

                temp -> next = temp2;
             }

        return dnode -> next; // head of merged LL        
    }
};
