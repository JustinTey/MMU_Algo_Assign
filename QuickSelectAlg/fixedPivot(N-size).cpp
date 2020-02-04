#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <fstream>
using namespace std;

void generateArray(int A[], int size){
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
	int k, size;
	cout << "Please input the array size: ";
	cin >> size;
	cout << "Please input the kth smallest element: ";
	cin >> k;

	int* A = new int[size];

	// Array of random number
	generateArray(A, size);

	//Write output into a txt for checking purposes
	ofstream outFile;
	outFile.open("check.txt");
	for (int i =0; i < size; i++)
		outFile << A[i] << " ";
	outFile.close();

	// array a, start index p, end index r, target index k
	auto start = chrono::system_clock::now();
	cout << "The " << k << "th smallest element is: " << quickSelectSort(A, 0, k - 1, size - 1) << endl;
	auto end = chrono::system_clock::now();

    delete []A;

 	chrono::duration<double> duration = end - start;
 	cout << "\nDuration: "<<duration.count()<<endl;
}
