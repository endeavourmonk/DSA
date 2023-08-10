// 237. Delete Node in a Linked List

// Approach: Just iterate over the Linkedlist and look if the node is the 2nd last node then change the value to the next node's value and delete the last node. otherwise just change the value.

// TC: O(N)
// SC: O(1)

// Assuming multiple nodes with similar value exist
void deleteNode(ListNode *node)
{
    while (node->next)
    {
        if (!node->next->next)
        {
            node->val = node->next->val;
            ListNode *temp = node->next;
            node->next = nullptr;
            delete temp;
            return;
        }
        else
        {
            node->val = node->next->val;
            node = node->next;
        }
    }
}

// All nodes are unique
// TC: O(1)
// SC: O(1)
void deleteNode(ListNode *node)
{
    ListNode *nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    delete nextNode;
}