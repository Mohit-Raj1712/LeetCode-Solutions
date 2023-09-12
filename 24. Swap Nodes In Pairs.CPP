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
    ListNode* swapPairs(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* output = new ListNode(-1, head);
        ListNode* backup = output;
        
        while (output -> next != nullptr && output -> next -> next != nullptr)
        {
            ListNode* first_node = output -> next;
            ListNode* second_node = output -> next -> next;
            
            first_node -> next = second_node -> next;
            output -> next = second_node;
            output -> next -> next = first_node;
            
            output = output -> next -> next;
        }
        
        output = backup -> next;
        return output;
    }
};