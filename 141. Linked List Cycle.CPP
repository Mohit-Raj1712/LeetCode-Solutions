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
    bool hasCycle(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return false;
        
        ListNode* fast_pointer = head;
        ListNode* slow_pointer = head;
        
        while (fast_pointer -> next != nullptr && fast_pointer -> next -> next != nullptr)
        {
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
            
            if (fast_pointer == slow_pointer)
                return true;
        }
        
        return false;
    }
};