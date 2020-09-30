#include <iostream>
using namespace std;


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






/* MAIN FUNCTION */


int main()
{
   int ch;
   char ch1;
   Bst<int> b;

 do{
     
      cout << "\n1. Insert \n2. recursive_inorder \n3. recursive_preorder \n4. recursive_postorder \n5. exit";
      cout << "\n\nEnter your choice : ";
      cin >> ch;
      
      switch(ch)
      {
         case 1:
         
               b.insert();
               break;
        
         case 2:
        
               cout << "\nThe recursive inorder is \n\n ";
               cout << "\n-----------------\n";
               b.recursive_inorder(b.root);
               cout << "\n-----------------\n";
               break;
         case 3:
         
               cout << "\nThe recursive preorder is \n\n ";
               cout << "\n-----------------\n";
               b.recursive_preorder(b.root);
               cout << "\n-----------------\n";
               break;
         case 4:
         
               cout << "\nThe recursive postorder is \n\n ";
               cout << "\n-----------------\n";
               b.recursive_postorder(b.root);
               cout << "\n-----------------\n";
               break;
         case 5:
               
               exit(0);
               break;
         default:
           
               cout << "\nInvalid input !! ";
            
      }

      cout << "\n\nDo you want to continue(y/n) : ";
      cin >> ch1;

   }while(ch1 == 'y' || ch1 == 'Y');
 
 
return 0;

}
    