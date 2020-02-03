#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

void generateArray (int A[], int size){
	for(int i = 0; i < size; i++)
		 A[i] = i+1;
}

void generateArray2(int A[], int size){
	srand(1); //time(NULL) for random

	for(int i = 0; i < size; i++)
        A[i] = rand() % size + 1; // A[i] = rand() % 10000 + 1; //range of 1 to 10000
}

int partition(int arr[], int p, int r) {
	int pivotIndex, pi, swapIndex;

    pivotIndex = r;

	pi = arr[pivotIndex];
	swapIndex = p;
	swap ( arr[pivotIndex], arr[r] );

	for (int i = p; i < r; i++){
		if ( arr[i] < pi ){
			if ( i != swapIndex){
				swap( arr[swapIndex], arr[i] );
			}
			swapIndex++;
		}
	}
	swap ( arr[swapIndex], arr[r] );
	return swapIndex;
}

int quickSelectSort(int A[], int p, int k, int r){
	if ( p <= r){
		int pi = partition(A, p, r);
		if ( k == pi )
            return A[pi];
		if ( k < pi )
			quickSelectSort (A, p, k, pi - 1);
		else
			quickSelectSort (A, pi + 1, k, r);
	}
}

int main(){
	int k, choice;
	const int ARRAY_SIZE = 10000;
	int* A = new int[ARRAY_SIZE];

	cout << "1 -- Best case\n2 -- Average case\n3 -- Worst case\n\nSelect the test case: ";
	cin >> choice;
	
	switch(choice){
		case 1:	generateArray(A,ARRAY_SIZE);
				k = ARRAY_SIZE;
			    break;
			
		case 2:	cout << "Please input the kth smallest element: ";
				cin >> k;
				generateArray2(A,ARRAY_SIZE);
				break;

		case 3:	generateArray(A,ARRAY_SIZE);
				k = 1;
			    break;
				
		default : cout << "Invalid choice"<< endl;
			      exit(0);
	}
	
	//Write output into a txt for checking purposes
	ofstream outFile;
	outFile.open("check.txt");
	for (int i =0; i < ARRAY_SIZE; i++)
		outFile << A[i] << " ";
	outFile.close();

	auto start = chrono::system_clock::now();	
    cout << "The " << k << "th smallest element is: " << quickSelectSort(A, 0, k - 1, ARRAY_SIZE - 1) << endl;
	auto end = chrono::system_clock::now();

 	chrono::duration<double> duration = end - start;
 	cout << "\nDuration: " << duration.count() << endl;
}
