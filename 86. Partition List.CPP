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
    ListNode* partition(ListNode* head, int x) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
    
        ListNode* list1 = new ListNode(-1); ListNode* backup_list1 = list1;
        ListNode* list2 = new ListNode(-1); ListNode* backup_list2 = list2;
        
        ListNode* node = head;
        
        while (node != nullptr)
        {
            if (node -> val < x)
            {
                list1 -> next = node;
                list1 = list1 -> next;
            }
            else {
                
                list2 -> next = node;
                list2 = list2 -> next;
            }
            
            node = node -> next;
        }
        
        list1 -> next = list2 -> next = nullptr;
        list1 -> next = backup_list2 -> next;
        
        head = backup_list1 -> next;
        
        return head;
    }
};