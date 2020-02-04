#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <fstream>
using namespace std;

void generateArray (int A[], int size){
	for(int i = 0; i < size; i++)
		 A[i] = i+1;
}

int partition(int arr[], int p, int r)
{
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

int quickSelect(int A[],int p,int r,int k){
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
    int ARRAY_SIZE = 10000;
    int *A = new int[ARRAY_SIZE];

	k = 1;

	generateArray(A,ARRAY_SIZE);

	//Write output into a txt for checking purposes
	ofstream outFile;
	outFile.open("check.txt");
	for (int i =0; i < ARRAY_SIZE; i++)
		outFile << A[i] << " ";
	outFile.close();

	// array a, start index p, end index r, target index k
	auto start = chrono::system_clock::now();
	cout << "The " << k << "th smallest element is: " << quickSelect(A, 0, ARRAY_SIZE - 1, k-1) << endl;
	auto end = chrono::system_clock::now();

	delete []A;

    chrono::duration<double> duration = end - start;
 	cout << "\nDuration: "<<duration.count()<<endl;
}


