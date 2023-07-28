// 234. Palindrome Linked List
// SC: O(1)
// TC: O(N)
bool isPalindrome(ListNode *head)
{
    // Getting the Mid of the linked list O(N/2) => O(N)
    ListNode *fp = head, *sp = head;
    while (fp && fp->next)
    {
        fp = fp->next->next;
        sp = sp->next;
    }

    // Reverse the 2nd half of linked list O(N/2) => O(N)
    ListNode *prev = NULL, *next = NULL;
    while (sp)
    {
        next = sp->next;
        sp->next = prev;
        prev = sp;
        sp = next;
    }

    // sp is NULL and prev is pointing the last node after reversing the half
    // linked list.
    ListNode *newHead = prev;

    // Compairing val from end and start. O(N/2) => O(N)
    while (newHead)
    {
        if (head->val != newHead->val)
            return false;
        head = head->next;
        newHead = newHead->next;
    }
    return true;
}
