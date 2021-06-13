#include<bits/stdc++.h>
using namespace std;

//To merge the divided array.
void merge(int *arr1, int size1, int *arr2,int size2, int output[]){
	int i = 0, j = 0;
	int current = 0;
	
	while(i < size1 && j < size2){
		if(arr1[i] <= arr2[j]){
			output[current] = arr1[i];
			++i;
			current++;
		}else{
			output[current] = arr2[j];
			++j;
			++current;
		}
	}
	
	//Filling the rest of the remaining array.
	while(i < size1){
		output[current] = arr1[i];
		++i;
		++current;
	}
	
	while(j < size2){
		output[current] = arr2[j];
		++j;
		++current;
	}
}

//To divide the array.
void mergeSort(int *arr,int size){
	//Base Case.
	if( size <= 1){
		return;
	}
	
	int mid = size / 2;
	int size1 = mid , size2 = size - mid;
	int *arr1 = new int[size1];
	int *arr2 = new int[size2];
	
	for(int i=0 ; i< size1 ; ++i){
		arr1[i] = arr[i];
	}
	
	int k = 0;
	for(int i = size1 ; i < size ; i++){
		arr2[k] = arr[i];
		++k;
	}
	
	//Calling recursion on the left part.
	mergeSort(arr1,size1);
	
	//Calling recursion on the right part.
	mergeSort(arr2,size2);
	
	//Calling the merge function to merge the arrays.
	merge(arr1,size1,arr2,size2,arr);
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i=0;i<n;++i){
		cin >> arr[i];
	}

	mergeSort(arr, n);
	
	for(int i = 0;i< n;++i){
		cout << arr[i] << " ";
	}
	
	return 0;
}
