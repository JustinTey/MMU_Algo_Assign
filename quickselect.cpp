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
	srand(time(0)); //time(NULL) for random
	for(int i = 0; i < size; i++)     
	{
		 A[i] = rand() % 100 + 1; //range of 1 to 100
	}
}

// array a, start index p, end index r
int partition(int arr[], int p, int r) {
	//Fixed pivot = last element of the array
	//int pivotIndex = r;
	
	//Random pivot = random number from r to p;
	int pivotIndex = rand() % r + p;
	
	//No matter what the random pivot is, swap it to the last element
	swap ( arr[pivotIndex], arr[r] );
	int pi = arr[r];
	int swapIndex = p;
	
	for (int i = p; i < r; i++){
		//Check that if the element is larger than pi, swap and put it behind pivot
		if ( arr[i] < pi ){
			if ( i != swapIndex){
				swap( arr[swapIndex], arr[i] );
			}				
			//Specify the array index of a number larger than the pivot
			swapIndex++;
		}		
	} 
	swap ( arr[swapIndex], arr[r] );
	return swapIndex;
} 

// array a, start index p, end index r, target index k
int quickSelectSort(int A[], int p, int k, int r){
	if ( p <= r){		
		//Partition the array into two sides (needs to know the index of pivot)
		int pi = partition( A, p, r);
		///Three cases:
		//if k == pivot -> already found kth smallest
		//if k < pivot -> only check the left side
		//if k > pivot -> only check the right side
		
		if ( k == pi ) { return A[pi];} //Stop the recursion
		
		if ( k < pi ){
			quickSelectSort (A, p, k, pi - 1); 
		}
		else{
			quickSelectSort (A, pi + 1, k, r);
		}	
	}
}

int main(){
	int k;
	cout << "Please input the kth smallest element: ";
	cin >> k;
	
	const int ARRAY_SIZE = 9;
	int A[ARRAY_SIZE] = { 31, 77, 4, 96, 42, 94, 55, 91, 66 };
	
	// Array of random number
	//generateArray(A, ARRAY_SIZE);
	
	cout << "Unsorted array: ";
	printArray(A, ARRAY_SIZE);
	
	// array a, start index p, end index r, target index k
	cout << "The " << k << "th smallest element is: " << quickSelectSort(A, 0, k - 1, ARRAY_SIZE - 1) << endl;
	printArray(A, ARRAY_SIZE);
}