//Vivek_singh_negi
//19_78066

#include<iostream>
#include<string>
using namespace std;
#define size 5

template <class T>
class Linear_Queue

{ 
   int first;
   int last;
   int temp;


   public :

   T que[size];

   Linear_Queue()
     {
        first = last = -1;
       
     }
  ~Linear_Queue()
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
bool Linear_Queue<T> :: isEmpty()
{
   if(first==-1)
   return true;
   else
   return false;
}



/*********function to enter elements in the queue***********/


template <class T>
void Linear_Queue<T> :: enqueue()
{
 char ch;
do{

   int n;



   if(isEmpty())
   {
       first=last=0;
       cout<<"\n Enter the data : ";
       cin>>que[first];  
       cout<<"\n data added !! ";
   }
  else if(last < size-1 )
   {
      cout<<"\n Enter the data : ";
      cin>>que[++last];
      cout<<"\n data added !! ";
   }

  else
   {
      cout<<"\n **** Reached last element **** ";
      break;
   }

   

   cout<<"\n \n Wanna add more elements (y/n) : ";
   cin>>ch;
   
}while(ch=='y');

}


/************function to delete elements from queue*********/



template <class T>
T Linear_Queue<T> :: dequeue()
{

    int a;
    if(isEmpty())
    {
      cout<<"\n Can't delete, Queue is  empty. ";
      return 0;
    }
    else if(first==size)
    {
   
    cout<<"\n Nothing to delete ";
    exit(0);
     }
   else
    {
      
      a=que[first];
      first++;
      return a;
    }
    
    

}

/*********function to return first element of queue********/




template <class T>
T Linear_Queue<T> :: firstelement()
{
  if(isEmpty())
  {
     cout<<"\n Can't return, Queue is empty ";
     return 0;
  }
  else 
  {
  return que[first];
  }
  

}



/******function to display queue********/

template <class T>
void Linear_Queue<T> :: display()
{
   if(isEmpty())
   cout<<"\n No elements to display. ";
   else if(first==size)
   cout<<"\n No elements, all spaces  already used ";
   else 
    {
      temp=first;
      cout<<endl;
      while(temp <= last)
       {
          cout<<que[temp]<<" ";
          temp++;
       }
    }
    
    
    

}

/**********function to clear the queue**********/


template <class T>
void Linear_Queue<T> :: clear()
{
  
  if(isEmpty())
  cout<<"\n Nothing to clear.  ";
  else
    {
       temp=first;
       while(temp <= last)
        {
           dequeue();
           temp++;
        }
        
       cout<<"\n Cleared !!";
    
    }


}

/********main function*************/



int main()
{
   int ch1;
   char ch2;
   Linear_Queue<int> queue; 
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
 
