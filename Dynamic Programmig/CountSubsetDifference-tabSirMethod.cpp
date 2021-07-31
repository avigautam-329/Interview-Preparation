#include<bits/stdc++.h>
using namespace std;

void countDiffSubsets(int *arr, int n, int sum, int diff ,int **dp){
	for(int i = 1; i < n+1; ++i){
		for(int j = 1; j < sum + 1; ++j){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	cout << "The number of subsets are: " << dp[n][sum];
}

int main(){
	int n, diff, sum = 0;
	cin >> n >> diff;
	
	int *arr = new int[n];
	for(int i = 0 ; i < n; ++i){
		cin >> arr[i];
		sum += arr[i];
	}
	
	
	// We need to find the number of subsets whose sum is sum1.
	int sum1 = (diff + sum)/2;
	
	int **dp = new int*[n+1];
	for(int i = 0; i < n + 1; ++i){
		dp[i] = new int[sum1 + 1];
		for(int j = 0; j < sum1 + 1; ++j){
			if(i == 0 && j > 0){
				dp[i][j] = 0;
			}
			if(j == 0){
				dp[i][j] = 1;
			}
		}
	}
	
	countDiffSubsets(arr,n,sum1,diff,dp);
	
	return 0;
}
