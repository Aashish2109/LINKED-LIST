#include<iostream>
#include<map>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* tail;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};
void insertathead(Node* &head,int data)
{
    Node* temp=new Node(data);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void insertattail(Node* &tail,int data)
{
    Node* temp=new Node(data);
    if(tail==NULL)
    {
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}
bool detect(Node* &head)
{
    if(head==NULL)
    {
        return false;
    }
    map<Node*,bool>visited;
    Node*temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            cout<<"Cycle is present at "<<temp->data;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;

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
int main()
{
    Node* node=new Node(10);
    Node *head=node;
    Node *tail=node;
    insertathead(head,20);
    cout<<"Head is "<<head->data<<endl;
    cout<<"Tail is "<<tail->data<<endl;
    insertathead(head,30);
    cout<<"Head is "<<head->data<<endl;
    cout<<"Tail is "<<tail->data<<endl;
    insertattail(tail,40);
    cout<<"Head is "<<head->data<<endl;
    cout<<"Tail is "<<tail->data<<endl;
    insertattail(tail,50);
    tail->next=head->next;
    cout<<"Head is "<<head->data<<endl;
    cout<<"Tail is "<<tail->data<<endl;
    if(detect(head))
    {
        cout<<"Loop is present "<<endl;
    }
    else
    {
        cout<<"Loop is not present "<<endl;
    }
}