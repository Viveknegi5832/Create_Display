#include<iostream> 
using namespace std;

class SinglyLinkedList
{
    

class Node
{
   public:
    int data;
    Node *next;
};
public:
Node *head,*newnode,*temp;
 
  void create()
  {

    
    head=Null;
    
    
    int ch=1;
    while(ch==1)
    {
        newnode = new Node();
        cout<<"Enter the data: \n";
        cin>>newnode->data;
        newnode->next=Null;
        
        if(head==Null)
        {
            head=temp=newnode;
        
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
     cout<<"1 for continue and 0 for exit \n";
     cin>>ch;
        
        
    }
    
    
    }
    
    void display()
    {
        
    
     temp=head;
     while(temp!=Null)
     {
         cout<<temp->data<<" ";
         temp=temp->next;
     }
    
}

};

int main()
{
    int n;
    char ch;
    SinglyLinkedList list;
    
    do{
        
        cout<<"enter 1 for create and 2 for display \n";
        cin>>n;
        
        switch(n)
        {
            case 1:
                   list.create();
                   break;
            case 2:
                   list.display();
                   break;
            default:
                   cout<<"wrong input \n";
                   break;
        }
        
        cout<<"y for continue \n";
        cin>>ch;
    }while(ch=='y');
    
    return 0;
}







