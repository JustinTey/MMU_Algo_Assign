#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<random>
using namespace std;

void generateArray (int A[], int size){
	for(int i = 0; i < size; i++)
		 A[i] = i+1;
}

void generateArray2(int A[], int size){
    std::random_device rd;
    std::default_random_engine eng {rd()};
    std::uniform_int_distribution<> dist(0, size);
    for(int i = 0; i < size; i++)
        A[i] = dist(eng);
}

// array a, start index p, end index r
int partition(int arr[], int p, int r) {
	//Fixed pivot = last element of the array
	int pivotIndex = r;

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

	const int ARRAY_SIZE = 10000;
	int* A = new int[ARRAY_SIZE];

	// Array of random number
	generateArray(A, ARRAY_SIZE);

	// array a, start index p, end index r, target index k
	cout << "The " << k << "th smallest element is: " << quickSelectSort(A, 0, k - 1, ARRAY_SIZE - 1) << endl;
}
