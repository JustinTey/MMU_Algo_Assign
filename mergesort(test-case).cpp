#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

void printArray (int *array, int size){
	for (int i = 0; i <= size; ++i)
		cout << array[i] << ' ';
	cout << endl;
}

void merge(int *array, int size, int p,int r){
    
	//Set the temp object size.
    int temp[size];
	
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
	//Test size between 0 to 1000.
	for(int i = 0; i <= size; i++)
		array[i] = i;
	
	//Show original output.
	cout << "Before sort: ";
	printArray(array,size);
					
	//Show sorted output.
	cout << "\n\nAfter sorted: ";
	auto start = chrono::system_clock::now();
	mergeSort(array, size, 0, size);
	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;
			
	printArray(array,size);
	cout << "Duration: " << duration.count() << "s\n";	
}

void worstCase(int *array,int size){
	//Test size between 0 to 1000.
	int range = size;
	for(int i = 0; i <= size; i++){
		array[i] = range;
		range--;
	}
	
	//Show original output.
	cout << "Before sort: ";				
	printArray(array,size);
	
	//Show sorted output.	
	cout << "\n\nAfter sorted: ";
	auto start = chrono::system_clock::now();
	mergeSort(array, size, 0, size);
	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;
			
	printArray(array,size);
	cout << "Duration: " << duration.count() << "s\n";
}

void averageCase(int *array, int size){
	//Test size between 0 to 1000.
	//Init random number generator.
	srand(time(0));
	for(int i = 0; i <= size; i++)
		array[i] = (rand()%1000);
	
	//Show original output.
	cout << "Before sort: ";					
	printArray(array,size);
	
	//Show sorted output.	
	cout << "\n\nAfter sorted: ";
	auto start = chrono::system_clock::now();
	mergeSort(array, size, 0, size);
	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;
			
	printArray(array,size);
	cout << "Duration: " << duration.count() << "s\n";
}

int main(){
	const int size = 1000; 
	int array[size];
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
				
	}
	
	return 0;
}



