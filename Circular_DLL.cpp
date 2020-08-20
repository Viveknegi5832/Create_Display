#include<iostream>
using namespace std;


class Circular_DLL
{
   class Node
{
   public:
   int data;
   Node *next,*prev;
};
public:
Node *temp,*tail,*newnode;

Circular_DLL()
{
  tail=NULL;
}

~Circular_DLL()
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
bool isEmpty();//done
void create();//done
void display();//done
void insert_at_end();//done
void insert_at_beginning();//done
void insert_in_between();//done
void delete_at_beginning();//done
void delete_at_end();//done
void delete_in_between();//done
void search();//done
void count();//done


   
};


/*********isEmpty*********/


bool Circular_DLL :: isEmpty()
{
   if(tail==NULL)
   return true;
   else
   return false;
   
}

/**********CREATE*********/


void Circular_DLL :: create()
{
  char ch='y';
  while(ch=='y')
{
  insert_at_end();
  cout<<"\n want to enter more nodes (y/n): ";
  cin>>ch;
}
  

  
}



/********INSERT_AT_END***********/

void Circular_DLL :: insert_at_end()
{
  newnode = new Node();
  cout<<"\n Enter the data:";
  cin>>newnode->data;

 if(isEmpty())
{
   tail=newnode;
   tail->next=tail;
   tail->prev=tail;
}
else{
 

  newnode->next=tail->next;
  newnode->prev=tail;
  tail->next=newnode;
  newnode->next->prev=newnode;
  tail=newnode;

}
cout<<"Inserted!!";
}

/***********INSERT_AT_BEGINNING**********/


void Circular_DLL :: insert_at_beginning()
{

   if(isEmpty())
   insert_at_end();
   else
{
   newnode= new Node();
   cout<<"\n enter the data:";
   cin>>newnode->data;


   newnode->next=tail->next;
   tail->next->prev=newnode;
   tail->next=newnode;
   newnode->prev=tail; 
   cout<<"\n Inserted!";
}


}

/************INSERT_IN_BETWEEN***********/

void Circular_DLL :: insert_in_between()
{
  if(isEmpty())
  insert_at_end();
  else
{
  int loc,a=1;
  cout<<"\n Enter the location you want to add data:";
  cin>>loc;
  
  temp=tail->next;
  while(a<loc-1)
{
  temp=temp->next;
  a++;
  
}
 if(temp==tail)
 insert_at_end();
 else
  {
   newnode=new Node();
   cout<<"\n Enter the data:";
   cin>>newnode->data;


   newnode->next=temp->next;
   temp->next->prev=newnode;
   temp->next=newnode;
   newnode->prev=temp;

   cout<<"\n Inserted!!";
  }

}
}


/************DELETE_AT_BEGINNING*************/

void Circular_DLL :: delete_at_beginning()
{

   if(!isEmpty())
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
           temp->next->prev=tail;
           delete temp;
        }

     cout<<"\n Deleted node from beginning!";

   }
 
   else
   display();
   
 

}

/**********DELETE_AT_END************/

void Circular_DLL :: delete_at_end()
{

   if(!isEmpty())
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
          tail->next->prev=temp;
          delete tail;
          tail=temp;
 
       }
         cout<<"\n Deleted node from end!";
        
      }
    else
    display();
    
    }

/************DELETE_IN_BETWEEN********/
 
void Circular_DLL :: delete_in_between()
{

  if(!isEmpty())
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
             newnode->next->prev=temp;
             delete newnode;
             cout<<"\n Deleted an element at location "<<loc;
         }
       }
    
    }
    
    else
    display();
  
  

}

/***************SEARCH******************/


void Circular_DLL :: search()
{
   if(!isEmpty())
   {
  
       int count=0,flag=0;
       newnode=new Node();
       cout<<"\n Enter the data to be searched:";
       cin>>newnode->data;
       temp=tail;
   
      do{
         temp=temp->next;
         count++;
        if(temp->data==newnode->data)
           {
               flag=1;
               break;
           }
        
        }while(temp!=tail);

    if(flag==1)
    cout<<"Found At Location: "<<count;
    else
    cout<<"NOT FOUND!!";
    
    }
    else
    display();

}

/**********COUNT*************/
void Circular_DLL :: count()

{
  if(!isEmpty())
  {
     int count=0;
     temp=tail;
   do{
     
        temp=temp->next;
        count++;
    
      }while(temp!=tail);

     cout<<"Total elements:"<<count;
  } 
    else
    display();
}


/*************DISPLAY**************/

void Circular_DLL :: display()
 {
   if(isEmpty())
   cout<<"\n List is Empty!!";
   else
   {
      temp=tail;

      do{ 
          temp=temp->next;
		        	cout<<temp->data<<" ";
        	}while(temp!=tail);
    
         cout<<"\n";
   }
 

 }


int main()

{
    int a;
    char ch='y';
    Circular_DLL list;
    
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
    
      cout<<"\n Want to continue (y/n): ";
      cin>>ch;
    
    
    }while(ch=='y');
    
    return 0;
   
    
}





    
    
