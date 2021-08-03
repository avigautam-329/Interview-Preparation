#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int *val, int *wt, int n, int maxWt){
	
	// Inititalizing dp matrix.
	int **dp = new int*[n+1];
	for(int i = 0; i < n+1; ++i){
		dp[i] = new int[maxWt + 1];
		for(int j =0; j < maxWt + 1; ++j){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
		}
	}
	// Or we can also write : memset(dp,0,sizeof(dp));
	
	// Now we will have to fill the dp matrix.
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < maxWt + 1; ++j){
			if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1] + dp[i][j - wt[i-1]], dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][maxWt];
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
	for(int i = 0 ; i < n ; ++i){
		cin >> wt[i];
	}
	
	int maxProfit = unboundedKnapsack(val,wt,n,maxWt);
	cout << "THE MAX PROFIT IS : " << maxProfit << endl;
	return 0;
}
