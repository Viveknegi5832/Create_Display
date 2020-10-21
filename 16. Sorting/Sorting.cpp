
#include<iostream>

using namespace std;

template<class T>
class Sorting
{
       public:

       void Insertion_sort(int n[] , int a);
       void Selection_sort(int n[] , int a);
       void Bubble_sort(int n[] , int a);
       void display(int n[], int a);

};

template<class T>
void Sorting<T> :: Bubble_sort(int n[] , int a)
 {

    for(int i=0 ; i<a ; i++)
    {
        for(int j=0 ; j<a-1-i ; j++)
        {
            if(n[j] > n[j+1])
            {
                int temp = n[j];
                n[j] = n[j+1];
                n[j+1]=temp;
            }
        }
    }

}
template<class T>
void Sorting<T> :: Insertion_sort(int n[] , int a)
{
    int k , j ;
    for(int i=1 ; i<a ; i++)
    {
        k = n[i];
        j = i-1;
        while(j>=0 && n[j]>k)
        {
            n[j+1] = n[j];
            j = j - 1;
        }
        n[j+1] = k;
    }

}

template<class T>
void Sorting<T> :: Selection_sort(int n[] , int a )
{
    int small;
    for(int i = 0 ; i<a ; i++)
    {
        int minindex = i;
        for(int j = i+1 ; j<a-1 ; j++)
        {
            if(n[j]<n[minindex])
            {
                minindex = j;

            }
        }
        int temp = n[minindex];
        n[minindex]=n[i];
        n[i]=temp;


    }
}


template<class T>
void Sorting<T> :: display(int n[] , int a)
{
    cout<<"\nSorted array is !!\n\n";
    for(int i=0 ; i<a ; i++)
    {
        cout<<n[i]<<" ";
    }
}
int main()
{
    char choice;
    int ch;
    Sorting<int> s;
    int n[40] , a ;
    cout<<"Enter the size of list : ";
    cin>>a;
    for(int i=0 ; i<a ; i++)
    {
        cout<<"\nEnter Element "<<i+1<<" : ";
        cin>>n[i];
    }
    do{
        cout<<"\n--------------------------";
        cout<<"\n1.Bubble sort";
        cout<<"\n2.Insertion sort";
        cout<<"\n3.Selection sort";
        cout<<"\n--------------------------";
        cout<<"\n\nEnter Your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                   s.Bubble_sort(n,a);
                   s.display(n,a);
                   break;
            case 2:
                   s.Insertion_sort(n,a);
                   s.display(n,a);
                   break;
            case 3:
                   s.Selection_sort(n,a);
                   s.display(n,a);
                   break;
        }


        cout<<"\nWanna Continue (y/n) : ";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}
