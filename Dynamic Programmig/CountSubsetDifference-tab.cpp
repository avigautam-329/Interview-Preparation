#include<bits/stdc++.h>
using namespace std;

void diffSubset(int *arr, int n, int sum, int diff, int **dp){
	for(int i = 1; i < n+1; ++i){
		for(int j = 1; j < sum + 1; ++j){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	for(int i = sum; i >= 0; --i){
		if(sum - (2*i) == diff){
			cout << "The number of subset possible are: " << dp[n][i];
		}
	}
}

int main(){
	int n, diff ,sum = 0;
	cin >> n;
	cin >> diff;
	
	int *arr = new int[n];
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		sum += arr[i];
	}
	
	int **dp = new int*[n+1];
	for(int i = 0; i < n+1; ++i){
		dp[i] = new int[sum+1];
		for(int j = 0; j < sum+1; ++j){
			if(i == 0 && j > 0){
				dp[i][j] = 0;
			}
			if(j == 0){
				dp[i][j] = 1;
			}
		}
	}
	
	diffSubset(arr,n,sum,diff,dp);
	
	return 0;
}
