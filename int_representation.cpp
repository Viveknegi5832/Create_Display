




#include <iostream>
using namespace std;

template <class T>
class Node
	{public:
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
    
    
template <class T>
	bool Stack<T>:: isEmpty()
  	{
		   if(top == NULL)
    return true;
    else
    return false;
    

  	}



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
		cout<<endl<< n<<" pushed to the stack.";
	}



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



template <class T>
	void Stack<T>:: clear()
	{
		cout << "\nClearing the stack.";
		while(!isEmpty())
			pop();
		cout<<"Done"<<endl;
	}



template <class T>
	void Stack<T>:: display()
	{
		if(isEmpty())
			cout<<"\n \n \n Stack is empty!"<<endl;
		else
		{
			cout<<"\n \n \n below is the Stack<"<<count<<">"<<"\n \n"<<">";
			newnode = top;
			while(newnode != NULL)
			{
				if (newnode == top)
					cout << newnode->data;
				else
					cout<<endl<<">"<< newnode->data;
			 newnode = newnode->next;
			}
			cout << endl;
		}
	}



int main()
{
	Stack<int> stack;
	int r;
	cout << " Demonstration of a Stack<int> with Linked list  \n";
	cout << "\n Pushing elements to stack:\n";
	for(int i=0; i<5; i++)
	{
		r = (rand() % 100 + 1);
		stack.push(r);
		cout << "\n Element at top: " << stack.topelement();
	}
	stack.display();
	
	cout << "\n Popping elements from stack:\n";
	while(true)
	{
		if(stack.topelement() == 0)
			break;
		else
		{
			cout<<"\n Element at the top: "<<stack.topelement();
			cout<<endl<<stack.pop()<<" popped from stack.";
		}
	}

	cout << "\nPushing elements to stack.\n";
	for(int i=0; i<5; i++)
	{
		r = (rand() % 1000 + 1);
		stack.push(r);
		cout << "\nElement at top: " << stack.topelement();
	}
	stack.display();
	return 0;
}








    