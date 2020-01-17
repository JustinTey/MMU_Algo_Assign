#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void printArray (int A[], int n ) {
  for (int i = 0; i < n; ++i)
    cout << A[i] << ' ';
  cout << endl;
}

void generateArray (int A[], int size){
	srand(time(NULL)); //time(NULL) for random
	for(int i = 0; i < size; i++)
	{
		 A[i] = rand() % 100 + 1; //range of 1 to 100
	}
}

// array a, start index p, end index r
int partition(int arr[], int p, int r)
{
    int pivotIndex = rand() % (r + 1);
    int pivot;
    int swapIndex;

    if(pivotIndex < p && pivotIndex + p <= r)
         pivotIndex = pivotIndex + p;
    else if (pivotIndex < p)
        pivotIndex = p;

    pivot = arr[pivotIndex];

    //swap to last element
    swap(arr[pivotIndex],arr[r]);
    swapIndex = p;

	for (int i = p; i < r; i++){
		//Check that if the element is larger than pi, swap and put it behind pivot
		if ( arr[i] < pivot ){
            swap( arr[swapIndex], arr[i] );
			//Specify the array index of a number larger than the pivot
			swapIndex++;
		}
	}
	swap ( arr[swapIndex], arr[r] );
	return swapIndex;
}

int quickSelect(int A[],int p,int r,int k){ // array A, start index p, end index r, target smallest k
    int pi;

    if(p <= r){
        pi = partition(A,p,r);

        if(k == pi)
            return A[pi];
        if(k < pi)
            quickSelect(A,p,pi-1,k);
        else
            quickSelect(A,pi+1,r,k);
    }
}

int main(){
    int k;
    int size = 9;
    int A[size] = { 77, 99, 22, 66, 55, 44, 11, 88, 33 };
    //int A[size] = { 31, 77, 4, 96, 42, 94, 55, 91, 66 };
	cout << "Please input the kth smallest element: ";
	cin >> k;

	cout << "Unsorted Array: " <<endl;
	printArray(A,size);

	// array a, start index p, end index r, target index k
	cout << "The " << k << "th smallest element is: " << quickSelect(A, 0, size - 1, k-1) << endl;
	printArray(A, size);
}

