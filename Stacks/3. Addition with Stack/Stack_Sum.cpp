//Vivek singh negi
//19_78066

#include <iostream>
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
	Node<T> *top, *newnode;


	   
    Stack()
     { 
        top = NULL;
     }
	  ~Stack() 
     { 
        clear(); 
     }
    
    bool isEmpty();
    void push(T n);
    T pop();
    T topelement();
    void display();
    void clear();
    
    };
    
   
    
/*********function to check if stack is empty or not**********/



template <class T>
	bool Stack<T>:: isEmpty()
  	{
		   if(top == NULL)
    return true;
    else
    return false;
    

  	}


/********function for pushing or inserting elements********/



template <class T>
	void Stack<T>:: push(T n)
	{
		 newnode = new Node<T>();
	 	newnode->data = n;
		if (isEmpty())
		{
			newnode->next = NULL;
			top = newnode;
		}
		else
		{
			newnode->next = top;
			top = newnode;
		}
		++count;
		
	}


/********function for popping or deleting elements from stack**********/



template <class T>
	T Stack<T> :: pop()
	{
		if(isEmpty())
		{
			cout<<"\n \n \n Stack is empty!"<<endl;
			return 0;
		}
		else
		{
			T n = top->data;
			if (top->next == NULL)
			{
				delete top;
				top = NULL;
			}
			else
			{
				newnode = top;
				top = top->next;
				delete newnode;
			}
			--count;
			return n;
		}
	}




/*******function to return top element of the stack*******/


template <class T>
T Stack<T> :: topelement()
	{
		if(isEmpty())
		{
			cout<<"\nStack is empty!"<<endl;
			return 0;
		}
		else 
 return top->data;
	}




/*******function for clearing stack**********/




template <class T>
	void Stack<T>:: clear()
	{
		while(!isEmpty())
			pop();

	}


/******function to display the stack***********/



template <class T>
	void Stack<T>:: display()
	{
		if(isEmpty())
			cout<<"\n \n \n Stack is empty!"<<endl;
		else
		{
			 newnode=top;
   while(newnode!=NULL)
  {
      cout<<newnode->data;
      newnode=newnode->next;

  }
			cout << endl;
		}
	}






/**********function to convert the entered number into stack*********/

void makestack(string &n, Stack<int> &stack)
{
	
     for(int i = 0; i < n.length(); ++i)
     	{
		        stack.push((int)(n[i] - 48));
     	}
}


/**********function to add two stacks*************/

void add(Stack<int> &s1, Stack<int> &s2, Stack<int> &sum)
{
	   int n1, n2, carry = 0;
	   int itr = (s2.count > s1.count) ? s2.count : s1.count;
	   for (int i = 0; i < itr; i++)
	    {
		       if(s1.isEmpty())
        n1=0;
        else
        n1=s1.pop();
		       if(s2.isEmpty())
        n2= 0;
        else
        n2= s2.pop();

	       	sum.push((n1 + n2 + carry) % 10);
	       	carry = (n1 + n2 + carry) / 10;
	    }
	  if (carry > 0)
	  sum.push(carry);
}


/**********main function************/


int main()
{
	string stack;
	Stack<int> s1, s2, s3;
	cout<<"\nEnter first number:  ";
	cin>> stack;
	makestack(stack, s1);
	cout<< "Enter second number: ";
	cin>>stack;
	makestack(stack, s2);
	cout<< "\n Sum of both\t: ";
	add(s1, s2, s3);
	s3.display();
	cout << endl;
}






