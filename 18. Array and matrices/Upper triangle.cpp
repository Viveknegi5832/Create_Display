#include<iostream>
using namespace std;


class uppertriangle
{
   public:
   int  size;
   int *arr;

   uppertriangle(int a=10)
   {
      size = a*(a+1)/2;
      if(a!=0)
        arr = new int[size+1];
   }

  ~uppertriangle()
  {
     delete[] arr;
  }
  
  void store(int a, int i , int j , int k);
  void display(int r , int k );
  int retrieve(int d , int e , int k);
};


void uppertriangle :: store(int a , int i , int j , int k)
{
   if(i<0 || i>size || j<0 || j>size)
   {
      cout<<"\nOut of bound !!\n";
   }
   else if(i>j)
   {
      cout<<"\nMust be zero value ";
   }
   else if(i<=j)
   {
      
      arr[k] = a;
      cout<<"Stored : "<<arr[k]<<" at position "<<k<<endl;
     
   }
   

}

void uppertriangle :: display( int r , int k)
{
   for(int i=1 ; i<=r ; i++)
   {
      for(int j=1 ; j<=r ; j++)
      {
         if(i<=j)
         {
           
           cout<<arr[k]<<"  ";
           k++;
         }
         else
         cout<<"0"<<"  ";
      }
      cout<<"\n\n\n";

   }

}

int uppertriangle :: retrieve(int i , int j , int k)
{
  if(i<0 || i>size || j<0 || j>size)
  {
     cout<<"\nEntered index is out of Bound ";
  }
  else if(i>j)
  return 0;
  else 
  return arr[k];
  

}
int main()
{

    int r =0 , c=0 , ele;
    
    cout << "Enter Rows and columns\n";
    cin>>r>>c;
    uppertriangle obj(r);
    if(r!=c)
    {
      cout<<"Both Not Equal !! ";
      exit(0);
    }
    
    
    cout << "Enter Elements of Uppertriangle\n";
    int k=0;
    for(int i=1 ; i<=r; i++)
    {
        for(int j=1 ; j<=r; j++)
        {
           if(j>=i)
           {
            
             cin>>ele;
             obj.store(ele , i , j , k);
             k++;
           }
        }
    }
    
   
    cout << "\nUpper triangle  for given elements would be \n\n";
    obj.display(r,0);
    char ch='y';
    do{
    cout<<"\nEnter the indexes you want to retrieve\n";
    int m , n;
    cin>>m>>n;
    int p=0;
    for(int i=1 ; i<=m ; i++)
    {
       for(int j=1 ; j<=r ; j++)
       {
          if(i<=j)
          p++;
       }
    }
    cout<<endl<<p<<endl;
    int a = obj.retrieve(m,n,p-1);
    cout<<"\n\nValue : "<<a;
    
    cout<<"\nWanna retrieve again? (y/n) : ";
    cin>>ch;
    }while(ch=='y');
    return 0;
}

    