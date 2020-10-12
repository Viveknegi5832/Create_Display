/* Vivek singh negi
   19_78066
*/
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
		//cout << "\nClearing the stack.";
		while(!isEmpty())
			pop();
	//	cout<<"Done"<<endl;
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





template <class T>
class Bst
{
     
     class Node
	    {

        public:
        
	      
        T info;
        Node *left,*right;
     };

  

  public:
  T n;
  Node *p,*q,*p1,*root;
  
   Bst()
   {
     root = nullptr;
   }
  ~Bst()
   {

   }

   void insert();
   void recursive_inorder(Node*);
   void recursive_preorder(Node*);
   void recursive_postorder(Node*);
   void itterative_preorder(Node*);
   void itterative_inorder(Node*);
   void itterative_postorder(Node*);
   void search(T n);
};



/* Insert function */




template <class T>
void Bst<T> :: insert()
{
   T i;
  
   char choice;
   cout<<"\nEnter the value or 0 to exit : ";
   cin>>i;
   
   

   do{

        
        
        
        if(root==nullptr)
        {
           root = new Node();
           root->info  = i;
           root->left  = nullptr;
           root->right = nullptr;
        }
        
       else
       {
          p = root;
          q = new Node();
          q->info  = i;
          q->left  = nullptr;
          q->right = nullptr;
        
          while(p != nullptr)
           {
              if(i < p->info)
              {
                p1 = p;
                p  = p->left;
              }
              else
              {
               p1 = p;
               p  = p->right;
              }
           }
        
          if(i < p1->info)
          p1->left  = q;
          else
          p1->right = q;
          cout<<"\nadded !! ";
        
         
      
        
       }
      
      cout<<"\n\nEnter the value or 0 to exit : ";
      cin>>i;
   
      
     }while(i != 0);
    

 }




/* Recursive inorder function */




template <class T>
void Bst<T> :: recursive_inorder(Node* temp)
{
    
    if(temp == nullptr)
      return;
    else
    {
       recursive_inorder(temp->left);
       cout << temp->info<<" ";
       recursive_inorder(temp->right);
    }
    
}




/* Recursive preorder function */




template <class T>
void Bst<T> :: recursive_preorder(Node* temp)
{
 
    if(temp != nullptr)
    {
       cout << temp->info<<" ";
       recursive_preorder(temp->left);
       recursive_preorder(temp->right);
    }
 
}




/* recursive postorder function */




template <class T>
void Bst<T> :: recursive_postorder(Node* temp)
{
   if(temp != nullptr)
   {
      recursive_postorder(temp->left);
      recursive_postorder(temp->right);
      cout << temp->info<<" ";
   }

}



/* Itterative preorder */



template <class T>
void Bst<T> :: itterative_preorder(Node* temp)
{

  Stack<Node*> s1;
  if(temp!=nullptr)
   {
      s1.push(temp);
      while(!s1.isEmpty())
      {
         temp = s1.pop(); //stack se remove
         cout << temp->info << " "; //temp ka info.print
        
         if(temp->right!=nullptr) //preorder mei left pehle aata hai par hum right daalte hai kyuki right pehle jayega jabhi toh jab pop hoga toh pehle bahar ayega
           {
             s1.push(temp->right);
           }
         if(temp->left!=nullptr)
           {
             s1.push(temp->left);
           } 
        }

   }
}




/* Itterative inorder */



template <class T>
void Bst<T> :: itterative_inorder(Node* temp)
{
   Stack<Node*> s1;
   while(temp != nullptr || !s1.isEmpty())
      {
         if(temp != nullptr)
           {
              s1.push(temp);
              temp = temp->left;
           }
        else
           {
              temp = s1.pop();
              cout << temp->info << " ";
              temp = temp->right;
           }
      }

}

/*  Itterative postorder */

 
template <class T>
void Bst<T> :: itterative_postorder(Node* ptr)
    {
        Stack <Node*> s1;
        Stack <Node*> s2;
        s1.push(ptr);
        while(!s1.isEmpty())
        {
            ptr=s1.topelement();
            s1.pop();
            s2.push(ptr);
            if(ptr->left!=NULL)
            {
            s1.push(ptr->left);
            }
            if(ptr->right!=NULL)
            {
            s1.push(ptr->right);
            }
        }
        while(!s2.isEmpty())
        {
            cout<<s2.topelement()->info<<" ";
            s2.pop();
        }
    }




/* Search function */

template <class T>
void Bst<T> :: search(T n)
{
   
    
    Node *temp1;
    Node *temp= root;
    int count = 0 ,flag = 0;
    
    if(root == nullptr)
    cout << "\nTree is empty !!";
    else
    {
        while(temp != nullptr)
         {
            if(temp->info == n)
              {
                 //cout << "\nElement found at level " << count;
                 flag = 1;
                 break;
              }
            else if(n < temp->info)
                {
                   temp = temp->left;
                }
            else
                {
                   temp = temp->right;
                }
            
             ++count;
             
         
         }
        
        if(flag==1)cout<<"\nFound at level "<<count;
        else cout<<"\nNot found";
   }

}









/* MAIN FUNCTION */


int main()
{
   int ch;
   
   char ch1;
   Bst<int> b;

 do{
     
      cout << "\n1.Insert \n2.recursive_inorder \n3.recursive_preorder \n4.recursive_postorder \n5.Itterative preorder \n6.Itterative inorder \n7.Itterative postorder \n8.search an element ";
      cout << "\n\nEnter your choice : ";
      cin >> ch;
      
      switch(ch)
      {
         case 1:
         
               b.insert();
               break;
        
         case 2:
        
               cout << "\nThe recursive inorder is \n";
               cout << "\n-----------------\n";
               b.recursive_inorder(b.root);
               cout << "\n-----------------\n";
               break;
         case 3:
         
               cout << "\nThe recursive preorder is \n";
               cout << "\n-----------------\n";
               b.recursive_preorder(b.root);
               cout << "\n-----------------\n";
               break;
         case 4:
         
               cout << "\nThe recursive postorder is \n";
               cout << "\n-----------------\n";
               b.recursive_postorder(b.root);
               cout << "\n-----------------\n";
               break;
         case 5:
               
               cout << "\nThe Itterative preorder \n";
               cout << "\n-----------------\n";
               b.itterative_preorder(b.root);
               cout << "\n-----------------\n";
               break;
         case 6:
        
               cout <<"\nThe Itterative inorder is \n";
               cout << "\n-----------------\n";
               b.itterative_inorder(b.root);
               cout << "\n-----------------\n";
               break;
        case 7:

               cout<<"\nThe Itterative postorder is \n";
               cout<<"\n----------------\n";
               b.itterative_postorder(b.root);
               cout<<"\n----------------\n";
               break;
        case 8:
        
               cout << "\nEnter the value to search : ";
               cin  >> b.n;
               b.search(b.n);
               break;
        default:
               cout << "\nInvalid input !! ";
            
      }

               cout << "\n\nDo you want to continue(y/n) : ";
               cin >> ch1;

   }while(ch1 == 'y' || ch1 == 'Y');
 
 
return 0;

}
    
