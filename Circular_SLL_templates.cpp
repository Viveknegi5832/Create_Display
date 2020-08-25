#include <iostream>
using namespace std;


template <typename T>
 class Node
	{
  public:
	 	T data;
		 Node *next;
	};


template<typename T> 
class Circular_SLL
{ 
 

	 Node<T>  *temp, *newnode, *tail;

  public:


	Circular_SLL() //Constructor
	 {
    		tail = NULL;
  	}


	~Circular_SLL() //Destructor
	{
      if(!isEmpty())
    {
	     	temp = tail->next;
       tail->next=NULL;
     		while (temp!= NULL)
    	   	{
		        	newnode = temp->next;
	       	 	delete temp;
	        		temp = newnode;
	      	}
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
	
};

/***********isEmpty************/


template <typename T>
bool Circular_SLL<T>::isEmpty()
{
	if (tail == NULL)
		return true;
	else
		return false;
}

/*********DISPLAY************/


template <typename T>
void Circular_SLL<T>::display()
{
	cout << "\n";
    	if (isEmpty())
   		cout << "Linked List is empty.";
    else
   {
	      temp = tail;
      	do
	      {  
          temp=temp->next;
	   	      cout<<temp->data<<" ";
          
      	}while(temp!=tail);
	      cout << endl;
   }

}

/***********INSERT_AT_END***********/


template <typename T>
void Circular_SLL<T>::insert_at_end()
{
	    newnode = new Node<T>();
    	cout<<"\n Enter the  data: ";
    	cin>>newnode->data;
	    newnode->next = NULL;
  	if(isEmpty())
	  {
	   	tail=newnode;
    tail->next=tail;
		 }
	else
	{
   newnode->next=tail->next;
	  	tail->next = newnode;
	  	tail=newnode;
	}
	cout << "Inserted!" << endl;
}

/************INSERT_AT_BEGINNING******************/


template <typename T>
void Circular_SLL<T>::insert_at_beginning()
{
	    newnode = new Node<T>();
	    cout<<"\n Enter the  data: ";
	    cin>>newnode->data;
	    if(isEmpty())
	    {
		      
		      tail=newnode;
        tail->next=tail;
		
	    }
    	else
	   {
	     	newnode->next=tail->next;
		     tail->next=newnode;
	   }
	cout << "Inserted!" << endl;
}

/******COUNT*******/


template <typename T>
int Circular_SLL<T>::count()
{
	int count = 0;
	temp = tail;
do
	{		
   
   temp=temp->next;	
   count++;	
   
	}while(temp!=tail);
	return count;
}





/************INSERT_IN_BETWEEN*********************/


template <typename T>
void Circular_SLL<T>::insert_in_between()
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
	   	  	temp = tail->next;
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
void Circular_SLL<T>::delete_at_end()
{
	    if (!isEmpty())
	   { 
		       if (tail == tail->next)
		     {
		       	delete tail;
		       	tail = NULL;
	      	}
	     	else
		    {
	      		temp = tail->next;
	      		while(temp->next!= tail)
		     	{
		        		temp = temp->next;
			     }
      
			     
			     temp->next = tail->next;
       delete tail;
			     tail = temp;
		    }
		      cout << "\n Deleted!";
	  }
    else
    cout<<"\n List is empty!";
}

/***********DELETE_AT_BEGINNING********************/

template <typename T>
void Circular_SLL<T>::delete_at_beginning()
{
    	if (!isEmpty())
	   {
		    if (tail->next == tail)
		     {
	   	   	delete tail;
	      		tail = NULL;
	     	}
		   else
	    	{
		     	temp = tail->next;
	     		tail->next = temp->next;
	     		delete temp;
	    	}
		    cout << "\n Deleted!";
	  }

   else
   cout<<"\n List is empty!";
}

/***********DELETE_IN_BETWEEN*******************/


template <typename T>
void Circular_SLL<T>::delete_in_between()
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
			       temp = tail->next;
			       while(i<loc-1)
			       {
		         		temp=temp->next;
            i++;
		       	}
		       	if(temp->next==tail)
			       delete_at_end();
		       	else
			       {
            newnode=temp->next;
			         	temp->next=newnode->next;
				         delete newnode;
				         cout << "Deleted from location : " << loc << "!" << endl;
			       }
	      	}
	}
     else
     cout<<"\n List is empty";
}


/*************DELETE_BY_DATA****************/


template <typename T>
void Circular_SLL<T>:: delete_data()
{
   
   if (!isEmpty())
	{
		T data;
		bool contains = false;
		cout<<"\n Enter the  data to be deleted: ";
		cin>>data;
  temp=tail->next;
		if(temp->data == data)
			delete_at_beginning();
		else if(tail->data == data)
			delete_at_end();
		else
		{
			do
			{

   
				if(temp->data==data)
				{
					contains = true;
					newnode->next = temp->next;
					delete temp;
					break;
				}
				newnode = temp;
		 	temp = temp->next;
			}while(temp!=tail);
			if (!contains)
				cout << "List doesn't have this node already!";
			else
 cout << "Deleted!";
		}
	}
  else
  cout<<"\n List is empty!";

}

/*************SEARCH_NODE**************/


template <typename T>
void Circular_SLL<T>::search()
{
	if (!isEmpty())
	{
		T data;
		int loc = 0;
		bool contains = false;
		cout<<"\nEnter the node data to be searched : ";
		cin>>data;
		temp = tail->next;
		do
		{
			++loc;
			if (temp->data == data)
			{
				contains = true;
				break;
			}
			temp= temp->next;
		}while(temp!=tail);
		if (contains == true)
			cout << "Data found at location " << loc << " in the list." << endl;
		else
			cout << "Data not found in the list.";
	}
  else
  cout<<"\n List is empty!";
}


/************REVERSE_NODE*****************/

template <typename T>
void Circular_SLL<T>::reverse()
{
	if (!isEmpty()&&tail->next!=tail)
	{
 Node<T> *temp1;
		temp = tail->next;
		temp1 = temp->next;
		while (temp != tail)
		{
			newnode = temp;
			temp= temp1;
			temp1=temp1->next;
			temp->next = newnode;
		}
  temp1->next=temp;
  tail=temp1;
		cout<<"\nReversed!";
	}
 else
 cout<<"\n List is empty!";
}


  
int main()
{
	int choice, choice1;
	char ch, ch1='y';
	Circular_SLL<int> list;
	cout << "\n Circular Singly Linked list: \n";
	do
	{
		cout<<" \n1. Insert at beginning \n2. insert at end \n3. insert in between \n4. delete at beginning\n5. delete at end\n6. delete in between\n7. delete by data\n8. display \n9. count nodes \n10. search a node \n11. reverse a node \n12. exit";
		cout<<"\n  Enter your choice : ";
		cin>>choice;
		switch(choice)
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
           
            cout<<"\n nodes :"<<list.count();
            break;
   case 10:
            list.search();
            break;
   case 11:
            list.reverse();
            list.display();
            break;
   case 12:
            exit(0);
           
    default:
    cout<<"\n Invalid Input";
		
		}
		cout << "\n Want to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}
    
