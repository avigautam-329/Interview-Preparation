#include<bits/stdc++.h>
using namespace std;

//Implement Binary search Recursively.
int binarySearch(int *arr, int start, int end, int k){
	//Base case
	if(start > end){
		return -1;
	}
	int mid = (start+end)/2;
	
	if(arr[mid] == k){
		return mid;
	}
	
	if(k < arr[mid]){
		return binarySearch(arr,start,mid-1,k);
	}else{
		return binarySearch(arr,mid+1,end,k);
	}
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i=0; i < n;++i){
		cin >> arr[i];
	}
	
	int k;
	cout << "Enter the element to be searched: ";
	cin >> k;
	
	
	int index = binarySearch(arr,0,n-1,k);
	if(index == -1){
		cout << "The element was not found.";
	}else{
		cout << "The element was found at : "<<index;
	}
	
	return 0;
}
