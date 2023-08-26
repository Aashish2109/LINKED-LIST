#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertNode(Node *&tail, int element, int data)
{
    // empty list
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        // list is not empty

        Node *current = tail;
        while (current->data != element)
        {
            current = current->next;
        }
        Node *temp = new Node(data);
        temp->next = current->next;
        current->next = temp;
    }
}
void deleteNode(Node *&tail, int value)
{

    if (tail == NULL)
    {
        cout << "PLZ add some value"
             << " ";
        return;
    }
    else
    {
        Node *previous = tail;
        Node *current = previous->next;
        while (current->data != value)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if (current == previous)
        {
            tail = NULL;
        }
        else if (tail == current)
        {
            tail = previous;
        }
        current->next = NULL;
        delete current;
    }
}
    void print(Node * tail)
    {
        Node *temp = tail;
        if (tail == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

        do
        {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != temp);
        cout << endl;
    }
    int main()
    {

        Node *tail = NULL;
        insertNode(tail, 5, 3);
        print(tail);
        insertNode(tail, 3, 5);
        print(tail);
        insertNode(tail, 5, 7);
        print(tail);
        insertNode(tail, 7, 9);
        print(tail);
        deleteNode(tail, 3);
        print(tail);
        return 0;
    }
