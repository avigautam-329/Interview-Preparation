#include<bits/stdc++.h>
using namespace std;

//Implement Bubble Sort.
void bubbleSort(int *arr, int n){
	for(int i=0; i < n-1;++i){
		for(int j = 0;j<n-1-i ; ++j){
			if(arr[j] > arr[j+1]){
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n ; ++i){
		cin >> arr[i];
	}
	
	//Call bublle sort.
	bubbleSort(arr,n);
	cout << "The sorted array is:" << endl;
	for(int i = 0; i < n ; ++i){
		cout << arr[i] << " ";
	}
		
	return 0;
}
