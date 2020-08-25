#include <iostream>
using namespace std;


template <typename T>
 class Node
	{
  public:
	 	T data;
		 Node *next,*prev;
	};


template<typename T> 
class DoublyLinkedList
{ 
 

	 Node<T> *head, *temp, *newnode, *tail;

  public:


	DoublyLinkedList()
	 {
    		head = NULL;
  	}


	~DoublyLinkedList()
	{
	     	temp = head;
     		while (temp!= NULL)
    	  	{
		        	newnode = temp->next;
	       	 	delete temp;
	        		temp = newnode;
	     	}
	}


	bool isEmpty();
	int  count();
	void search();
	void reverse();
	void insert_at_end();
	void insert_at_beginning();
	void insert_in_between();
	void delete_at_end();
	void delete_at_beginning();
	void delete_in_between();
	void delete_data();
	void display();
	DoublyLinkedList<T> operator+(DoublyLinkedList<T> &list);
};

/***********isEmpty************/


template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

/*********DISPLAY************/


template <typename T>
void DoublyLinkedList<T>::display()
{
	cout << "\n";
    	if (isEmpty())
   		cout << "Linked List is empty.";
    else
   {
	      temp = head;
      	while (temp!= NULL)
	      {
	   	      cout<<temp->data<<" ";
          temp=temp->next;
      	}
	      cout << endl;
   }

}

/***********INSERT_AT_END***********/


template <typename T>
void DoublyLinkedList<T>::insert_at_end()
{
	    newnode = new Node<T>();
    	cout << "\nEnter the  data: ";
    	cin >> newnode->data;
	    newnode->next = NULL;
  	if(isEmpty())
	  {
	   	head=tail=newnode;
    newnode->prev=NULL;
    
		 }
	 else
	 {
	  	 tail->next = newnode;
    newnode->prev=tail;
	   	tail=newnode;
	 }
	cout<<"\n\nInserted!";
}

/************INSERT_AT_BEGINNING******************/


template <typename T>
void DoublyLinkedList<T>::insert_at_beginning()
{
	    newnode = new Node<T>();
	    cout << "\nEnter the  data: ";
	    cin >>newnode->data;
	    if(isEmpty())
	    {
		      newnode->next = NULL;
		      head=tail=newnode;
       newnode->prev=NULL;
		
	    }
    	else
	   {
	     	newnode->next=head;
      head->prev=newnode;
      newnode->prev=NULL;
		     head=newnode;
	   }
	cout << "\n\nInserted!" << endl;
}

/******COUNT*******/


template <typename T>
int DoublyLinkedList<T>::count()
{	int count = 0;
	temp = head;
	while (temp != NULL)
	{		temp=temp->next;		
++count;	}
	return count;}





/************INSERT_IN_BETWEEN*********************/


template <typename T>
void DoublyLinkedList<T>::insert_in_between()
{
	if (!isEmpty())
	{
    int i=1,loc;
	    	cout<<"\n Enter the location for new node : ";
		   cin>>loc;
	 	if(loc >(count() + 1) || loc < 1)
			cout<<"Not Possible \n";
	 	else 
      if (loc == 1)
		    	insert_at_beginning();
	 	   else
 		  {
	   	  	temp = head;
		     	while(i<loc-1)
		     	{
			       	temp=temp->next;
          i++;
	     		}
		      	if(temp==tail)
	 		     insert_at_end();
		      	else
		      	{
          newnode =new Node<T>();
		       		cout<<"\nEnter the  data : ";
			       	cin>>newnode->data;
		       		newnode->next = temp->next;
          temp->next->prev=newnode;
          temp->next=newnode;
          newnode->prev=temp;
		       		cout<<"\n\nInserted!";
		      	}
		  }
	}
 	else
		insert_at_end();
}

/***********DELETE_AT_END**************/


template <typename T>
void DoublyLinkedList<T>::delete_at_end()
{
	    if (!isEmpty())
	   { 
		       if (head == tail)
		     {
		       	delete tail;
		       	head = NULL;
	      	}
	     	else
		    {
	      	temp = tail->prev;
       delete tail;
			     temp->next = NULL;
			     tail = temp;
		    }
		      cout << "\n Deleted!";
	  }
}

