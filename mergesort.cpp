#include <iostream>
#include <chrono>
using namespace std;

void printArray (int A[], int n) {
	for (int i = 0; i < n; ++i)
		cout << A[i] << ' ';
	cout << endl;
}

void generateArray (int A[], int size){
	srand(time(NULL)); //time(NULL) for random
	for(int i = 0; i < size; i++) {
		 A[i] = rand() % 100 + 1; //range of 1 to 100
	}
}

void merge (int A[], int Temp[], int p, int m, int r) {
	int i, j;
	for (i = m + 1; i > p; i--){
		Temp[i - 1] = A[i - 1];  
	}
	
	for (j = m; j < r; j++) {  
		Temp [r + m - j] = A[j + 1];
	}

	for (int k = p; k <= r; k++){
		if (Temp[j] < Temp [i])	
			A[k] = Temp[j--];		
		else
			A[k] = Temp[i++];	
	}	
} 

void mergesort (int A[], int Temp[], int p, int r) {
	if (p < r) 
	{
		// Divide: divide a into two nearly equal parts.
		int m;
		m = (p + r) / 2;
		// Recur: sort each half.
		mergesort (A, Temp,p, m);
		mergesort (A, Temp,m + 1, r);
		// Conquer: merge the two sorted halves.
		merge (A, Temp,p, m, r);
     }
}

void startMergeSort (int A[], int n) {
	int* Temp = new int[n];
	mergesort (A, Temp, 0, n-1);
	delete [] Temp;
}

int main() {
	const int ARRAY_SIZE = 10;
	int A[ARRAY_SIZE];
	
	// Array of random number
	generateArray(A, ARRAY_SIZE);
	
	cout << "Unsorted array: ";
	printArray(A, ARRAY_SIZE);
	
	startMergeSort(A, ARRAY_SIZE);
	
	cout<< "Sorted array: ";
	printArray(A, ARRAY_SIZE);
}
