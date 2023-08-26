#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next; 
    Node *tail; 
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

//
void Insertatposition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1 && temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void deletenode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;
    print(head);
    cout << "head"
         << " " << head->data << endl;
    cout << "tail"
         << " " << tail->data << endl;
   
    InsertAtTail(tail, 12);
    print(head);
    cout << "head"
         << " " << head->data << endl;
    cout << "tail"
         << " " << tail->data << endl;
    InsertAtTail(tail, 15);
    print(head);
    cout << "head"
         << " " << head->data << endl;
    cout << "tail"
         << " " << tail->data << endl;

    Insertatposition(tail, head, 2, 22);
    print(head);
    cout << "head"
         << " " << head->data << endl;
    cout << "tail"
         << " " << tail->data << endl;
    deletenode(3, head);
    print(head);
    cout << "head"
         << " " << head->data << endl;
    cout << "tail"
         << " " << tail->data << endl;
}
//OUTPUT
// 10 
// head 10
// tail 10
// 10 12
// head 10
// tail 12
// 10 12 15
// head 10
// tail 15
// 10 22 12 15 
// head 10
// tail 15
// 10 22 15
// head 10
// tail 15
