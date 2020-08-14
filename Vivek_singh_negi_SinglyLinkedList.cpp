
//Vivek_Singh_Negi
//19_78066



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
    Node *head,*newnode,*temp,*temp1; 
    void create()
 { 
    head=NULL; 
    int ch=1;
    while(ch==1) 
     {
        newnode = new Node();
        cout<<"Enter the data: ";
        cin>>newnode->data; 
        newnode->next=NULL;
      if(head==NULL) 
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
void delete_in_between()
{
   int loc,i=1;
   cout<<"enter the location of data you want to delete\n";
   cin>>loc;
   temp=head;
   while(i<loc-1)
{
  temp=temp->next;
  i++;
  
}temp1=temp->next;
temp->next=temp->next->next;
delete temp1;
cout<<"Deleted in given location!\n";


}





void delete_at_beginning()
{
   temp=head;
   head=head->next;
   delete temp;
   cout<<"Deleted at beginning! \n";
}
void delete_at_end()
{
   temp=head;
   while(temp->next!=newnode)
  {
       temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    newnode=temp;
    cout<<"Deleted at end! \n";
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
  while(temp->next!=NULL)
{
   temp=temp->next;
} 
 temp->next=newnode;
newnode->next=NULL;
cout<<"Inserted! \n";
}
void insert_in_between()
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
while(temp!=NULL)
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
cout<<"\n 1.create \n 2.display \n 3.insert at beginning \n 4.insert at end \n 5.insert in between \n 6.delete at end \n 7.delete at beginning \n 8.delete in any location\n";
 cout<<"enter your choice:";
cin>>n; 
switch(n) 
{ case 1:
          list.create(); 
          break; 
case 2:
         list.display(); 
         break;
case 3:
         list.insert_at_Beginning();
         break; 
case 4: 
         list.insert_at_end();
         break;
case 5: 
         list.insert_in_between();
         break;
case 6:
         list.delete_at_end();
         break;
case 7:
         list.delete_at_beginning();
         break;
case 8:  list.delete_in_between();
         break; 
case 9:
         exit(0); 
 }
 cout<<"want to continue (y/n) \n"; 
cin>>ch; 
}while(ch=='y'); 
return 0;
 } 
    
