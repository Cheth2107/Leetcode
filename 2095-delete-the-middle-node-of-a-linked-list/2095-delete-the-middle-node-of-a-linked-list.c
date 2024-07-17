
 //Definition for singly-linked list.
 // struct ListNode {
 //     int val;
 //     struct ListNode *next;
 // };
int countofnodes(struct ListNode* head) {
    int count = 0;
    while (head != NULL) { // Fixed the loop condition
        head = head->next;
        count++;
    }
    return count;
}

// Function to delete the middle node of the linked list
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL; // Corrected the return statement after freeing the node
    }

    int count = countofnodes(head);
    int mid = count / 2;

    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    for (int i = 0; i < mid; i++) {
        prev = current;
        current = current->next;
    }

    // prev->next should skip the middle node
    prev->next = current->next;
    free(current); // Free the middle node

    return head;
}