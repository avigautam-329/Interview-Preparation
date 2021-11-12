#include<iostream>
using namespace std;

void moveNegativeToLeft(int *arr, int n){
	// We will use the 2 pointer method.
	int left = 0;
	int right = n - 1;
	
	while(left <= right){
		// As we want to move the negative elements to the left, soo if we get a negative number on the left and a positive on the right, we swap.
		// If both are negative then we move the left by one to the right.
		// If both are positive we move the right by one to the left.
		// If left is negative and right is positive we move the left pointer to the left by one.
		
		if(arr[left] < 0 && arr[right] < 0){
			left++;
		}else if(arr[left] > 0 && arr[right] < 0){
			swap(arr[left], arr[right]);
			left++;
			right--;
		}else if(arr[left] > 0 && arr[right] > 0){
			right--;
		}else{
			left++;
			right--;
		} 
	}
	return;
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	moveNegativeToLeft(arr , n);
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
