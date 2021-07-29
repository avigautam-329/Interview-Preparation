#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

int helperFunction(int *arr, int si, int ei, vector<vector<int> >& dp){
	if(si == ei){
		dp[si][ei] = 0;
		return 0;
	}
	
	if(dp[si][ei] > -1){
		return dp[si][ei];
	}
	
	int minCost = INT_MAX;
	for(int k = si; k <= ei -1 ; k++){
		int tempAns = helperFunction(arr,si,k,dp) + helperFunction(arr,k+1,ei,dp) + (arr[si-1] * arr[k] * arr[ei]);
		minCost = min(minCost, tempAns);
	}
	
	dp[si][ei] = minCost;
	return minCost;
	
}

int matrixChainMultiplication(int *arr, int size){
	vector<vector<int> > dp(size,vector<int>(size,-1));
	int si = 1;
	int ei = size - 1;
	
	return helperFunction(arr, si, ei, dp);
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
