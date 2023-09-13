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
    ListNode* sortList(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* list1 = head;
        ListNode* mid_node = middle_of_list(list1);
        ListNode* list2 = mid_node -> next;
        mid_node -> next = nullptr;
        
        return sort(sortList(list1), sortList(list2));
    }
    
private:
    ListNode* sort(ListNode* list1, ListNode* list2) {
        
        if (list1 == nullptr)
            return list2;
        
        if (list2 == nullptr)
            return list1;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* backup = dummy;
        
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1 -> val < list2 -> val)
            {
                dummy -> next = list1;
                list1 = list1 -> next;
            }
            else {
                
                dummy -> next = list2;
                list2 = list2 -> next;
            }
            
            dummy = dummy -> next;
        }
        
        dummy -> next = list1 != nullptr ? list1 : list2;
        return backup -> next;
    }
    
private:
    ListNode* middle_of_list(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* fast_pointer = head;
        ListNode* slow_pointer = head;
        
        while (fast_pointer -> next != nullptr && fast_pointer -> next -> next != nullptr) 
        {
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
        }
        
        return slow_pointer;
    }
};