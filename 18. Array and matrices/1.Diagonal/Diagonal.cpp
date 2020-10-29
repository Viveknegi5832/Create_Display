//Vivek Singh Negi
//19/78066

#include<iostream>

using namespace std;


class Diagonal
{
   public:
   int  size;
   int *arr;

   Diagonal(int a=10)
   {
      size = a;
      if(a!=0)
        arr = new int[size];
   }

  ~Diagonal()
  {
     delete[] arr;
  }
  
  void store(int a, int i , int j);
  void display();
  int retrieve(int d , int e);
};


void Diagonal :: store(int a , int i , int j)
{
   if(i<0 || i>size || j<0 || j>size)
   {
      cout<<"\nOut of bound !!\n";
   }
   else if(i!=j)
   {
      cout<<"\nMust be zero value ";
   }
   else if(i==j)
   {
      arr[i] = a;
   }
   

}

void Diagonal :: display()
{
   for(int i=0 ; i<size ; i++)
   {
      for(int j=0 ; j<size ; j++)
      {
         if(i==j)
         cout<<arr[i]<<"  ";
         else
         cout<<"0"<<"  ";
      }
      cout<<"\n\n";

   }

}

int Diagonal :: retrieve(int i , int j)
{
  if(i<0 || i>size || j<0 || j>size)
  {
     cout<<"\nEntered index is out of Bound ";
  }
  else if(i!=j)
  return 0;
  else 
  return arr[i];
  

}
int main()
{

    int r =0 , c=0 , ele;
    
    cout << "Enter Rows and columns\n";
    cin>>r>>c;
    Diagonal obj(r);
    if(r!=c)
    {
      cout<<"Both Not Equal !! ";
      exit(0);
    }
    
    
    cout << "Enter Elements of Diagonal\n";
    for(int i=0 , j=0 ; i<r , j<r ; i++,j++)
    {
      cin>>ele;
      obj.store(ele , i , j);
    }
    cout << "\nDiagonal array for given elements would be \n";
    obj.display();
    cout<<"\nEnter the indexes to retrieve \n\n";
    int m,n;
    cin>>m>>n;
    int z = obj.retrieve (m,n);
    cout<<"\nValue : "<<z;
    return 0;
}

