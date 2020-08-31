


//Vivek Singh Negi
//19_78066


#include<iostream>
#include<string.h>

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


	   
    Stack() //Constructor
     { 
        top = NULL;
     }
	  ~Stack() //Destructor
     { 
        clear(); 
     }
    
    bool isEmpty();
    void push(T n);
    T topelement();
    T pop();
    void clear();
    
    };
  
    
/********function to check if stack isempty or not********/  
    
    
    
template <class T>
	bool Stack<T>:: isEmpty()
  	{
		   if(top == NULL)
    return true;
    else
    return false;
    

  	}


/*********function to push or insert element in stack*********/



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

/********function to delete element from stack*********/


 

template <class T>
	T Stack<T> :: pop()
	{
	
		if(!isEmpty())
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

/********function for clearing the stack***********/




template <class T>
	void Stack<T>:: clear()
	{
		    while(!isEmpty())
		    	pop();
		    
	}

  

/*********function to return top element of a stack**********/


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
			
/*******function to check the precedence of the operators*********/



int precedence(char ch)
{
	  if(ch=='^')
  return 3;
  else if(ch=='*' || ch=='/' || ch=='%')
  return 2;
  else if(ch=='+' || ch=='-')
  return 1;
  else
  return -1;
  
}



/********function to convert the infix expression into postfix************/



string infix_to_postfix(string infix)
{
	string postfix = "";
	Stack<char> stack;
 int i=0;


	for( int i=0 ; i < infix.length(); i++)
	{
		if(isblank(infix[i]))
 continue;

		else if(isalnum(infix[i])) 
      postfix += infix[i];
		else if(infix[i] == '(') 
      stack.push(infix[i]);
		else if(infix[i] == ')')
		  {
	     		while(!stack.isEmpty() && stack.topelement() != '(')
				    postfix = postfix + stack.pop();
			     stack.pop();
	   	}
		else
		{
			    while(!stack.isEmpty() && precedence(infix[i]) < precedence(stack.topelement()))
			   {
			        	postfix += stack.pop();
		    }
		        	stack.push(infix[i]);			
		}
  
  

	}
	while(!stack.isEmpty())
		postfix += stack.pop();
	return postfix;
}

int main()
{
	string str;
	cout <<"\n Enter the infix expression \n ";
	getline(cin, str);
	cout <<"\n Equivalent postfix expression \n "<<infix_to_postfix(str);
	return 0;
}

















