#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;


// BREAKING USING SCHEME 1. 
int helperFunction(int *arr, int si, int ei){
	// Base case.
	if(si == ei){
		return 0;
	}
	
	// To store the minimum value/cost.
	int minCost = INT_MAX;
	
	// Breaking about k.
	for(int k = si; k <= ei-1 ; k++){
		
		int currentCost = arr[si-1] * arr[k] * arr[ei];
		int tempAns = helperFunction(arr,si,k) + helperFunction(arr,k+1,ei) + currentCost;
		
		minCost = min(minCost, tempAns);  
	}
	
	return minCost;
}

// BREAKING USING SCHEME 2.
// couldnt make this work.
/*
int helperFunction1(int *arr, int si, int ei){
	if(si == ei){
		return 0;
	}
	
	
	int minCost = INT_MAX;
	for(int k = si+1; k < ei ; k++){
		int currCost = arr[si] * arr[k] * arr[ei];
		int tempAns = helperFunction1(arr,si,k) + helperFunction1(arr,k,ei) + currCost;
		
		minCost = min(minCost,tempAns);
	}
	
	return minCost;
}
*/

int matrixChainMultiplication(int *arr, int n){
	int si = 1;
	int ei = n - 1;
	return helperFunction(arr,si,ei);
}

int main(){
	int n;
    cin >> n;
    int* arr = new int[n + 1];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n + 1);

    delete[] arr;
	
	return 0;
}
