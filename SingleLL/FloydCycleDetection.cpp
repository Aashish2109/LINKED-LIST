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
bool detect(Node *&head)
{
    Node* temp=head;
    map<Node*,bool>visited;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            cout<<"LOOP IS PRESENT AT:"<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
Node* floydAlgo(Node* &head)
{
    if(head==NULL ||head->next==NULL)
    {
        return NULL;
    }
   Node* slow=head;
   Node* fast=head;
   bool loopexists=false;
    while(slow!=NULL && fast !=NULL)
    {
       fast=fast->next;
       if(fast!=NULL)
       {
        fast=fast->next;
       }
       slow=slow->next;
       if(slow==fast)
       {
         loopexists=true;
         break;
       }
    }
       if(!loopexists)
       {
            return NULL;
       }
       slow=head;;
       {
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
       }
    
}
Node* removeLoop(Node *&head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* startloop=floydAlgo(head);
    if(startloop==NULL)
    {
        return NULL;
    }
    Node* temp=startloop;
    while (temp->next!=startloop)
    {
       temp=temp->next;
    }
    temp->next=NULL;
    
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
    if(floydAlgo(head) &&detect(head))
    {
        cout<<"";
    }
    else
    {
        cout<<"Loop is not present "<<endl;
    }
    removeLoop(head);
    print(head);
      if(floydAlgo(head) &&detect(head))
    {
        cout<<"";
    }
    else
    {
        cout<<"Loop is not present "<<endl;
    }
}
//OUTPUT
// Head is 20
// Tail is 10
// Head is 30
// Tail is 10
// Head is 30
// Tail is 40
// Head is 30
// Tail is 50
// LOOP IS PRESENT AT:20
// 30 20 10 40 50
// Loop is not present