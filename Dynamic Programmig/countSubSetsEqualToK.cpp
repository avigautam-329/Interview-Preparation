#include<bits/stdc++.h>
using namespace std;

int countSubsets(int *arr, int n, int k, int **dp){
	for(int i = 1; i < n+ 1; i++){
		for(int j = 1; j < k + 1; j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][k];
}

int main(){
	int n , sum;
	cin >> n;
	cin >> sum;
	
	int *arr = new int[n];
	for(int i = 0 ; i < n; ++i){
		cin >> arr[i];
	}
	
	// We need to make the top doum approach dp and initialize it.
	int **dp = new int*[n+1];
	for(int i = 0; i < n+1; ++i){
		dp[i] = new int[sum+1];
		for(int j = 0; j < sum + 1; ++j){
			if(i == 0 && j > 0){
				dp[i][j] = 0;
			}
			
			if(j == 0){
				dp[i][j] = 1;
			}
		}
		
	}
	
	cout << "The number of subsets are : " << countSubsets(arr,n,sum,dp);
	
	return 0;
}
