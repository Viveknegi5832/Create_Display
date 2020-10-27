#include<iostream>
using namespace std;


class lowertriangle
{
   public:
   int  size;
   int *arr;

   lowertriangle(int a=10)
   {
      size = a*(a+1)/2;
      if(a!=0)
        arr = new int[size+1];
   }

  ~lowertriangle()
  {
     delete[] arr;
  }
  
  void store(int a, int i , int j);
  void display(int r);
  int retrieve(int d , int e);
};


void lowertriangle :: store(int a , int i , int j)
{
   if(i<0 || i>size || j<0 || j>size)
   {
      cout<<"\nOut of bound !!\n";
   }
   else if(i<j)
   {
      cout<<"\nMust be zero value ";
   }
   else if(i>=j)
   {
      int k  = i*(i-1)/2 + j - 1 ;
      arr[k] = a;
      cout<<"Stored : "<<arr[k]<<" at position "<<k<<endl;
   }
   

}

void lowertriangle :: display( int r )
{
   for(int i=1 ; i<=r ; i++)
   {
      for(int j=1 ; j<=r ; j++)
      {
         if(i>=j)
         {
           int k = i*(i-1)/2 + j - 1 ;
           cout<<arr[k]<<"  ";
         }
         else
         cout<<"0"<<"  ";
      }
      cout<<"\n\n\n";

   }

}

int lowertriangle :: retrieve(int i , int j)
{
  if(i<0 || i>size || j<0 || j>size)
  {
     cout<<"\nEntered index is out of Bound ";
  }
  else if(i<j)
  return 0;
  else 
  return arr[i*(i-1)/2+j-1];
  

}
int main()
{

    int r =0 , c=0 , ele;
    
    cout << "Enter Rows and columns\n";
    cin>>r>>c;
    lowertriangle obj(r);
    if(r!=c)
    {
      cout<<"Both Not Equal !! ";
      exit(0);
    }
    
    
    cout << "Enter Elements of lefttriangle\n";
    for(int i=1  ; i<=r ; i++)
    {
        for(int j=1 ; j<=i ; j++)
        {
           if(i>=j)
           {
             cin>>ele;
             obj.store(ele , i , j);
           }
        }
    }
    
   
    cout << "\nLower triangle  for given elements would be \n\n";
    obj.display(r);
    cout<<"\nEnter the indexes you want to retrieve\n";
    int m , n;
    cin>>m>>n;
    int a = obj.retrieve(m,n);
    cout<<"\n\nValue : "<<a;
    return 0;
}

    
