// 141. Linked List Cycle

// Approach: If the linked list has a cycle then when we will traverse it using fast and slow pointers then the both pointers will points to same node once a while.

// TC: O(N)
// SC: O(1)

bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }
    return false;
}
