// 2816. Double a Number Represented as a Linked List

class Solution {
public:
    // Approach:
    // Reverse
    // Multiply
    // add carry node
    // Reverse

    // TC: O(N)

    ListNode *reverseLinkedList(ListNode *head) {
        ListNode *curr = head, *prev = NULL, *next = head;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *doubleIt(ListNode *head) {
        ListNode *curr = head, *newHead = NULL, *next = head;
        newHead = reverseLinkedList(head);

        curr = newHead, head = newHead;
        int carry = 0;

        while (curr) {
            int val = (curr->val) * 2;
            curr->val = (val + carry) % 10;
            carry = (val + carry) / 10;
            newHead = curr;
            curr = curr->next;
        }

        if (carry) {
            ListNode *newNode = new ListNode(carry, NULL);
            newHead->next = newNode;
        }

        newHead = reverseLinkedList(head);
        return newHead;
    }
};