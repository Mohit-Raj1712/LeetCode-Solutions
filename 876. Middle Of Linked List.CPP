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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* Fast_Pointer = head;
        ListNode* Slow_Pointer = head;
        
        while(true) {
            
            if(Fast_Pointer -> next == nullptr)
                break;
            
            if(Fast_Pointer -> next != nullptr && Fast_Pointer -> next -> next == nullptr)
                return Slow_Pointer -> next;
            
            Slow_Pointer = Slow_Pointer -> next;
            Fast_Pointer = Fast_Pointer -> next -> next;
        }
        
        return Slow_Pointer;
    }
};