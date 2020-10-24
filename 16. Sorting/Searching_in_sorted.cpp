#include <iostream>

using namespace std;

int binary(int a[]  , int size , int ele)
{
   int high = size-1;
   int low = 0;
   int flag = -1;

  while(low <= high)
  {
   int   mid = (low + high)/2 ;
   if(ele == a[mid])
    {
          flag = 1;
          break;
    }
   else if(ele < a[mid])
   {
       low = 0;
       high = mid - 1;
   }
   else if(ele > a[mid])
   {
       low = mid + 1;
       high = high;
   }


 }
  return flag;
}

int main()
{
    int   a[] = {1,2,3,4,5,6,7,8,9,200};
    int n = sizeof(a)/sizeof(a[0]);
    int ele , i;
    cout<<"\nGiven array is ";
    for( i=0 ; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
    char ch = 'y';
    do{

        cout<<"\nENter the element to search : ";
        cin>>ele;
        int result = binary(a , n , ele);
        (result == -1) ? cout<<"\n---------Not Found--------" : cout<<"\n------ELement Found------- ";
        cout<<"\n\nDo you wanna search more Element? (y/n) : ";
        cin>>ch;
    }while(ch == 'y');

    return 0 ;


}
