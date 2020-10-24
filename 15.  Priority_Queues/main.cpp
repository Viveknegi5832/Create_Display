#include<iostream>

using namespace std;

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l <= n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r <= n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);


        heapify(arr,  largest , n);
    }
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;


    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, i , n);
    }
}


void heapsort(int a[] , int size)
{

    buildHeap(a , size );
    cout<<"\nMax heap is \n";
    cout<<"\n----------------\n";
    for(int i = 0 ; i<size ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n----------------\n";
    size = size-1;
    while(size >= 0)
    {

        swap(a[0],a[size]);
        size--;
        heapify(a , 0 , size );
    }
}
int main()
{
    int a[40] , size;
    cout<<"\nEnter the size of array : ";
    cin>>size;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"\nEnter element "<<i+1<<" : ";
        cin>>a[i];
    }
    heapsort(a , size );
    cout<<"\nAfter applying heapsort  ";
    cout<<"\n----------------\n";
    for(int i=0 ; i<size ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n----------------\n";
    return 0;
}





//////////////////
