#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(0);
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void print(Node *&head)
{
    for (auto it = head; it != NULL; it = it->next)
        cout << it->data << " ";
    cout << endl;
}

int main()
{
    Node *head = new Node();
    Node *tail = head;
    insertAtHead(head, 32);
    insertAtHead(head, 36);
    print(head);
    insertAtTail(tail, 40);
    insertAtTail(tail, 500);
    print(head);
    return 0;
}