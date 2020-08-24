#include <iostream>
using namespace std;

/******************************************
	OrderedLinkedList Class
*******************************************/
class OrderedLL
{
	class Node
	{ public:
		int data;
		Node *next;
	};
	
  public:

  Node *head,*temp2, *temp, *newnode, *tail;

  
	
	      OrderedLL()
	      {
		      head = NULL;
	      }
	
	
      	~OrderedLL()
	      {
		      temp = head;
		      while (temp != NULL)
		       {
			         newnode= temp->next;
	        		 delete temp;
			         temp= newnode;
		       }
	      }


bool isEmpty();
void insert(int data);
void Delete(int data);
void print();





/************MERGE**************/


OrderedLL merge(OrderedLL &list)

	 {
    
		    OrderedLL list1;
	    	list1 = *this;
	    temp = list.head;
	    	while (temp != NULL)
	     	{
	         		list1.insert(temp->data);
		         	temp = temp->next;
		     }
    
		   return list1;
  	}




};

	/*********************isEmpty*************************/
	bool OrderedLL :: isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}

	/************INSERT********************/
	void OrderedLL :: insert(int data)
	{
		newnode = new Node();
		newnode->data = data;
		newnode->next = NULL;
   		if (isEmpty())
	    	{
	       		head = tail = newnode;
	   		}
		  else
	   	{
	     		Node *temp1;
			     if (newnode->data < head->data)
			      {
		         		newnode->next = head;
			          	head = newnode;
		       }
			else if (newnode->data > tail->data)
			      {
		       		tail->next = newnode;
			       	tail = newnode;
		      	}
	     		else
			     {
		      		temp = head;
			      	while (temp!= NULL)
			       	{
				        	temp1 = temp;
			        		temp = temp->next;
			        		if ((newnode->data >= temp1->data) && (newnode->data < temp->data))
				         	{
				           		newnode->next = temp;
					           	temp1->next = newnode;
					         }
			        	}
	     		}

      
	   	}
	}
	
	/******************DELETE_FUNCTION************************/
	void OrderedLL :: Delete(int data)
	{
		bool contains;
		if (!isEmpty())
		{
			if (head->data == data)
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
			}
			else
			{
				temp = head;
				while (temp != NULL)
				{
					    if (temp->data == data)
					      {
					     	  contains = true;
						      if (temp == tail)
				         		{
							           delete temp;
							           newnode->next = NULL;
							           tail = newnode;
						         }
					      	else
						        {
							           newnode -> next = temp->next;
							           delete temp;
							           break;
						         }
				       	}
				     	else
						    contains = false;

				    	 newnode = temp;
					    temp = temp->next;
				}
				 if(!contains)
					cout << "\n List don't have this node";
			}
		}
	}
	
	

  
	
	/*****************PRINT****************************/
	void OrderedLL::  print()
	{
		  cout << "\n ";
		  if (isEmpty())
			 cout << "Linked list is empty";
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


/***********CREATING_LIST********************************/
void  create_list(OrderedLL &list)
{
	char ch1;
	int data;
	do
	{
		cout << "\nEnter node data to be inserted: ";
		cin >> data;
		list.insert(data);

		cout << "Want to insert more nodes? y/n: ";
		cin >> ch1;
	} while (ch1 == 'y');

}





/************DELETE****************/




void del(OrderedLL &list)
{
	char ch1;
	int data;
	do
	{
		if (!list.isEmpty())
		{
			cout << "\nEnter node data to be deleted: ";
			cin >> data;
			list.Delete(data);

			cout << "\nWant to delete more nodes (y/n): ";
			cin >> ch1;
		}
	} while (ch1 == 'y');
}






int main()
{
	OrderedLL list;
	char ch;
	int choice;
	cout << "\n Ordered Linked list demonstration:\n";
	do
	{
		cout << "\n1. Insert\n2. Delete\n3. Merge with another list\n\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			         create_list(list);
			         list.print();
		         	break;
		case 2: 
		         	del(list);
	         		list.print();
	         		break; 
		case 3:
		       	  OrderedLL new_list;
			         cout << "\n Creating  list to be merged...\n\n";
			         create_list(new_list);
           list = list.merge(new_list);
	         		list.print();
		          	break;
		}
		cout << "\n Want to operate more? y/n : ";
		cin >> ch;
	} while (ch == 'y');
	return 0;
}