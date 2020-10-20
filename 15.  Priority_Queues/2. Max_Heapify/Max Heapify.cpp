

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

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;


    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}



int main()
{
    char ch = 'y' ;
    int s ,  choice , arr[40];
    cout<<"Enter the size of array or heap : ";
    cin>>s;
    for(int i=0 ; i<s ; i++)
    {
        cout<<"\n Enter Element "<<i+1<<" : ";
        cin>>arr[i];
    }
    buildHeap(arr , s);

    cout<<"\nThe Max heapify is !!\n\n";
    for(int i=0 ; i<s ; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;

}
