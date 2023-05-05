#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    Node() {
        this->data = 0;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data) {
    Node *temp = new Node(0);
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data) {
    Node *temp = new Node(data);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void insertAtPosition(Node *&head, int data, int pos) {
    Node *ptr = head;
    if (!head)
        return;
    if (pos == 1) {
        insertAtHead(head, data);
        return;
    }
    for (int i = 1; i < pos - 1; ++i) {
        if (!ptr) 
            return;
        ptr = ptr->next;
    }
    Node *temp = new Node(data);
    temp->next = ptr->next;
    ptr->next = temp;
    
}

void deleteNodeByData(Node * &head, int data) {
    if(!head) 
        return; 
    for (Node *it = head; it != NULL; it = it->next) {
        
    }
}

void print(Node *&head) {
    for (auto it = head; it != NULL; it = it->next)
        cout << it->data << " ";
    cout << endl;
}

int main() {
    Node *head = new Node();
    Node *tail = head;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    print(head);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    print(head);
    insertAtPosition(head, 5, 5);
    print(head);
    return 0;
}