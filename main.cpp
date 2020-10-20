#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);


        heapify(arr, n, largest);
    }
}


void buildHeap(int arr[], int n)  // Function to build a Max-Heap from the given array
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;


    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void increase_key(int arr[] , int ind , int val) // Replace the value of key at ind position with larger value
{
    int p = ind/2;

    if(val < arr[ind])
        cout<<"\nEntered value is smaller than the current one !!";
    else
    {
        arr[ind] = val;
        while( ind>=0 && arr[ind] > arr[p])
        {
            int temp = arr[p];
            arr[p]   = arr[ind];
            arr[ind] = temp;
            ind = p;
            p = ind/2;
        }
    }
}

void max_heap(int arr[]) //Prints the max value of heap or array
{
    cout<<"\nMaximum element : "<<arr[0];
}

void max_heap_insert(int arr[] , int s ) // Enter a new max value to the heap
{
    int value;
    cout<<"\nEnter the value to add : ";
    cin>>value;
    arr[s] = value;
    increase_key(arr , s , value );
}


void Extract_maxheap(int arr[] , int s)
{
   int m;
   m = arr[0];
   s = s-1 ;
   arr[0] = arr[s];
   buildHeap(arr , s-1);

}
int main() // Main function
{
    char ch = 'y' ;
    int s ,  choice , arr[40];
    cout<<"Enter the size of array or heap : ";
    cin>>s;
    for(int i=0 ; i<s ; i++)
    {
        cout<<"\nEnter Element "<<i+1<<" : ";
        cin>>arr[i];
    }
    buildHeap(arr , s);
    cout<<"\nArray after building\n";
    for(int i=0 ; i<s ; i++)
    {
          cout<<arr[i]<<" ";
    }
    do{
        cout<<"\n------------------------";
        cout<<"\n1. Increase key ";
        cout<<"\n2. Maximum of heap ";
        cout<<"\n3. Max heap insert ";
        cout<<"\n4. Extract max heap ";
        cout<<"\n5. Exit ";
        cout<<"\n------------------------";
        cout<<"\n\nEnter your choice : ";
        cin>>choice;

        int ind,val;

        switch(choice)
            {

            case 1:
                    cout<<"\nEnter the index you want to add value : ";
                    cin>>ind;
                    cout<<"\nEnter the value you want to add :";
                    cin>>val;
                    increase_key(arr , ind , val);
                    cout<<"\nArray after increasing key is !!\n\n";
                    for(int i=0 ; i<s ; i++)
                    {

                       cout<<arr[i]<<" ";
                    }
                    break;
            case 2:
                    max_heap(arr);
                    break;
            case 3:
                    max_heap_insert(arr , s );
                    cout<<"\nAfter insertion !!\n\n";
                    for(int i = 0 ; i <= s ; i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                    break;
            case 4:
                    Extract_maxheap(arr , s);
                    cout<<"\nAFter Extracting max. !!\n\n";
                    for(int i = 0 ; i<s ; i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                    break;
            case 5:
                    exit(0);

            default:
                    cout<<"\nInvalid choice Please Reconsider !!";

            }
            cout<<"\nDo You Want to Continue (y/n) : ";
            cin>>ch;

    }while(ch == 'y' || ch == 'Y');

    return 0;

}
