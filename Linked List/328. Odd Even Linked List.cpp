// 328. Odd Even Linked List

// Approach:
// Store oddhead which is the head(first node) and the evenHead which is the second node of the original linkedlist.
// Then traverse the linkedlist till the even or even's next is not NULL, and change the next of odd to even's next and update odd pointer.
// Again change the next of the even's node to the odd's next and update the even pointer.
// Now you have two broken linkedlist one with odd and even node now update the odd's next with the priviously stored second node which is the even node.

// TC: O(N)
// SC: O(1)

ListNode *oddEvenList(ListNode *head) {
    if (!head)
        return head;

    ListNode *odd = head, *even = head->next, *evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = even->next;
        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenHead;
    return head;
}