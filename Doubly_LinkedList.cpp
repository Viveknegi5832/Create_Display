#include<iostream>
using namespace std;
class Doubly_LinkedList
{

 class Node
{
  public:
  int data;
  Node *prev,*next;
};

public:
Node *head,*temp,*newnode,*temp1;
Doubly_LinkedList()
{
 head=NULL;
}

void create();
void display();
void insert_at_beginning();
void insert_at_end();
void insert_in_between();
void delete_at_beginning();
void delete_at_end();
void delete_in_between();
};

/***********CREATE_A_NODE***********/

void Doubly_LinkedList :: create()
{
  
   char ch='y';
   
   while(ch=='y')
{
   newnode= new Node();
   cout<<"Enter the data: ";
   cin>>newnode->data;
   if(head==NULL)

   {
     head=temp=newnode;
     head->prev=NULL;
     temp->prev=NULL;
   }
     else
    {
      temp->next=newnode;
      newnode->prev=temp;
      temp=newnode;
    }
    cout<<"want to enter more nodes (y/n):";
    cin>>ch;

}

/**********DISPLAY*********/

}
void Doubly_LinkedList :: display()
{
   temp=head;
  while(temp!=NULL)
{
   cout<<temp->data<<" ";
   temp=temp->next;

}
cout<<endl;
 
}

/**********INSERT_AT_BEGINNING**********/


void Doubly_LinkedList :: insert_at_beginning()
{
   newnode=new Node();
   cout<<"\n enter the data:";
   cin>>newnode->data;
   head->prev=newnode;
   newnode->next=head;
   head=newnode;
   cout<<"\n Inserted at beginning! \n";
}

/**********INSERT_AT_END***********/

void Doubly_LinkedList :: insert_at_end()
{
   newnode=new Node();
   cout<<"\n enter the data:";
   cin>>newnode->data;
   if(head==NULL)
    {
       head=newnode;
       head->next=NULL;
    
    }
    else
    {
      temp=head;
      while(temp->next!=NULL)
    {
       temp=temp->next;
    }
     newnode->prev=temp;
     temp->next=newnode;
     newnode->next=NULL;
    
    cout<<"\n Inserted at end! \n";
    }


}

/**********INSERT_IN_BETWEEN*********/


void Doubly_LinkedList :: insert_in_between()
{
  int loc,a=1;
  cout<<"\n enter the location you want the node to add:";
  cin>>loc;
  newnode=new Node();
  cout<<"\n enter the data:";
  cin>>newnode->data;
  temp=head;
  while(a<loc-1)
{
  temp=temp->next;
  a++;
   
}
newnode->next=temp->next;
newnode->prev=temp;
temp->next=newnode;

cout<<"\n Inserted in given location! \n";

}

/*********DELETE_AT_BEGINNING*********/

void Doubly_LinkedList :: delete_at_beginning()
{
  temp=head;
  temp->next->prev=NULL;
  head=temp->next;
  delete temp;
  cout<<"\n Deleted at beginning! \n";
  

  

}


/**********DELETE_AT_END*************/


void Doubly_LinkedList :: delete_at_end()
{
   temp=head;
   while(temp->next!=NULL)
{
   temp=temp->next;
   
}
temp->prev->next=NULL;
delete temp;
 cout<<"\n Deleted at end! \n";

}

/*********DELETE_IN_BETWEEN**********/

void Doubly_LinkedList :: delete_in_between()
{
  int loc,a=1;
  cout<<"\n enter the location you want the node to be deleted:";
  cin>>loc;
  temp=head;
  while(a<loc-1)
{
   temp=temp->next;
   a++;
}
 temp1=temp->next;
if(temp==head)
{
delete_at_beginning();
}
else
if(temp1==newnode)
{
delete_at_end();
}
else{

temp->next=temp1->next;
temp1->next->prev=temp;
delete temp1;
cout<<"\n Deleted at given location!\n";
  }
}







int main()
{
  Doubly_LinkedList list;
  char ch1;
  do{
     int a;
     cout<<"\n 1.create a node\n 2.display\n 3.insert at beginning\n 4.insert at end\n 5.insert in between\n 6.delete at beginning\n 7.delete at end\n 8.delete in between\n";
     cin>>a;
    
    
    switch(a)
    {
       case 1:
               list.create();
               break;
       case 2:
               list.display();
               break;
       case 3:
               list.insert_at_beginning();
               break;  
       case 4:
               list.insert_at_end();
               break;   
       case 5:
               list.insert_in_between();
               break; 
       case 6:
               list.delete_at_beginning();
               break;
       case 7:
               list.delete_at_end();
               break;  
       case 8:
               list.delete_in_between();
               break;
       case 9:
               exit(0);
    
    
    
    }
    
    cout<<"\n want to continue(y/n):";
    cin>>ch1;

}while(ch1=='y');
return 0;
 
}



    