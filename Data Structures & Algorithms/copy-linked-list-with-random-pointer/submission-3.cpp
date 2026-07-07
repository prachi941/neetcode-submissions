/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// t.c. = O(3n)(3 traversals or 3 while loops)
// s.c. = O(n)
//Instead of using a hash map, we'll temporarily interleave the copied nodes with the original nodes.

class Solution {
public:
    Node* copyRandomList(Node* head) { 

        Node* temp = head;

        //Step 1: Insert copied nodes
        while(temp != NULL) {

            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = temp->next->next; //or copyNode->next;
        }

        temp = head;

        //Step 2: Assign random pointers
        while(temp != NULL) {

        Node* copyNode = temp->next;
        
           if(temp->random != NULL) {
            
            copyNode->random = temp->random->next;
           }

            temp = temp->next->next;
        }

        //Step 3: Separate the two lists
        Node* dnode = new Node(-1);
        Node* res = dnode;

        temp = head;

        while(temp != NULL) { 

            Node* copyNode = temp->next;
            
            res->next = temp->next;
            temp->next = temp->next->next;

            res = res->next;
            temp=temp->next;
        } 

        return dnode->next;
        
    }
};
