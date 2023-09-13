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
    ListNode* insertionSortList(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* dummy = new ListNode(-1, head);
        
        ListNode* previous_pointer = head;
        ListNode* current_pointer = head -> next;
        
        while (current_pointer != nullptr)
        {
            if (previous_pointer -> val <= current_pointer -> val)
            {
                previous_pointer = current_pointer;
                current_pointer = current_pointer -> next;
                continue;
            }
            
            ListNode* temp = dummy;
            
            while (temp -> next -> val < current_pointer -> val)
                temp = temp -> next;
            
            previous_pointer -> next = current_pointer -> next;
            current_pointer -> next = temp -> next;
            temp -> next = current_pointer;
            
            current_pointer = previous_pointer -> next;
        }
        
        head = dummy -> next;
        return head;
    }
};