// Implement merge sort in place.
// Steps:
//		1. First we will call the merge sort fucntion where we will divide the array into arr1 and arr2 using pointers.
//		2. When we call the merge function, I am going to use the 'GAP method'.
//		3. In the merge function we will pass the arr, the start pointer, the mid pointer, and the end pointer.

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;


// This is the helper function to find the gap.
int nextGap(int gap){
	if(gap <= 1){
		return 0;
	}
	
	// This is to get the ceil value of the (gap / 2) operation.
	return (gap / 2) + (gap % 2);
}


void merge(int *arr, int start, int mid, int end, int size){
	int i, gap = end - start + 1;
	
	for(gap = nextGap(gap);  gap > 0; gap = nextGap(gap)){
		
		
		// Now since we are not mergeing 2 different arrays, soo we dont need the 3 seperate functions here.
		for(i = start; i + gap <= end; i++){
			if(arr[i] >= arr[i + gap]){
				swap(arr[i] , arr[i + gap]);
			}
		}
	}
	
	return;
}

void mergeSort(int *arr, int start, int end, int size){
	if(start >= end){
		return;
	}
	
	int mid = start + (end - start) / 2;
	
	// Now we will not make different arrays, we will just use the pointers.
	mergeSort(arr , start , mid , size);
	mergeSort(arr , mid + 1, end, size);
	
	merge(arr , start , mid , end , size);
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	// I am passing the start index and the ending index and lastly the size of the array.
	mergeSort(arr , 0 , n - 1, n);
	
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
