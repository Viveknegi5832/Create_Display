#include <iostream>
#include <stdlib.h>
using namespace std;
#define SIZE 5




template<typename T>
class Stack
{
  	T arr[SIZE];

  	int top;
	
	 public:

	
	 Stack()//constructor
  { 
    top = -1;
  }
	
	bool isempty()
	{
		 if(top < 0)
   return true;
  else
   return false;
	}
	bool push(T data)
	{
		if(top == SIZE-1)
		{
			cout << "\n Stack is full!" << endl;
			return false;
		}
		else
		{
			arr[++top] = data;
  		cout << endl << data << " is pushed(inserted) to the stack ";
			return true;
		}
	}
	
	T pop()
	{
		if(isempty())
		{
			cout << "\n Stack is empty!" << endl;
			return 0;
		}
		else
		{
			int n = arr[top--];
  
			return n;
		}
	}
	
	T topelement()
	{
		if(isempty())
		{
			cout << "\n Stack is empty!" << endl;
			return 0;
		}
		else
			return arr[top];
	}
	
	void clear()
	{
		cout << "\n Removing elements from stack."
      <<endl<<"....."
      <<endl<<".....";
		while(!isempty())
			pop();
		cout<<"\n Removing complete";
	}
	
	void display()
	{
  int i=top;
		if(isempty())
			cout << "\n Stack is empty!" << endl;
		else
		{
			cout << "\n Stack<" << top+1 << "> : ";
			while( i>=0)
			{
   cout<<endl;
				cout << arr[i] << " ";
   i--;
			}
			cout << "«--end" << endl;
		}
	}
};










int main()
{
	Stack<int> stack;
	int a;
	cout << " Demonstrating Stack<int> with Array  \n";
	cout << " \n Pushing(inserting) elements to stack:\n";
	while(true)
	{
		a = (rand()%100 + 1);
		bool flag = stack.push(a);
		if(!flag)
			break;
		else
			cout << "\n Element at top: " << stack.topelement();
	}
	stack.display();
	
	cout << "\n Popping(deleting) elements from stack:\n";
	while(true)
	{
		if(stack.topelement() == 0)
			break;
		else
		{
			cout << "\n Element at top: " << stack.topelement();
			cout << endl << stack.pop() << " popped(deleted)";
		}
	}
	
	cout << "\n Pushing(inserting) elements to stack again...\n";
	while(true)
	{
		a = ( rand() % 100 + 1 );
		bool flag = stack.push(a);
		if(!flag)
			break;
		else
			cout << "\nElement at top: " << stack.topelement();
	}
	stack.display();
	stack.clear();
	return 0;
}