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
        cout<<"Enter the data: ";
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
void insert_at_Beginning()
{
  
  newnode=new Node();
  cout<<"enter the data:";
  cin>>newnode->data;
  newnode->next=head;
  head=newnode;
  cout<<"Inserted! \n";
}
void insert_at_end()
{
  newnode = new Node();
  cout<<"enter the data:";
  cin>>newnode->data;
  temp=head;
  while(temp->next!=Null)
{
   temp=temp->next;
} 
 temp->next=newnode;
newnode->next=Null;
cout<<"Inserted! \n";
}
void insert_between()
{
  int location;
  int i=1;
  cout<<"enter the location you want the new node to be at:";
  cin>>location;
  newnode=new Node();
  cout<<"enter the data:";
  cin>>newnode->data;
  
  temp=head;
  while(i<location-1)
{
  temp=temp->next;
  i++;
  
}newnode->next=temp->next;
temp->next=newnode;
cout<<"Inserted! \n";

}

void display() 
{ temp=head; 
while(temp!=Null)
 { cout<<temp->data<<" ";
 temp=temp->next; 
} 
cout<<endl;
}
 }; 
int main() 
{ int n; 
char ch;
 SinglyLinkedList list; 
do{ 
cout<<"\n 1.create \n 2.display \n 3.insert at beginning \n 4.insert at end \n 5.insert in between \n";
 cin>>n; 
switch(n) 
{ case 1: list.create(); 
break; 
case 2: list.display(); 
break;
case 3: list.insert_at_Beginning();
break; 
case 4: list.insert_at_end();
break;
case 5: list.insert_between();
break;
default: cout<<"wrong input \n";
break; 
 }
 cout<<"y for continue \n"; 
cin>>ch; 
}while(ch=='y'); 
return 0;
 } 
    
