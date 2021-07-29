#include <bits/stdc++.h>
#include <cstring>
using namespace std;

// We are starting to check form the end of both the given arrays.
// This is the Dp - memorization solution.
int maxProfit(int *val, int *wt, int size, int maxWt, int **dp){
	if(size == 0 || maxWt <= 0){
		dp[size][maxWt] = 0;
		return 0;
	}
	
	if(dp[size][maxWt] > -1){
		return dp[size][maxWt];
	}
	
	// This means we can insert the object.
	if(wt[size-1] <= maxWt){
		int smallAns = max(val[size-1] + maxProfit(val,wt,size-1,maxWt-wt[size-1],dp)
		, maxProfit(val,wt,size-1,maxWt,dp));
		
		dp[size][maxWt] = smallAns;
	}
	else{
		
		// now as the weigt of the current element exceeds tha maximum weight.
		// We automatically do not include the item.
		int smallAns = maxProfit(val,wt,size-1,maxWt,dp);
		dp[size][maxWt] = smallAns;
		return smallAns;
	}
}


int main(){
	int n;
	int maxWt;
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
	
	// I need to define my dp 2D matrix.
	int **dp = new int*[n+1];
	for(int i = 0; i < n+1; i++){
		dp[i] = new int[maxWt + 1];
		for(int j = 0; j < maxWt + 1; j++){
			dp[i][j] = -1;
		}
	}
	
	cout << "The maxProfit for this particular KnapSack is : " << maxProfit(val,wt,n,maxWt,dp);
	
	return 0;
}
