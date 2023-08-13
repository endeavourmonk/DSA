#include <iostream>

using namespace std;
class node {
public:
    int data;
    node *next;

    node(int val) {
        data = val;
    }
};

void print(node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node *head = new node(1);
    node *second = new node(2);
    head->next = second;
    print(head);

    cout << "head -> " << head << endl;
    cout << "head data -> " << &(head->data) << endl;
    cout << "head next -> " << (head->next) << endl
         << endl;

    cout << "next node -> " << (second) << endl;
    cout << "next data -> " << &(second->data) << endl;

    cout << "\n"
         << "after:" << endl
         << "\n";
    *head = *second;
    cout << "head -> " << head << endl;
    cout << "head data -> " << &(head->data) << endl;
    cout << "head next -> " << (head->next) << endl
         << endl;
    cout << "head data -> " << (head->data) << endl;
    return 0;
}
