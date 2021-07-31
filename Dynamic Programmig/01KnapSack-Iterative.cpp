#include<bits/stdc++.h>
#include<climits>
#include<cstring>
using namespace std;

int maxProfit(int *val, int *wt, int n, int maxWt){
	// Create a dp array of the appropriate size.
	// The base cases here are the following.
	// If the maxWt is 0 or there is no element to insert.
	
	int **dp = new int*[n+1];
	for(int i = 0; i < n+1; ++i){
		dp[i] = new int[maxWt+1];
		for(int j = 0; j < maxWt+1; ++j){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
		}
	}
	
	// Now we have to fill the rest of the array, Keeping in mind the choice diagram that we have.
	for(int i = 1; i < n+1;++i){
		for(int j = 1; j < maxWt + 1; ++j){
			if(wt[i-1] <= j){
				// I have two choices here, whether to include or exclude.
				// These are the same conditions and logical way that we were implying in the recursion function.
				int option1 = val[i-1] + dp[i-1][j-wt[i-1]];
				int option2 = dp[i-1][j];
				dp[i][j] = max(option1,option2);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][maxWt];
}


int main(){
	
	int n, maxWt;
	cin >> n >> maxWt;
	
	int *val = new int[n];
	int *wt = new int[n];
	for(int i = 0; i < n;i++){
		cin >> val[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> wt[i];
	}
	
	cout << "The maxProfit is : " << maxProfit(val,wt,n,maxWt) << endl;
	return 0;
}
