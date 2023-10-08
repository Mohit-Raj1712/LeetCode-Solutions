class MyLinkedList {
private:
    
    class ListNode {
    public:
        int val;
        ListNode* next;

    public:
        ListNode(int val) {
        
            this -> val = val;
            this -> next = nullptr;
        }
    };
    
    int size;
    ListNode* head;
    
public:
    MyLinkedList() {
        
        this -> size = 0;
        this -> head = new ListNode(-1);
    }
    
    int get(int index) {
        
        if (index >= size)
            return -1;
        
        ListNode* node = head -> next;
        for (int i = 0; i < index; i++)
            node = node -> next;
        
        return node -> val;
    }
    
    void addAtHead(int val) {
        
        size ++;
        
        ListNode* node = head -> next;
        head -> next = new ListNode(val);
        head -> next -> next = node;
        
        return;
    }
    
    void addAtTail(int val) {
        
        size ++;
        
        ListNode* node = head;
        while (node -> next != nullptr)
            node = node -> next;
        
        node -> next = new ListNode(val);
        
        return;
    }
    
    void addAtIndex(int index, int val) {
        
        if (index > size)
            return;
        
        
        if (index == 0)
            return addAtHead(val);
        
        if (index == size)
            return addAtTail(val);
        
        ListNode* node = head;
        for (int i = 0; i < index; i++)
            node = node -> next;
        
        size ++;
        
        ListNode* temp = node -> next;
        node -> next = new ListNode(val);
        node -> next -> next = temp;
        
        return;
    }
    
    void deleteAtIndex(int index) {
        
        if (index >= size)
            return;
        
        size --;
        
        ListNode* node = head;
        for (int i = 0; i < index; i++)
            node = node -> next;
        
        ListNode* temp = node -> next;
        node -> next = temp -> next;
        temp -> next = nullptr;
        
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */