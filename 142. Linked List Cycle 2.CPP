/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (head == nullptr || head -> next == nullptr)
            return nullptr;
        
        ListNode* fast_pointer = head;
        ListNode* slow_pointer = head;
        bool is_loop_present = false;
        
        while (fast_pointer -> next != nullptr && fast_pointer -> next -> next != nullptr)
        {
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
            
            if (fast_pointer == slow_pointer)
            {
                is_loop_present = true;
                break;
            }
        }
        
        if (is_loop_present == false)
            return nullptr;

        ListNode* node = head;
        
        while (node != slow_pointer)
        {
            node = node -> next;
            slow_pointer = slow_pointer -> next;
        }
        
        return node;
    }
};