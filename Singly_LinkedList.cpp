
/****************Vivek_Singh_Negi****************
******************19_78066**********************/




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


    SinglyLinkedList()
    { 
       head=NULL;
    }

   ~SinglyLinkedList()
    {
        temp=head;
        cout<<" Deallocating memory....\n";
        while(temp!=Null)
          {
           temp1=temp;
           delete temp1;
           temp=temp->next;
           
          }
    }

  void create();
  void display();
  void insert_at_beginning();
  void insert_at_end();
  void insert_in_between();
  void delete_at_beginning();
  void delete_at_end();
  void delete_in_between();
  void search();
  void count();
  void reverse();
};



/********CREATING_NODES*******/



  void SinglyLinkedList :: create()
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


/*******DELETE_IN_BETWEEN*********/


void SinglyLinkedList :: delete_in_between()
{
     int loc,i=1;
     cout<<"enter the location of data you want to delete\n";
     cin>>loc;
     temp=head;
   while(i<loc-1)
    {
      temp=temp->next;
      i++;
    }
    temp1=temp->next;
    temp->next=temp->next->next;
    delete temp1;
    cout<<"Deleted in given location!\n";


}


/*******DELETE_AT_BEGINNING******/


void SinglyLinkedList :: delete_at_beginning()
{
   temp=head;
   head=head->next;
   delete temp;
   cout<<"Deleted at beginning! \n";
}



/*******DELETE_AT_END********/


void  SinglyLinkedList :: delete_at_end()

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


/*******INSERT_AT_BEGINNING********/


void SinglyLinkedList :: insert_at_Beginning()

{
  
  newnode=new Node();
  cout<<"enter the data:";
  cin>>newnode->data;
  newnode->next=head;
  head=newnode;
  cout<<"Inserted! \n";
}



/*******INSERT_AT_END******/


void SinglyLinkedList ::   insert_at_end()

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


/*******INSERT_IN_BETWEEN******/


void SinglyLinkedList :: insert_in_between()

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
    }
    newnode->next=temp->next;
    temp->next=newnode;
    cout<<"Inserted! \n";

}

/********SEARCH_A_NODE******/


void  SinglyLinkedList :: search()
{
  int n, count=0,flag=0;
  cout<<"Enter the value to be searched:";
  cin>>n;
  temp=head;
  while(temp!=NULL)
    {
       ++count;
   
      if(temp->data==n)
      {
             flag=1;
             break;
      }
         temp=temp->next;
    }
   if(flag==1)
   cout<<"data found at location:"<<count<<"\n";
   else
   cout<<"not found: \n";
}

/*******COUNT_THE_NODES********/


void SinglyLinkedList :: count()
{
     int count=0;
     temp=head;
 while(temp->next!=NULL)
   {
      temp=temp->next;
      ++count;
   }
   cout<<"no. of nodes ="<<count+1<<endl;

}

/******REVERSE_LINKEDLIST*******/


void SinglyLinkedList :: reverse()
{

       temp=head->next;
       head->next=NULL;
       newnode=head;
       while(temp!=NULL)
    {
       temp1=temp;
       temp=temp->next;
       temp1->next=head;
       head=temp1;
    }
      cout<<"Reversed! \n";
      display();

}

/*******DISPLAY_THE_NODES*********/


void  SinglyLinkedList :: display() 
{
   temp=head; 
   while(temp!=NULL)
   { 
      cout<<temp->data<<" ";
      temp=temp->next; 
   } 
      cout<<endl;
}
  
int main() 
{ int n; 
char ch;
 SinglyLinkedList list; 
do{ 
cout<<"\n 1.create \n 2.display \n 3.insert at beginning \n 4.insert at end \n 5.insert in between \n 6.delete at end \n 7.delete at beginning \n 8.delete in any location\n 9.count nodes\n 10.search node\n 11.Reverse LinkedList\n";
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
case 8:  
         list.delete_in_between();
         break;
case 9:  
         list.count();
         break; 
case 10: 
         list.search();
         break;
case 11:
         list.reverse();
         break;
case 12:
         exit(0); 
 }
 cout<<"want to continue (y/n) \n :"; 
cin>>ch; 
}while(ch=='y'); 
return 0;
 } 
    
