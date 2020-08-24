#include <iostream>

using namespace std;

/******************************************
	SinglyLinkedList Class
*******************************************/

template <typename T>
 class Node
	{
  public:
	 	T data;
		 Node *next;
	};


template<typename T> 
class SinglyLinkedList
{ 
 

	 Node<T> *head, *temp, *newnode, *tail;

  public:


	SinglyLinkedList()
	 {
    		head = NULL;
  	}


	~SinglyLinkedList()
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
	SinglyLinkedList<T> operator+(SinglyLinkedList<T> &list);
};

/***********isEmpty************/


template <typename T>
bool SinglyLinkedList<T>::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

/*********DISPLAY************/


template <typename T>
void SinglyLinkedList<T>::display()
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
void SinglyLinkedList<T>::insert_at_end()
{
	    newnode = new Node<T>();
    	cout << "\n Enter the  data: ";
    	cin >> newnode->data;
	    newnode->next = NULL;
  	if(isEmpty())
	  {
	   	head=tail=newnode;
		 }
	else
	{
	  	tail->next = newnode;
	  	tail=newnode;
	}
	cout << "Inserted!" << endl;
}

/************INSERT_AT_BEGINNING******************/


template <typename T>
void SinglyLinkedList<T>::insert_at_beginning()
{
	    newnode = new Node<T>();
	    cout << "\n Enter the  data: ";
	    cin >>newnode->data;
	    if(isEmpty())
	    {
		      newnode->next = NULL;
		      head=tail=newnode;
		
	    }
    	else
	   {
	     	newnode->next=head;
		     head=newnode;
	   }
	cout << "Inserted!" << endl;
}

/******COUNT*******/


template <typename X>
int SinglyLinkedList<X>::count()
{	int count = 0;
	temp = head;
	while (temp != NULL)
	{		temp=temp->next;		
++count;	}
	return count;}





/************INSERT_IN_BETWEEN*********************/


template <typename T>
void SinglyLinkedList<T>::insert_in_between()
{
	if (!isEmpty())
	{
    int i=1,loc;
	    	cout << "\n Enter the location for new node : ";
		   cin >> loc;
	 	if (loc >(count() + 1) || loc < 1)
			cout << "Not Possible \n";
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
		       		cout << "\n Enter the  data : ";
			       	cin >>newnode->data;
		       		newnode->next = temp->next;
		       	 temp->next = newnode;
		       		cout << "\n Inserted!" << endl;
		      	}
		  }
	}
 	else
		insert_at_end();
}

/***********DELETE_AT_END**************/


template <typename T>
void SinglyLinkedList<T>::delete_at_end()
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
	      		while(temp->next->next!= NULL)
		     	{
		        		temp = temp->next;
			     }
    
			     delete temp->next;
			     temp->next = NULL;
			     tail = temp;
		    }
		      cout << "\n Deleted!";
	  }
}

/***********DELETE_AT_BEGINNING********************/

template <typename T>
void SinglyLinkedList<T>::delete_at_beginning()
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
	     		delete temp;
	    	}
		    cout << "\n Deleted!";
	  }
}

/***********DELETE_IN_BETWEEN*******************/


template <typename T>
void SinglyLinkedList<T>::delete_in_between()
{
	if (!isEmpty())
	{
		int i=1,loc;
		cout<<"\n Enter the location of the node to delete : ";
		cin>>loc;
		if(loc > count() || loc < 1)
			cout<< "\n Invalid location!";
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
			         	temp->next=temp->next->next;
				         delete temp->next;
				         cout << "Deleted from location : " << loc << "!" << endl;
			       }
	      	}
	}
}


/*************DELETE_BY_DATA****************/


template <typename T>
void SinglyLinkedList<T>:: delete_data()
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
					newnode->next = temp->next;
					delete temp;
					break;
				}
				newnode = temp;
		 	temp = temp->next;
			}
			if (!contains)
				cout << "List doesn't have this node already!";
			else
 cout << "Deleted!";
		}
	}


}

/*************SEARCH_NODE**************/


template <typename T>
void SinglyLinkedList<T>::search()
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
			cout << "Data found at location " << loc << " in the list." << endl;
		else
			cout << "Data not found in the list.";
	}
}


/************REVERSE_NODE*****************/

template <typename T>
void SinglyLinkedList<T>::reverse()
{
	if (!isEmpty())
	{
		temp = head->next;
		head->next = NULL;
		tail = head;
		while (temp != NULL)
		{
			newnode = temp;
			temp= temp->next;
			newnode->next = head;
			head = newnode;
		}
		cout << "\nReversed!" << endl;
	}
}

/*************OVERLOAD_OPERATOR*****************/

template <typename X>
SinglyLinkedList<X> SinglyLinkedList<X>::operator+(SinglyLinkedList<X> &list)
{	
  tail->next = list.head;	
  tail = list.tail;	
  return *this;
}




  
int main()
{
	int choice, choice1;
	char ch, ch1='y';
	SinglyLinkedList<int> list, new_list;
	cout << "\nSingly Linked list demonstration: \n";
	do
	{
		cout << " \n1. Insert at beginning \n2. insert at end \n3. insert in between \n4. delete at beginning\n5. delete at end\n6. delete in between\n7. delete by data\n8. display \n9. count nodes \n10. search a node \n11. reverse a node \n12. Concatanate a new list" << endl;
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
            list.reverse();
            break;
   case 12:
           
             cout<<"\n Creating new list to be concatenate ";
             
             do{
            
                new_list.insert_at_end();
                cout<<"\n Want to enter more nodes (y/n): ";
                cin>>ch1;
               }while(ch1=='y');
              cout<<"\n The Newlist is:";
              new_list.display();
              list=list+new_list;
              cout<<"\n Concatenated list:";
              list.display();
              break;
              
    case 13:      
            exit(0);
    default:
    cout<<"\n Invalid Input";
		
		}
		cout << "\n Want to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}
    