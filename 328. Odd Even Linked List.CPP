class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* even_list = head;
        ListNode* odd_list = head -> next;
        ListNode* backup = odd_list;
        
        while(even_list -> next != nullptr && odd_list -> next != nullptr)
        {
            even_list -> next = odd_list -> next;
            even_list = even_list -> next;
            
            odd_list -> next = even_list -> next;
            odd_list = odd_list -> next;
        }
        
        even_list -> next = backup;
        
        return head;
    }
};