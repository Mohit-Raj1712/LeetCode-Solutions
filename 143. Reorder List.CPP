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
    void reorderList(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return;
        
        ListNode* list1 = head;
        ListNode* mid = find_mid(list1);
        ListNode* list2 = mid -> next;
        mid -> next = nullptr;

        list2 = reverse(list2);

        while (list1 != nullptr && list2 != nullptr)
        {
            ListNode* list1_next_node = list1 -> next;
            ListNode* list2_next_node = list2 -> next;

            list1 -> next = list2;
            list2 -> next = list1_next_node;

            list1 = list1_next_node;
            list2 = list2_next_node;
        }

        return;
    }
private:
    ListNode* find_mid(ListNode* head) {

        ListNode* fast_pointer = head;
        ListNode* slow_pointer = head;

        while (fast_pointer -> next != nullptr && fast_pointer -> next -> next != nullptr)
        {
            fast_pointer = fast_pointer -> next -> next;
            slow_pointer = slow_pointer -> next;
        }

        return slow_pointer;
    }

private:
    ListNode* reverse(ListNode* head) {

        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* current_node = head;
        ListNode* previous_node = nullptr;
        ListNode* forward_node = nullptr;

        while (current_node != nullptr)
        {
            forward_node = current_node -> next;
            current_node -> next = previous_node;

            previous_node = current_node;
            current_node = forward_node;
        }

        return previous_node;
    }

};