#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0 ; i< n ; ++i){
		cin >> arr[i];
	}
	
	//Implement BINARY SEARCH.
	int k;
	cout << "Enter the element to be searched: ";
	cin >> k;
	
	bool found = false;
	int start = 0, end = n-1;
	int mid;
	
	while(start <= end){
		mid = (start+end)/2;
		
		if(arr[mid] == k){
			cout << "Element found at position: "<<mid;
			break;
		}
		
		if(k < arr[mid]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	
	return 0;
}
