// 203. Remove Linked List Elements

// Approach:
// Iterate over the Linkedlist and keep track of prev and curr.
// If curr is same as val then store that node address in tempNode and change prev node next to the current next and change the current to next.

// If current node value is not same as val then simply move the previous and the current node.

// TC: O(N)
// SC: O(1)
ListNode *removeElements(ListNode *head, int val)
{
    // leading values equal to val
    while (head && (head->val == val))
    {
        ListNode *tempNode = head;
        head = head->next;
        delete tempNode;
    }

    ListNode *prev = head, *curr = head;
    while (curr)
    {
        if (curr->val == val)
        {
            ListNode *tempNode = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete tempNode;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}