//Vivek singh negi
//19_78066



#include <iostream>
#include <stdlib.h>
#include <string.h>

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

/********functio for clearing the stack***********/




template <class T>
	void Stack<T>:: clear()
	{
		    while(!isEmpty())
		    	pop();
		    
	}
			

/***********function for reversing a number***********/


int reverse(int number)
{

   int rem=0;
   while(number!=0)
    {
       
       rem = rem*10 + number%10;
       number = number/10;
    
    }
    
    return rem;
}



/***********function to evaluate postfix expression**************/




int evaluate(string &s)
{
  Stack<int> temp,n;
  
  for(int i=0; i<s.length(); i++)
    {
      
        if(isdigit(s[i]))
        temp.push(s[i]-'0');
        else
         {
                int v=0;
                while(!temp.isEmpty())
                v = v*10 + temp.pop();
                if(v!=0)
                n.push(reverse(v));
            
             switch(s[i])
            
              {
            
            
                case '+':
                          n.push(n.pop()+ n.pop());                   
                          break;
                case '-':
                          n.push(n.pop() - n.pop());
                          break;
                case '*':
                          n.push(n.pop() * n.pop());
                          break;
                case '/':
                          n.push(n.pop() / n.pop());
                          break;
              
                         
              }
          
            
        }
        
    
    }
    return n.pop();
    

}



/*************main function**********/



int main()
{
  string str;
  cout<<"\n Enter the Postfix expression \n";
  getline(cin,str); 
  cout<<"\n result :"<<evaluate(str);
}
		
