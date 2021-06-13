#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n){
	int min_pos = 0;
	int current = 0;
	
	
	//Goes on for only n-1 rounds.
	for(int i=0;i<n-1;++i){
		int min_num=INT_MAX;
		for(int j=current;j<n;++j){
			if(arr[j] < min_num){
				min_num = arr[j];
				min_pos = j;
			}
		}
		int temp = arr[current];
		arr[current] = arr[min_pos];
		arr[min_pos] = temp;
		
		current++;
	}
	
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n ; ++i){
		cin >> arr[i];
	}
	
	selectionSort(arr,n);
	
	for(int i = 0; i < n ; ++i){
		cout << arr[i] << " ";
	}
	
	return 0;
}
