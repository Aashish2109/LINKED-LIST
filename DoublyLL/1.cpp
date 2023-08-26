#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value=this->data;
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head,tail, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head,tail, data);
        return;
    }
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deletenode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev=NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
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
        curr->prev=NULL;
        delete curr;
    }
} 
int length(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
int main()
{
     Node *node = new Node(10);
    // cout<<node->data;
    // cout<<(*node).data;
    // Node *head = NULL; //If this then the position where to insert should be checked carefully
    // Node *tail = NULL;

    Node *head = node;
    Node *tail = node;
    print(head);
    // cout<<length(head);
    insertAtHead(head,tail, 11);
    print(head);
    // cout<<length(head);
    insertAtTail(head,tail, 25);
    print(head);
    insertAtPosition(head, tail, 30, 3);
    print(head);
    deletenode(2,head);
    print(head);
    return 0;
}
//OUTPUT
// 10 
// 11 10
// 11 10 25
// 11 10 30 25
// 11 30 25