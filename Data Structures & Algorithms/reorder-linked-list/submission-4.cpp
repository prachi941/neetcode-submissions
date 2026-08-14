class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == NULL || head -> next == NULL) {
            return;
        }
        
        //find middle point/ breakpoint
        //reverse second half
        //merge the two formed ll alternately

        //step 1
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL) {

            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //by this time slow will be pointing to middle node

        ListNode* second = slow -> next; // new second half LL
        slow -> next = NULL; // ending first half LL


        //step 2
        ListNode* prev = NULL;
        ListNode* curr = second;
        ListNode* next = NULL;

        while(curr != NULL ) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        second = prev; // head of reversed second half

        //step 3
        ListNode* first = head;

        while(second != NULL) {

            ListNode* firstNext = first -> next;
            ListNode* secondNext = second -> next;

            first -> next = second;
            second -> next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};
