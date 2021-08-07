#include<bits/stdc++.h>
using namespace std;

void findMult(int *arr, int n){
	int totalMult = 1;
	for(int i = 0; i < n ; i++){
		totalMult *= arr[i];
	}
	
	for(int i = 0; i < n; i++){
		arr[i] = (totalMult/arr[i]);
	}
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	findMult(arr,n);
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
