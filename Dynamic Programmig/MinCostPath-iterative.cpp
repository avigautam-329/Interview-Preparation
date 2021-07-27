#include<bits/stdc++.h>
using namespace std;

int minCostPath(vector<vector<int> >& grid, int n, int m, vector<vector<int> >& dp){
	// Now we will fill the base case of dp.
	// Filling the last column.
	for(int i = n-2; i >=0 ; --i){
		dp[i][m-1] = dp[i+1][m-1] + grid[i][m-1];
	}
	
	// Filling the last row.
	for(int j = m-2; j>=0 ; --j){
		dp[n-1][j] = dp[n-1][j+1] + grid[n-1][j];
	}
	
	// Now we will fill the entire array row wise.
	for(int i = n - 2; i >=0 ; --i){
		for(int j = m - 2;j >= 0; --j){
			dp[i][j] = grid[i][j] + min(dp[i+1][j], min(dp[i+1][j+1],dp[i][j+1]));
		}
	}
	
	return dp[0][0];
}

int main(){
	int n,m;
	cin >> n >> m;
	
	vector<vector<int> > grid(n,vector<int>(m,0));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> grid[i][j];
		}
	}
	
	//Now we will create the dp array(tabulation).
	vector<vector<int> > dp(n,vector<int>(m,0));
	dp[n-1][m-1] = grid[n-1][m-1];
	
	cout << "The min Cost Path is : " << minCostPath(grid,n,m,dp) << endl;
	
	return 0;
}
