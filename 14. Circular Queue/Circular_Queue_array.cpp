//Vivek_Singh_Negi
//19_78066


#include<iostream>
#include<string>
using namespace std;
#define size 3

template <class T>
class Circular_Queue

{ 
   int first;
   int last;
   int temp;


   public :

   T que[size];

   Circular_Queue()
     {
        first = last = -1;
       
     }
  ~Circular_Queue()
     {
        delete[] que;
     }


   void enqueue(T n);
   bool isEmpty();
   void clear();
   void display();
   bool isFull();
   T    firstelement();
   T    dequeue();
   

};
   
   
template <class T>
bool Circular_Queue<T> :: isEmpty()
{
   if(first==-1)
   return true;
   else
   return false;
}



template <class T>
bool Circular_Queue<T> :: isFull()
{
  if((last + 1) % size == first )
    return true;
  else
    return false;
  
}


template <class T>
void Circular_Queue<T> :: enqueue(T n)
{


      if(isFull())
       {
          cout<<"\n Queue is full!! ";
          return;
       }
      else if(isEmpty())
        {
          first=last=0;
        }
      else
        {
          last = (last + 1) % size ;
        }
      que[last] = n;
}



template <class T>
T Circular_Queue<T> :: dequeue()
{

    T a;
    if(isEmpty())
    {
      cout<<"\n Can't delete, Queue is  empty. ";
      return 0;
    }
    else if(first==last)
    {
       a=que[first];
       first=last=-1;
    }
   else
    {
      a=que[first];
      first = (first + 1) % size;
    }
    
    return a;
    

}



template <class T>
T Circular_Queue<T> :: firstelement()
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



template <class T>
void Circular_Queue<T> :: display()
{
   if(isEmpty())
   cout<<"\n Queue is Empty  ";
   else 
  {
    if(first<=last)
    {
      for(int i=first ; i<=last ; i++)
      cout<<que[i]<<" ";
    }
   else
    {
      for(int i=first ; i< size ; i++)
         cout<<que[i]<<" ";
      for(int i=0 ; i<=last ; i++)
         cout<<que[i]<<" ";
    }
    
  }  
    
    

}



template <class T>
void Circular_Queue<T> :: clear()
{
  
  if(isEmpty())
  cout<<"\n Queue is already Empty   ";
  else
   {
      while(!isEmpty())
      dequeue();
   }
    
    


}


int main()
{
   int ch1;
   char ch2;
   int data;
   Circular_Queue<int> queue; 
   cout<<"\n Demonstration of Linear Queue ";
   

   do{
       cout<<"\n \n 1. Insert element \n 2. Delete element \n 3. Display elements \n 4. First element \n 5. Clear Queue \n 6. exit  ";
       cout<<"\n Enter your choice : ";
       cin>>ch1;
    
       switch(ch1)
         {
              case 1:
                      cout<<"\n Ente the data :";
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
                      cout<<"\n Cleared ";
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
 











