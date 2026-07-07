class Node {
public :
   int key;
   int value;
   
   Node* prev;
   Node* next;
   
   Node(int k, int v) {
      key = k;
      value = v;
      prev = NULL;
      next = NULL;
    
    }
};

class LRUCache {

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

public:

    LRUCache(int capacity) { 

        this -> capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head -> next = tail;
        tail -> prev = head;
    } 

    void removeNode(Node* node) {

        Node* previous = node -> prev;
        Node* forward = node -> next;

        previous -> next = forward;
        forward -> prev = previous;
    }

    void insertAfterHead(Node* node) {

        Node* first = head -> next;

        head -> next = node;
        node -> prev = head;

        node -> next = first;
        first -> prev = node;
    }
    
    int get(int key) { 

        if (mp.find(key) == mp.end()) 
           return -1;

        Node* node = mp[key];

        removeNode(node);
        insertAfterHead(node);

        return node -> value;
        
    }
    
    void put(int key, int value) { 

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node -> value = value;

            removeNode(node);
            insertAfterHead(node);

            return;
        }

        if(mp.size() == capacity) {

            Node* lru = tail -> prev;

            removeNode(lru);

            mp.erase(lru -> key);
        }

        Node* newNode = new Node(key, value);

        insertAfterHead(newNode);

        mp[key] = newNode;
        
    }
};
