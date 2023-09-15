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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* dummy = new ListNode(-1, head);
        ListNode* previous = dummy;
        ListNode* current  = head;
        
        while (current -> next != nullptr)
        {
            bool flag = true;
            while (current -> next != nullptr && previous -> next -> val == current -> next -> val)
            {
                flag = false;
                current = current -> next;
            }
            
            if (!flag) 
                previous -> next = current -> next;
            else
                previous = previous -> next;
            
            if (current -> next != nullptr)
                current = current -> next;
        }
        
        head = dummy -> next;
        return head;
    }
};