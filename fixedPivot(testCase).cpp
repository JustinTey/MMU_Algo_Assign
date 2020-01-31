#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generateArray (int A[], int size){
	for(int i = 0; i < size; i++)
		 A[i] = i+1;
}

void generateArray2(int A[], int size){
	srand(1); //time(NULL) for random

	for(int i = 0; i < size; i++)
        A[i] = rand() % 100 + 100;
		// A[i] = rand() % 10000 + 1; //range of 1 to 10000
}

int partition(int arr[], int p, int r, char flag) {
	int pivotIndex;
    int pi;
	int swapIndex;

	if(flag == 'w')
        pivotIndex = p;
    else
        pivotIndex = r;

	pi = arr[r];
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

int quickSelectSort(int A[], int p, int k, int r, char flag){
	if ( p <= r){
		int pi = partition(A, p, r, flag);

		if ( k == pi )
            return A[pi];
		if ( k < pi )
			quickSelectSort (A, p, k, pi - 1, flag);
		else
			quickSelectSort (A, pi + 1, k, r, flag);
	}
}

int main(){
	int k;
	const int ARRAY_SIZE = 10;
	int choice;
	int A[ARRAY_SIZE];

	cout << "1 -- Best case\n2 -- Average case\n3 -- Worst case\n\nSelect the test case: ";
	cin >> choice;

	if(choice < 1 || choice > 3){
         cout << "Invalid choice"<<endl;
         exit(0);
    }

	cout << "Please input the kth smallest element: ";
	cin >> k;

	if(choice == 1 || choice == 3)
        generateArray(A,ARRAY_SIZE);
    else if(choice == 2)
        generateArray2(A,ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++)
        cout << A[i]<<"    ";
    cout << endl;
	auto start = chrono::system_clock::now();
	if(choice == 1)
        cout << "The " << k << "th smallest element is: " << quickSelectSort(A, 0, k - 1, ARRAY_SIZE - 1, 'b') << endl;
    else if(choice == 2)
        cout << "The " << k << "th smallest element is: " << quickSelectSort(A, 0, k - 1, ARRAY_SIZE - 1, 'a') << endl;
    else if(choice == 3)
        cout << "The " << k << "th smallest element is: " << quickSelectSort(A, 0, k - 1, ARRAY_SIZE - 1, 'w') << endl;
	auto end = chrono::system_clock::now();

    for(int i = 0; i < ARRAY_SIZE; i++)
        cout << A[i]<<"    ";
 	chrono::duration<double> duration = end - start;
 	cout << "\nDuration: "<<duration.count()<<endl;
}
