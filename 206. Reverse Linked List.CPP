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

// Recursive Approach

class Solution {
private:
    ListNode* backup;
    
public:
    ListNode* reverseList(ListNode* head) {
        
        reverse(head);
        
        head -> next = nullptr;
        return backup;
    }
    
private:
    void reverse(ListNode* head) {
        
        if (head -> next == nullptr)
        {
            backup = head;
            return;
        }
        
        head -> next = reverse(head -> next);
        head -> next -> next = head;
        
    }
};

// Iterative Approach


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode *forward = nullptr;
        ListNode *previous = nullptr;
        ListNode *current = head;
        
        while(current != nullptr) 
        {
            forward = current -> next;
            current -> next = previous;
            
            previous = current;
            current = forward;
        }
        
        return head = previous;
    }
};