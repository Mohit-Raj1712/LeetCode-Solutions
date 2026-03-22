class LRUCache {
private:

    class Node {
    public:
        int key, val;
        Node* previous;
        Node* next;

        Node(int key, int val)
        {
            this -> key = key;
            this -> val = val;
            this -> previous = this -> next = nullptr;
        }
    };

    Node* head;
    Node* tail;

    int capacity, size;
    unordered_map<int, Node*> lookup;

public:
    LRUCache(int capacity) {

        this -> size = 0;
        this -> capacity = capacity; 

        this -> head = new Node(0, 0);
        this -> tail = new Node(0, 0);

        head -> next = tail;
        tail -> previous = head;
    }
    
    int get(int key) {
        
        if (lookup.find(key) == lookup.end())
            return -1;
        
        int val = lookup[key] -> val;

        remove(lookup[key]);
        insert(new Node(key, val));

        return val;
    }
    
    void put(int key, int value) {
        
        if (lookup.find(key) != lookup.end())
            remove(lookup[key]);

        if (size >= capacity)
            remove(tail -> previous);
        
        insert(new Node(key, value));
    }

    void insert(Node* node) {

        lookup[node -> key] = node;
        size ++;

        node -> next = head -> next;
        head -> next -> previous = node;
        node -> previous = head;
        head -> next = node;

        return;
    }

    void remove(Node* node) {

        lookup.erase(node -> key);
        size --;

        node -> previous -> next = node -> next;
        node -> next -> previous = node -> previous;

        delete(node);

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */