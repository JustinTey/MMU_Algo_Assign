#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

void printArray (int A[], int n ) {
  for (int i = 0; i < n; ++i)
    cout << A[i] << ' ';
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

int main(){
	int size;
	cout << "Enter the array size: ";
	cin >> size;
		
	int array[size];
	
	//Init random number generator.
	srand (time(0));  
	//Assign random number to the array.
	for(int i = 0; i < size; i++)
		array[size] = rand()%RAND_MAX;
	
	auto start = chrono::system_clock::now();
	mergeSort(array, size, 0, size-1);
	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;
	
	printArray(array, size);
	cout << "Duration: " << duration.count() << "s\n";
	
	return 0;
}



