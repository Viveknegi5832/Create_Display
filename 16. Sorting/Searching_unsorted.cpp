
#include<iostream>
using namespace std;

int main()
{
    int x , i  , N[] = {10,24,11,67,89,90,58,98};
    int a=sizeof(N)/sizeof(N[0]);
    cout<<"\n\nSize of array is : "<<a;
    cout<<"\n\nGiven Array is !!\n\n";
    for(int i = 0 ; i<a ; i++)
    {
        cout<<N[i]<<" ";
    }
    cout<<"\n\nEnter the Element to Search : ";
    cin>>x;
    int f = 0;
    for( i=0 ; i<a ; i++)
    {
        if(N[i] == x)
        {
            f = 1;
            break;
        }


    }
    if(f == 1)
    {
        cout<<"\nFound at index : "<<i;
    }
    else
    {
        cout<<"\nNot found !!";
    }
}

