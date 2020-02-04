#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
using namespace std;

void printArray (int *array, int size){
	for (int i = 0; i != size; ++i)
		cout << array[i] << ' ';
	cout << endl;
}

void merge(int *array, int size, int p,int r){

	//Set the temp object size.
    int* temp = new int[size];

	//Midpoint of the array.
	int mid = (p + r)/2;

    int i = p;       // Initial point.
    int j = mid+1;   // Point after midpoint.
    int k = p;       // Initial point for temp

    while((i <= mid) && (j <= r)){
		if(array[i] < array[j]){
            temp[k++] = array[i++];
        }
        else{
            temp[k++] = array[j++];
        }
    }
    while(i <= mid){
        temp[k++] = array[i++];
    }
    while(j <= r){
        temp[k++]  = array[j++];
    }

    //Copy all element from temp(sorted) to original arrays.
    for(int i = p; i <= r; i++){
        array[i] = temp[i];
    }

	delete temp;
	temp = NULL;
}

void mergeSort(int *array, int size, int p, int r){
	//Base case - if array has 1 or 0 elements
	if(p >= r){
		//No need to sort.
		//End the program
		return;
	}

	//Find the midpoint of the array.
	int mid = (p + r)/2;

	mergeSort(array, size, p, mid);
	mergeSort(array, size, mid + 1, r);

	//Merge the two parts.
	merge(array, size, p, r);
}

void bestCase(int *array,int size){
	//Test size between 0 to 10000.
	for(int i = 0; i < size; i++)
		array[i] = i;
}

void worstCase(int *array,int size){
	//Test size between 0 to 10000.
//	int range = size;
//	for(int i = 0; i < size; i++){
//		array[i] = range;
//		range--;
//	}
    int counter = size/2;
    int leftCounter = 0, rightCounter = 0;

    for(int i = 0; i < size; i++){
        if(i % 2 == 0){  //prove is even number
            array[rightCounter+counter] = i;
            rightCounter++;
        }
        else{
            array[leftCounter] = i;
            leftCounter++;
        }
    }
}

void averageCase(int *array, int size){
	//Test size between 0 to 10000.
	//Init random number generator.
	srand(1);
	for(int i = 0; i <= size; i++)
		array[i] = rand()%size;
}

int main(){
	const int size = 500000;
	int* array = new int[size];

	int input;
	cout << "1 -- Best case\n2 -- Average case\n3 -- Worst case\n\nSelect the test case: ";
	cin >> input;

	switch(input){
		case 1:	bestCase(array,size);
			break;

		case 2:	averageCase(array,size);
			break;

		case 3:	worstCase(array,size);
			break;
		default : cout<<"Input incorrect exiting program";
			exit(0);

	}

	//Write output into a txt for checking purposes
	ofstream outFile;
	outFile.open("check.txt");
	for (int i =0; i < size; i++)
		outFile << array[i] << " ";
	outFile.close();

	//retrive k-element to find
	cout<<"Which element would you like to find in the array?"<<endl;
	cin>>input;
	//Show original output.
	//cout << "Before sort: ";
	//printArray(array,size);

	//Show sorted output.
	//cout << "\n\nAfter sorted: ";
	auto start = chrono::system_clock::now();
	mergeSort(array, size, 0, size - 1);
	int answer = array[input-1];
	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;

	//printArray(array,size);
	cout << "Duration: " << duration.count() << "s\n";

	cout<< "Element in position " <<input<<" is "<< answer;
	return 0;
}
