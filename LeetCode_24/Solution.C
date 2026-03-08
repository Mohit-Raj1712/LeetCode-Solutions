/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* new_node(int val, struct ListNode* next_node);

struct ListNode* swapPairs(struct ListNode* head) {
    
    if (head == NULL || head -> next == NULL)
        return head;
    
    struct ListNode* dummy = new_node(-1, head);
    struct ListNode* node = dummy;

    while (node -> next != NULL && node -> next -> next != NULL)
    {
        struct ListNode* first_node = node -> next;
        struct ListNode* second_node = node -> next -> next;

        first_node -> next = second_node -> next;

        node -> next = second_node;
        node -> next -> next = first_node;
        
        node = node -> next -> next;
    }

    return head = dummy -> next;
}

struct ListNode* new_node(int val, struct ListNode* next_node) {

    struct ListNode* node = (struct ListNode*) malloc (sizeof(struct ListNode));
    node -> val = val;
    node -> next = next_node;

    return node;
}