//RECOVER ARRAY
/*
	1.First we will find out the mid and see if it is odd or even.
	2.Next we will set up the left and right values accordingly.
	3.Using a while loop we will iterate the values to revocer the arrays till a certain flag variable reaches the length value of the array.
*/
#include<bits/stdc++.h>
using namespace std;


void recoverArray(int n, int input[], int output[]){
	int left,right;
	int mid = n / 2;
	int i = 0;
	
	if(n % 2 != 0){
		output[mid] = input[i];
		++i;
		left = mid - 1;
		right = mid + 1;
	}else{
		left = mid - 1;
		right = mid;
	}
	
	while(i < n){
		output[left] = input[i];
		--left;
		++i;
		output[right] = input[i];
		++right;
		++i;
	}
}


int main(){
	int n;
	cin >> n;
	int *input = new int[n];
	int *output = new int[n];
	
	for(int i=0;i<n;++i){
		cin >> input[i];
	}
	
	recoverArray(n,input,output);
	
	cout << "The recovered array is:" << endl;
	for(int i=0; i < n ; ++i){
		cout << output[i] << " ";
	}
	
	return 0;
}
