










#include<iostream>
using namespace std;


class Polynomial
{
   class Node
    {
      public:
      int coefficient,power;
      Node *next;
      
    };
    
    public:
    
    Node *head,*temp,*newnode,*tail;
    
    Polynomial() //Constructor for declaring head as NULL
    {
       head=NULL;
    }
    
    ~Polynomial() //Destructor for releasing memory
    {
       
       temp=head;
       while(temp!=NULL) 
        {
          newnode=temp->next;
          delete temp;
          temp=newnode;
        }
        
    }
    
    
    
   
    
    
    
    
    
   
    
    /*************INSERT*****************/
    
    
    
    
    void insert(int a,int b)
    {
      newnode=new Node();
      newnode->coefficient=a;
      newnode->power=b;
      newnode->next=NULL;
    
      if(head==NULL)
      {
         head=tail=newnode;
      }
    
     else
    {
       Node *temp1;
       if(newnode->power > head->power)
       {
           newnode->next=head;
           head=newnode;
       }
     
       else if(newnode->power < tail->power)
              {
                tail->next=newnode;
                tail=newnode;
            
              }
             else
              {
                temp=head;
                while(temp!=NULL)
                 {
                    
                    temp1=temp;
                    temp=temp->next;
                    if(newnode->power==temp1->power)
                     {
                        temp1->coefficient=newnode->coefficient + temp1->coefficient;
                         
                     }
                    else if((newnode->power<temp1->power) && (newnode->power>temp->power))
                      {
                         newnode->next=temp;
                         temp1->next=newnode;
                      }
                  
                 }
              }
            
     }
    
    }
    
    /*************DISPLAY*******************/
    
    
    void display()
    {
      if(head==NULL)
      cout<<"\n 0 ";
         temp=head;
         while(temp!=NULL)
          {
             if(temp!=head)
             cout<<"+";
             if(temp->power==0)
             cout<<temp->coefficient;
             else
             cout<<temp->coefficient<<"x^"<<temp->power;
             temp=temp->next;
         }
    
       
    }
    
    
    /***********OVERLOAD_OPERATOR***********/
    
    Polynomial operator+(Polynomial &p)	
    {	
    	Polynomial poly;		
    poly = *this;	
    	temp = p.head;		
    while(temp != NULL)		
    {		
    	poly.insert(temp->coefficient, temp->power);		
    	temp = temp->next;
    		}
    		return poly;	}
    
    
    
    
    
    
  
};




/*************CREATING_POLYNOMIAL************/

 void create_polynomial(Polynomial &poly)
    {
      int coefficient,power;
      char ch='y';
    
      do{
    
          cout<<"\n \t Enter the coefficient :";
          cin>>coefficient;
          cout<<"\n \t Enter the power:";
          cin>>power;
          poly.insert(coefficient,power);
          
        
          cout<<"\n You can add more terms(y/n):";
          cin>>ch;
        
        }while(ch=='y');
    
    
    
    }



int main()
{

    Polynomial poly1,poly2,poly3;
    cout<<"\n Polynomial 1";
    create_polynomial(poly1);
    cout<<"\n Create poly 2:";
    create_polynomial(poly2);
    cout<<"\n \n •••••••••••••••••••••••• \n \n ";
    cout<<"\n The first polynomial: ";
    poly1.display();
    cout<<"\n \n \n •••••••••••••••••••••••• \n \n \n";
    cout<<"\n The second polynomial: ";
    poly2.display();
    cout<<"\n \n \n •••••••••••••••••••••••• \n \n \n";
    cout<<"\n poly1 + poly2 : ";
    poly3 = poly1 + poly2;
    poly3.display();
    return 0;
}