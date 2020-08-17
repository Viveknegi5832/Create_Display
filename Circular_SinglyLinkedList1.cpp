















#include<iostream>
using namespace std;


class Circular_SLL
{
   class Node
{
   public:
   int data;
   Node *next;
};
public:
Node *temp,*tail,*newnode;

Circular_SLL()
{
  tail=NULL;
}

~Circular_SLL()
{
  
  
  cout<<"\n memory is being released!";
  temp=tail->next;
  tail->next=NULL;
  while(temp!=NULL)
  {
    
    newnode=temp->next;
    delete temp;
    temp=newnode;
}
  
}

void create();
void display();
void insert_at_end();
void insert_at_beginning();
void insert_in_between();
void delete_at_beginning();
void delete_at_end();
void delete_in_between();
void search();
void count();

   
};


/**********CREATE*********/


void Circular_SLL :: create()
{
  char ch='y';
  while(ch=='y')
{
  insert_at_end();
  cout<<"\n want to enter more nodes (y/n)";
  cin>>ch;
}
  

  
}



/********INSERT_AT_END***********/

void Circular_SLL :: insert_at_end()
{
  newnode = new Node();
  cout<<"\n Enter the data:";
  cin>>newnode->data;

 if(tail==NULL)
{
   tail=newnode;
   tail->next=tail;
}
else{
 

  newnode->next=tail->next;
  tail->next=newnode;
  tail=newnode;

}
cout<<"Inserted!!";
}

/***********INSERT_AT_BEGINNING**********/
void Circular_SLL :: insert_at_beginning()
{
   newnode= new Node();
   cout<<"\n enter the data:";
   cin>>newnode->data;
   newnode->next=tail->next;
   tail->next=newnode;
   cout<<"\n Inserted!";


}

/************INSERT_IN_BETWEEN***********/

void Circular_SLL :: insert_in_between()
{
  int loc,a=1;
  cout<<"\n Enter the location you want to add data:";
  cin>>loc;
  newnode=new Node();
  cout<<"\n Enter the data:";
  cin>>newnode->data;
  temp=tail->next;
  while(a<loc-1)
{
  temp=temp->next;
  a++;
  
}
newnode->next=temp->next;
temp->next=newnode;


cout<<"\n Inserted!!";

}


/************DELETE_AT_BEGINNING*************/

void Circular_SLL :: delete_at_beginning()
{
   temp=tail->next;
   if(temp==tail)
{
   delete temp;
   tail=NULL;
}
else
{
   tail->next=temp->next;
   delete temp;
}

cout<<"\n Deleted!";
   
 

}

/**********DELETE_AT_END************/

void Circular_SLL :: delete_at_end()
{
   temp=tail->next;
   if(temp==tail)
{
    delete temp;
    tail=NULL;
}
else
{
  while(temp->next!=tail)
{
   temp=temp->next;
 }
 temp->next=tail->next;
 delete tail;
 tail=temp;
 
}

cout<<"\n Deleted!!";
}

/************DELETE_IN_BETWEEN********/
 
void Circular_SLL :: delete_in_between()
{
  int loc,a=1;
  cout<<"\n Enter the location of data to be deleted:";
  cin>>loc;
  temp=tail->next;
  if(loc==1)
{
  delete_at_beginning();
}
  else
  {
   
  while(a<loc-1)
  {
    temp=temp->next;
    a++;
  } 
   if(temp->next==tail)
{
   delete_at_end();
}
else
{
   newnode=temp->next;
   temp->next=newnode->next;
   delete newnode;
   cout<<"\n Deleted!!";
}
}
  
  

}

/***************SEARCH******************/
void Circular_SLL :: search()
{
   int count=0,flag=0;
   newnode=new Node();
   cout<<"\n Enter the data to be searched:";
   cin>>newnode->data;
   temp=tail;
   do
{
   temp=temp->next;
   count++;
   if(temp->data==newnode->data)
   {
      flag=1;
      break;
   }

   
    
}while(temp!=tail);

if(flag==1)
cout<<"found at location: "<<count;
else
cout<<"not found!!";

}

/**********COUNT*************/
void Circular_SLL :: count()

{
  int count=0;
  temp=tail;
  do{
     count++;
    temp=temp->next;
    
}while(temp!=tail);

cout<<"Total elements:"<<count;

  

}


/*************DISPLAY**************/

void Circular_SLL :: display()
{
   
   temp=tail->next;
	 	
		do
{
			
			cout<<temp->data<<" ";
  temp=temp->next;
  
		}while(temp!=tail);
cout<<temp->data;
    cout<<"\n";
 

}

  


int main()

{
    int a;
    char ch='y';
    Circular_SLL list;
    
    do{
     
        cout<<"\n 1.create \n 2.display \n 3.Insert at end\n 4.Insert at beginning\n 5.insert in between\n 6.delete at beginning\n 7.delete at end\n 8.delete in between\n 9.search\n 10.count nodes\n";
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
                  list.insert_at_end();
                  break;
          case 4:
                  list.insert_at_beginning();
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
                  list.search();
                  break;
          case 10:
                  list.count();
                  break;
          case 11:
                  exit(0);
        
        }
    
      cout<<"\n Want to continue (y/n):";
      cin>>ch;
    
    
    }while(ch=='y');
    
    return 0;
   
    
}





    