/***********DELETE_AT_BEGINNING********************/

template <typename T>
void DoublyLinkedList<T>::delete_at_beginning()
{
    	if (!isEmpty())
	   {
		    if (head == tail)
		     {
	   	   	delete tail;
	      		head = NULL;
	     	}
		   else
	    	{
		     	temp = head;
	     		head = head->next;
       head->prev=NULL;
	     		delete temp;
	    	}
		    cout << "\n Deleted!";
	  }
}

/***********DELETE_IN_BETWEEN*******************/


template <typename T>
void DoublyLinkedList<T>::delete_in_between()
{
	if (!isEmpty())
	{
		int i=1,loc;
		cout<<"\n Enter the location of the node to delete : ";
		cin>>loc;
		if(loc > count() || loc < 1)
			cout<<"\n Data Not present at this location ";
		else 
      if(loc==1)
		     delete_at_beginning();
		    else
		     {
			       temp = head;
			       while(i<loc-1)
			       {
		         		temp=temp->next;
            i++;
		       	}
		       	if (temp->next==tail)
			       delete_at_end();
		       	else
			       {
            Node<T> *temp1;
            temp1=temp->next;
			         	temp->next=temp1->next;
            temp1->next->prev=temp;
				         delete temp1;
				         cout<<"Deleted from location : "<<loc<<"!";
			       }
	      	}
	}
}


/*************DELETE_BY_DATA****************/


template <typename T>
void DoublyLinkedList<T>:: delete_data()
{
   
   if (!isEmpty())
	{
		T data;
		bool contains = false;
		cout<<"\n Enter the  data to be deleted: ";
		cin>>data;
		if(head->data == data)
			delete_at_beginning();
		else if(tail->data == data)
			delete_at_end();
		else
		{
			temp = head;
			while (temp!= NULL)
			{

   
				if (temp->data==data)
				{
					contains = true;
    newnode=temp->prev;
					newnode->next = temp->next;
    temp->next->prev=newnode;
					delete temp;
					break;
				}

		 	temp = temp->next;
			}
			if (!contains)
				cout<<"This node is not present in the list!";
			else
 cout<<"Deleted!";
		}
	}


}

/*************SEARCH_NODE**************/


template <typename T>
void DoublyLinkedList<T>::search()
{
	if (!isEmpty())
	{
		T data;
		int loc = 0;
		bool contains = false;
		cout<<"\nEnter the node data to be searched : ";
		cin>>data;
		temp = head;
		while (temp!= NULL)
		{
			++loc;
			if (temp->data == data)
			{
				contains = true;
				break;
			}
			temp= temp->next;
		}
		if (contains == true)
			cout<<"Data found at location " << loc << " in the list." << endl;
		else
			cout<<"Data not found in the list.";
	}
}







  
int main()
{
	int choice, choice1;
	char ch, ch1='y';
	DoublyLinkedList<int> list;
	cout << "\n Doubly Linked list  \n";
	do
	{
		cout << " \n1. Insert at beginning \n2. insert at end \n3. insert in between \n4. delete at beginning\n5. delete at end\n6. delete in between\n7. delete by data\n8. display \n9. count nodes \n10. search a node  \n11. exit " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
{
			 	case 1:
			           		list.insert_at_beginning();
			           		break;
			 	case 2:
		           			list.insert_at_end();
				 	          break;
		 		case 3:
					          list.insert_in_between();
				           	break;
		  case 4:
		 				         list.delete_at_beginning();
			 	  	        	break;
			 case 5:
			           list.delete_at_end();
				 	         break;
			 case 6:
				          list.delete_in_between();
				          break;
			 case 7:
			           list.delete_data();
				          break;
		  case 8:
             list.display();
             break;
			 case 9:
            list.count();
            cout<<"\n nodes :"<<list.count();
            break;
   case 10:
            list.search();
            break;
   case 11:
            exit(0);
  
   default:
 
           cout<<"\n Invalid Input";
		
		}
		cout << "\n Want to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}
    