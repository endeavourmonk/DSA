// 206. Reverse Linked List

// Approach: Traversing and changing the previous node's next to the newHead which is initially NULL and incrementing the head to the next node.

// TC: O(N)
// SC: O(1)
ListNode *reverseList(ListNode *head)
{
    ListNode *nextNode, *newHead = NULL;
    while (head)
    {
        nextNode = head->next;
        head->next = newHead;
        newHead = head;
        head = nextNode;
    }
    return newHead;
}