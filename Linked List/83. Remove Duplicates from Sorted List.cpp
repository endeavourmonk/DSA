// 83. Remove Duplicates from Sorted List

// TC: O(log N)
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        int data = head->val;
        head = head->next;
        ListNode *uniqueListHead = new ListNode(data);
        ListNode *uniqueListTail = uniqueListHead;
        while (head) {
            if (data != head->val) {
                ListNode *temp = new ListNode(head->val);
                uniqueListTail->next = temp;
                uniqueListTail = temp;
            }
            data = head->val;
            head = head->next;
        }
        return uniqueListHead;
    }
};