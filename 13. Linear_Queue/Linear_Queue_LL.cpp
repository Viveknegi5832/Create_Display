










//Vivek_singh_negi
//19_78066

#include<iostream>
#include<string>
using namespace std;
#define size 5


template<class T>
class Node
{
  public: 
  T data;
  Node *next;
};



template <class T>
class LinearQueue_LL

{ 
   Node<T> *first,*newnode,*last,*temp;
   
   public :

   T que[size];

   LinearQueue_LL()
     {
        first = last = NULL;
       
     }
  ~LinearQueue_LL()
     {
        clear();
     }


   void enqueue();
   bool isEmpty();
   void clear();
   void display();
   T    firstelement();
   T    dequeue();
   

};

/********function to check if queue is empty************/

   
   
template <class T>
bool LinearQueue_LL<T> :: isEmpty()
{
   if(first == NULL)
   return true;
   else
   return false;
}



/*********function to enter elements in the queue***********/


template <class T>
void LinearQueue_LL<T> :: enqueue()
{
 char ch;
do{

   int n;
   newnode = new Node<T>();
   cout<<"\n Enter the data : ";
   cin>>newnode->data;
   newnode->next=NULL;
   if(isEmpty())
   {
       last = first = newnode;
       cout<<"\n data added !! ";
   }
  else
   {
      last->next=newnode;
      last=newnode;
      cout<<"\n data added !! ";
   }

 /* else
   {
      cout<<"\n **** Reached last element **** ";
      break;
   }
*/
   

   cout<<"\n \n Wanna add more elements (y/n) : ";
   cin>>ch;
   
}while(ch=='y');

}


/************function to delete elements from queue*********/



template <class T>
T LinearQueue_LL<T> :: dequeue()
{

    T a;
    if(isEmpty())
    {
      cout<<"\n Can't delete, Queue is  empty. ";
      return 0;
    }
 
   else
    {
      
      a=first->data;
      delete first;
      first=first->next;
      return a;
      
      
    }
    
    

}

/*********function to return first element of queue********/




template <class T>
T LinearQueue_LL<T> :: firstelement()
{
  if(isEmpty())
  {
     cout<<"\n Can't return, Queue is empty ";
     return 0;
  }
  else 
  {
  return first->data;
  }
  

}



/******function to display queue********/

template <class T>
void LinearQueue_LL<T> :: display()
{
   if(isEmpty())
   cout<<"\n No elements to display. ";
   else if(first==NULL)
   cout<<"\n No elements, all spaces  already used ";
   else 
    {
      temp = first;
      cout<<endl;
      while(temp != NULL)
       {
          cout<<temp->data<<" ";
          temp=temp->next;
       }
    }
    
    
    

}

/**********function to clear the queue**********/


template <class T>
void LinearQueue_LL<T> :: clear()
{
  
  if(isEmpty())
  cout<<"\n Nothing to clear.  ";
  else
    {
       
       while(first != NULL)
        {
           dequeue();
          
        }
        
       cout<<"\n Cleared !!";
      
       
    
    }


}

/********main function*************/



int main()
{
   int ch1;
   char ch2;
   LinearQueue_LL<int> queue; 
   cout<<"\n Demonstration of Linear Queue ";
   

   do{
       cout<<"\n \n 1. Insert element \n 2. Delete element \n 3. Display elements \n 4. First element \n 5. Clear Queue \n 6. exit  ";
       cout<<"\n Enter your choice : ";
       cin>>ch1;
    
       switch(ch1)
         {
              case 1:
                      queue.enqueue();
                      break;
              case 2:
                      cout<<"\n "<<queue.dequeue()<<" Deleted ";
                      break;
              case 3:
                      queue.display();
                      break;
              case 4:
                      cout<<"\n First element is "<<queue.firstelement();
                      break;
              case 5:
                      queue.clear();
                      break;
              case 6:
                      exit(0);
              default:
                     cout<<"\n Invalid input. ";
            
                      
         }
        
        
        cout<<"\n \n \n Want to operate more (y/n) : ";
        cin>>ch2;
     
     }while(ch2=='y');
  
}
 
    