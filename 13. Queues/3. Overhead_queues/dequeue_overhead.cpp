#include <iostream>
//#include "stack_ll.h"
//#define Stack<X> s1, s2 ;
using namespace std;

template <class T>
class Node
	{
   public:
		  T data;
	   Node *next;
	};

template <class T>
class Stack 
{	
     public:
	    int count = 0;
	    Node<T> *top, *temp;

  
	    Stack()  //Constructor
     { 
       top = NULL; 
     }
	    ~Stack() 
     { 
       clear(); 
     }

    	bool isEmpty()
	    {
	      	if(top == NULL)
       return true;
       else
       return false;
    	 }

	   void push(T n)
	    {
	      	temp = new Node<T>();
		      temp->data = n;
	      	if(isEmpty())
		      {
			       temp->next = NULL;
			       top = temp;
	      	 }
	      	else
		      {
		       	temp->next = top;
		       	top = temp;
	       	}
	          	++count;
	    }

	   T pop()
	   {
	     	if(isEmpty())
		     {
			      cout << "\nStack is empty!" << endl;
			      return 0;
	      }
	     else
		     {
		       	T n = top->data;
		       	if(top->next == NULL)
		        {
		    	        delete top;
		            top = NULL;
			       }
			      else
		       	{
			        	temp = top;
			        	top = top->next;
			        	delete temp;
		       	}
	      		--count;
		      	return n;
	     	}
	  }
    
	T topelement()
	{
		if(isEmpty())
		 {
		  	cout<<"\n Stack is empty! "<<endl;
		  	return 0;
		 }
		else 
 return top->data;
	}



	void display()
	{
		if (isEmpty())
			cout << "\nStack is empty!" << endl;
		else
		{
			temp = top;
			cout << "\n \t";
			while (temp != NULL)
			{
				cout<<temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

 void clear()
 {
    while(!isEmpty())
    pop();
 }
};


/**************************
	Queue Class
***************************/


template <class T>
class Queue
{
	 public:

	 Stack<int> s1, s2;
  int cnt = 0;
 
	Queue(){}//Constructor
	
	 
	~Queue()//Destructor
  { 
	   	 s1.clear(); 
	    s2.clear();
	 }
	
	/*  isempty function. */



	bool isempty()
	{
		if(s1.isEmpty())
 return true;
 else
		return false;
	}
	
	/* enqueue function. */


	void enqueue(T val)
	{
	   	++cnt;
    s1.push(val);
	
	}
	
	/*   dequeue function. */



	T dequeue()
	{
		if(isempty())
		{
			cout << "Queue underflow!\n";
			return 0;
		}
 else
{
		--cnt;
  while(!s1.isEmpty())
  {
    s2.push(s1.pop());
  }
 T n = s2.pop();
  
  while(!s2.isEmpty())
   { 
     s1.push(s2.pop());
   }

		return n;
}
	}
	
	/* count function */


	int count()
	{
		return cnt;
	}
	
/*display function*/


	void display()
	{
		if (isempty())
			cout << " \nQueue is empty!\n";
		else 
  {
    while(!s1.isEmpty())
     {
       s2.push(s1.pop());
     }
    
     cout<<"\n\n \t";
    
    while(!s2.isEmpty())
     {
        int a=s2.pop();
        
        cout<<a<<" ";
        s1.push(a);
     }
    
  }
	}
	
	/* firstelement function of queue */


	T firstelement()
	{
		if (isempty())
			return -1;
 else
  {
		   while(!s1.isEmpty())
     {
       s2.push(s1.pop());
     }
    T b = s2.topelement();
    
    while(!s2.isEmpty())
    {
      s1.push(s2.pop());
    }
    
    return b;
  }

	}
	
	/* clear function*/


	void clear()
	{
		cnt = 0;
		s1.clear();
	}


};






//#include <iostream>
//using namespace std;


/***************************************
	Driver(Main) Function
****************************************/


int main()
{

	 Queue<int> que;
 
	  int ch,val;
   char ch1;
	  cout << "\n< Queue using Stacks with Enqueue Overhead >\n";
	do
	{
	
		cout << "\n1. Enqueue\n2. Dequeue\n3. Clear the queue\n4. Count\n5. First\n6. Display the queue\n7. Exit\n";
		
		cout << "Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout<<"\nEnter the element: ";
			cin >> val;
			que.enqueue(val);
			break;
		case 2:
			cout<<endl<<que.dequeue()<<" is Deleted. ";
			break;
		case 3:
			que.clear();
			cout<<"\n Queue cleared!\n";
			break;
		case 4:
			cout<<"\n No of element in the queue : " << que.count() << endl;
			break;
		case 5:
			cout<<"\n Element at front is: " << que.firstelement() << endl;
			break;
		case 6:
			que.display();
			break;
 case 7:
  exit(0);
		}
 cout<<"\nWant to continue(y/n) : ";
	cin>>ch1;
} while (ch1 =='y');

	return 0;

}

    