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
    ListNode *getIntersectionNode(ListNode* A, ListNode* B) {
        
        if (A == nullptr || B == nullptr)
            return nullptr;
        
        ListNode* list1 = A;
        ListNode* list2 = B;
        
        while (list1 != list2)
        {
            list1 = list1 == nullptr ? B : list1 -> next;
            list2 = list2 == nullptr ? A : list2 -> next;
        }
        
        return list1;
    }
};