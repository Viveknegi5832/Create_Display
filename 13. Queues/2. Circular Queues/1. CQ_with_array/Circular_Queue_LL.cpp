
//Vivek_singh_negi
//19_78066

#include<iostream>
#include<string>
using namespace std;
#define size 3


template<class T>
class Node
{
  public: 
    T data;
    Node *next;
};


template <class T>
class CircularQueue_LL

{ 
       Node<T> *first,*newnode,*last,*temp;
       public :
   
        CircularQueue_LL()
        {
          first = last = NULL;
        }
       ~CircularQueue_LL()
        {
          clear();
        }

   void enqueue(T n);
   bool isEmpty();
   bool isFull();
   void clear();
   void display();
   int count();
   T    firstelement();
   T    dequeue();

};

/********function to check if queue is empty************/

template <class T>
bool CircularQueue_LL<T> :: isEmpty()
{
   if(first == NULL)
     return true;
   else
     return false;
}



template <class T>
bool CircularQueue_LL<T> :: isFull()
{
  if(count()==size)
   return true;
  else
   return false;
}

template <class T>
int CircularQueue_LL<T> :: count()
	{
	   	int cnt = 0;
	  	if (!isEmpty())
	  	{
	    		temp = first;
		   	do
		    	{
			      ++cnt;
				     temp = temp->next;
			    }while(temp != last->next);
		  }
		   return cnt;
	}



/*********function to enter elements in the queue***********/


template <class T>
void CircularQueue_LL<T> :: enqueue(T n)
{
   
   
   
      newnode = new Node<T>();
      newnode->data=n;
      newnode->next=NULL;
      if(isFull())
        {
          cout<<"\n Queue Full ";
          return;
        }
     else if(isEmpty())
       {
          last = first = newnode;
          first->next=last; 
          return;
       }
      else
        {
           newnode->next=last->next;
           last->next=newnode;
           last=newnode;
          
        }
 


}


/************function to delete elements from queue*********/



template <class T>
T CircularQueue_LL<T> :: dequeue()
{

    T a;
    if(isEmpty())
     {
        cout<<"\n Can't delete, Queue is  empty. ";
        return 0;
     }
    else if(first==last)
     {
       a=first->data;
       delete first;
       first=last=NULL;
     }
    else
     {
         a=first->data;
         temp=first;
         first=first->next;
         last->next=first;
         delete temp;
     }
     
    return a;

}



/*********function to return first element of queue********/

template <class T>
T CircularQueue_LL<T> :: firstelement()
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
void CircularQueue_LL<T> :: display()
 {
   if(isEmpty())
    cout<<"\n Queue is Empty  ";
   else 
   {
      temp = first;
      cout<<endl;
      do
      {
          cout<<temp->data<<" ";
          temp=temp->next;
      }while(temp!=first);
                                                                           
   }
  
 
 }

/**********function to clear the queue**********/


template <class T>
void CircularQueue_LL<T> :: clear()
{
  if(isEmpty())
    cout<<"\n Queue is Empty ";
  else
   {
     while(!isEmpty())
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
   CircularQueue_LL<int> queue; 
   int data;
   cout<<"\n Demonstration of Linear Queue ";

   do{
          cout<<"\n \n 1. Insert element \n 2. Delete element \n 3. Display elements \n 4. First element \n 5. Clear Queue \n 6. count \n 7. exit  ";
          cout<<"\n Enter your choice : ";
          cin>>ch1;
                switch(ch1)
                     {
                              case 1:
                                     cout<<"\n Enter the data : ";
                                     cin>>data;   
                                     queue.enqueue(data);
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
                                     cout<<"\n Total elements : "<<queue.count();
                                     break;
                              case 7:
                                    exit(0);
                                                                                                                                                                                                                                                                                                                                                                    default:
                                                                                                                                                                                                                                                                                                                                                                                         cout<<"\n Invalid input. ";
                     }
        cout<<"\n \n \n Want to operate more (y/n) : ";
                cin>>ch2;
     }while(ch2=='y');
}
 











    