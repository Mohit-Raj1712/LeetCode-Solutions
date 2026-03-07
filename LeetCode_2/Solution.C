/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* create_node(int val);

struct ListNode* addTwoNumbers(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode* head = create_node(-1);
    struct ListNode* backup = head;
    int carry = 0;

    while (list1 != NULL || list2 != NULL || carry != 0)
    {
        int val1 = list1 != NULL ? list1 -> val : 0;
        int val2 = list2 != NULL ? list2 -> val : 0;
        int sum = val1 + val2 + carry;

        int val = sum % 10;
        carry = sum / 10;

        struct ListNode* node = create_node(val);
        head -> next = node;
        head = head -> next;

        if (list1 != NULL)
            list1 = list1 -> next;
        
        if (list2 != NULL)
            list2 = list2 -> next;
    }

    head = backup -> next;
    backup -> next = NULL;
    free(backup);

    return head;
}

struct ListNode* create_node(int val) {

    struct ListNode* node = (struct ListNode*) malloc (sizeof(struct ListNode));
    node -> val  = val;
    node -> next = NULL;

    return node;
}