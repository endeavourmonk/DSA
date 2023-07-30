// 876. Middle of the Linked List

// Approact 1: First counting the total nodes by traversing then returning the ct/2 th node
// by again traversing.

// TC: O(N)

ListNode *middleNode(ListNode *head)
{
    int ct = 0;
    for (ListNode *ptr = head; ptr != NULL; ptr = ptr->next)
        ct++;
    int mid = ct / 2;
    ListNode *midNode = head;
    for (int i = 1; i <= mid; ++i)
        midNode = midNode->next;
    return midNode;
}

// Approach 2: Used two pointers fast which traverse 2 nodes at once and slow which traverse
// a node, whenever fast -> next becomes NULL, slow is at the middle of the linkedlist

// TC: O(N)
// SC: O(1)
ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}