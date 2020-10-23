
#include <iostream>

using namespace std;

void min_heapify(int arr[], int n , int i)
{
	int smallest = i; // The node which will be heapified
	int l = 2 * i + 1; // left child node
	int r = 2 * i + 2; // right child node


	if (arr[l] < arr[smallest] && l < n)
		smallest = l;


	if (arr[r] < arr[smallest] && r < n)
		smallest = r;


	if (smallest != i) {
		swap(arr[i], arr[smallest]);

		// Recursively heapify the affected sub-tree
		min_heapify(arr, n , smallest);
	}
}


void buildHeap(int arr[] , int n)
{

	for (int i = n; i >= 0; i--)
    {
		min_heapify(arr, n , i);
	}
}

void decrease_key(int arr[] , int i , int val)
{
    int p = i/2;
    if(val > arr[i])
    {
        cout<<"\nEntered value is larger than already existing value ";
    }
    else
    {

        arr[i]=val;
        while(i >= 0 && arr[p] > val )
        {

            int temp ;
            temp     = arr[p];
            arr[p]   = arr[i];
            arr[i]   = temp;
            i = p;
            p = i/2;
        }
    }
}

void min_heap_insert(int arr[] , int n)
{
    int val;
    cout<<"\nEnter the  value to add: ";
    cin>>val;
    arr[n]=val;
    decrease_key(arr , n , val);
}


void Extract_min_heap(int arr[] , int n)
{
    int minimum;
    minimum = arr[0];
    n = n-1;
    arr[0] = arr[n];
    buildHeap(arr , n);
}
int main()
{
	// Sample array
	int arr[50] , n ;
	cout<<"\nEnter the size of array : ";
	cin>>n;
	for(int i=0 ; i<n ; i++)
    {
        cout<<"\nEnter element "<<i+1<<" : ";
        cin>>arr[i];
    }
	cout << "Array representation before buildHeap is: "<<endl;
	for (int i = 0; i < n; ++i)
	{
	   cout << arr[i] << " ";
	}

	// call the buildheap method on the array
	buildHeap(arr , n);
    cout << "\nArray representation after buildHeap is !!\n\n"<<endl;

    // print the heap
	for (int i = 0; i < n; ++i)
	{
	    cout << arr[i] << " ";
    }

    char choice = 'y';

    do{
        int ch , i , val;

        cout<<"\n---------------------------";
        cout<<"\n1. Decrease key ";
        cout<<"\n2. Minimum of heap ";
        cout<<"\n3. Minimum heap insert ";
        cout<<"\n4. Extract minimum heap ";
        cout<<"\n5. Exit";
        cout<<"\n----------------------------";
        cout<<"\nEnter Your choice : ";
        cin>>ch;

        switch(ch)
        {
           case 1:
                   cout<<"\nEnter the index you want to add value : ";
                   cin>>i;
                   cout<<"\nEnter the value : ";
                   cin>>val;
                   decrease_key(arr , i , val);
                   cout<<"\nAfter decreasing !!\n\n";
                   for(int i=0 ; i<n ; i++)
                   {
                       cout<<arr[i]<<" ";
                   }
                   break;
          case 2:
                   cout<<"\nMinimim of heap is : "<<arr[0];
                   break;
          case 3:
                   min_heap_insert(arr , n);
                   cout<<"\nAfter Insertion !!\n\n";
                   for(int i=0 ; i<=n ; i++)
                   {
                       cout<<arr[i]<<"  ";
                   }
                   break;
          case 4:
                   Extract_min_heap(arr , n );
                   for(int i=0 ; i<n ; i++)
                   {
                       cout<<arr[i]<<" ";
                   }
                   break;
          case 5:
                   exit(0);
          default:
                   cout<<"\nInvalid choice !!!";


       }

        cout<<"\nDo you want to continue (y/n) : ";
        cin>>choice;

    }while(choice == 'y' || choice == 'Y');
    return 0;
}
