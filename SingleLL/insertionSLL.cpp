#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next; //This member variable represents a pointer to the next node in a linked list. 
    Node *tail;//This member variable represents a pointer to the tail or last node of the linked list. 
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

bool detect(Node *head)
{

    map<Node* , bool> visited;
    Node *temp=head;
    if(head==NULL)
    {
        return false;
    }
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            cout<<"Loop element is"<<temp->data<<endl;;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;

}
int main()
{
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;
    // print(head);
    // cout<<"head"<<" "<<head->data<<endl;
    // cout<<"tail"<<" "<<tail->data<<endl;
    // InsertAtHead(head,100);
    // print(head);
    InsertAtTail(tail, 12);
    // print(head);
    // cout<<"head"<<" "<<head->data<<endl;
    // cout<<"tail"<<" "<<tail->data<<endl;
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 25);
    InsertAtTail(tail, 35);
    // print(head);
    // cout<<"head"<<" "<<head->data<<endl;
    // cout<<"tail"<<" "<<tail->data<<endl;
    // InsertatMid(head, 3, 22);
    // print(head);
    // Insertatposition(tail, head, 2, 22);
    print(head);
    tail->next=head->next;
    cout<<"head"<<" "<<head->data<<endl;
    cout<<"tail"<<" "<<tail->data<<endl;
    detect(head);
    if(detect(head))
    {
        cout<<"Loop is present"<<endl;
    }
    else
    {
        cout<<"No cycle is present"<<endl;
    }

}
//OUTPUT
// 10 
// 10 12
// 10 12 15
// 10 22 12 15
// head 10
// tail 15