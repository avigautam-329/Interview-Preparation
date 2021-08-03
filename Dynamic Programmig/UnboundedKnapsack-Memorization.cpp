#include<bits/stdc++.h>
using namespace std;

int helperFunction(int *val, int *wt, int n, int maxWt, int **dp){
	if(n == 0 || maxWt == 0){
		dp[n][maxWt] = 0;
		return 0;
	}
	
	if(dp[n][maxWt] > -1){
		return dp[n][maxWt];
	}
	
	if(wt[n-1] <= maxWt){
		dp[n][maxWt] = max(val[n-1] + helperFunction(val, wt, n, maxWt - wt[n-1], dp), helperFunction(val,wt,n-1,maxWt,dp));
	}else{
		dp[n][maxWt] = helperFunction(val,wt,n-1,maxWt,dp);
	}
	
	return dp[n][maxWt];
}

int unboundedKnapsack(int *val, int *wt, int n, int maxWt){
	int **dp = new int*[n+1];
	for(int i = 0; i < n+1; ++i){
		dp[i] = new int[maxWt + 1];
		for(int j =0 ; j < maxWt + 1; ++j){
			dp[i][j] = -1;
		}
	}
	
	return helperFunction(val, wt, n, maxWt, dp);
}

int main(){
	int n, maxWt;
	cin >> n;
	cin >> maxWt;
	
	int *val = new int[n];
	int *wt = new int[n];
	
	for(int i = 0; i < n; ++i){
		cin >> val[i];
	}
	
	for(int i = 0; i < n; ++i){
		cin >> wt[i];
	}
	
	int maxProfit = unboundedKnapsack(val,wt,n,maxWt);
	cout << "The maximum profit from an unbounded knapsack is: " << maxProfit;
	return 0;
}
