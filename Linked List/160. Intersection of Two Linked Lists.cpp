// 160. Intersection of Two Linked Lists

// Intuition: Find the intersection node(not value) of two linked List.

// Approach:
// Used two pointers l1 and l2 to keep track of the both linked list.
// if the both node's address is same we found intersection otherwise keep iterating the both linked list till we found the intersection.
// l1 is initially at headA and l2 at headB.
// suppose if a linked list is smaller then we reached to the NULL (len(l1) - len(l2)) before.
// So, change the l1 to the headB and after (len(l1) - len(l2)) iterations change the l2 to headA now both l1 and l2 are pointing to the both nodes paralally.
// Now while loop runs until found intersection node or both NULL.

// TC: O(N)
// SC: O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2) {
        l1 = l1 ? l1->next : headB;
        l2 = l2 ? l2->next : headA;
    }
    return l1;
}