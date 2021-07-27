#include<bits/stdc++.h>
using namespace std;

/*
	1. Time complexity : O(n). 
	2. Massive improvement over the normal recursion method which has a TC of O(2 ^ n).
*/


long fibdp(long n, long *res){
	// The base case will stay the same.
	if( n== 0 || n == 1){
		return 1;
	}
	// Now we will first check if we have fib(n) in our res array.
	if(res[n] > 0){
		return res[n];
	}
	
	long smallOutput = fibdp(n-1 , res) + fibdp(n - 2 , res);
	
	// Now before returning the output , we should always save it in the res array.
	res[n] = smallOutput;
	return smallOutput;
}

// We can also calclate the nth term through iteration as .
int fibi(int n){
	int *arr = new int[n + 1];
	arr[0] = 1;
	arr[1] = 1;
	
	for(int i = 2; i < n + 1; ++i){
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	
	int output = arr[n];
	delete [] arr;
	return output;
} 


int main(){
	long n;
	cin >> n;
	
	// To store all the fibonacci numbers till n.
	long *res = new long[n + 1];
	for(int i = 0; i < n + 1; ++i){
		res[i] = 0;
	}
	
	cout << fibdp(n, res) << endl; 
	
	cout << "Answer through iteration : " << fibi(n);
	return 0;
}
