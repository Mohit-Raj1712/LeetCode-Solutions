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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        
        
        ListNode* output = new ListNode(-1);
        ListNode* backup = output;
        
        int carry = 0;
        
        while (list1 != nullptr || list2 != nullptr || carry != 0)
        {
            int val1 = list1 != nullptr ? list1 -> val : 0;
            int val2 = list2 != nullptr ? list2 -> val : 0;
            
            
            int sum = val1 + val2 + carry;
            int val = sum % 10;
            carry = sum / 10;
            
            output -> next = new ListNode(val);
            output = output -> next;
            
            if (list1 != nullptr)
                list1 = list1 -> next; 
            
            if (list2 != nullptr)
                list2 = list2 -> next;
        }
        
        output = backup -> next;
        return output;
    }
};