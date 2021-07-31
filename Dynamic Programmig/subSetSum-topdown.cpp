#include<bits/stdc++.h>
#include<cstring>
using namespace std;

bool subsetSum(int *arr, int n, int k, bool dp[][1001]){
	// First we build the base conditions.
	for(int i = 0; i < n+1; i++){
		dp[i][0] = true;
	}
	
	for(int i = 1; i < n+1; ++i){
		for(int j = 1; j < k+1; ++j){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
			}else{
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
	
	for(int i = 0 ;i < n; ++i){
		cin >> arr[i];
	}
	
	// Create a dp array for memorization.
	// The 2 changing variables are sum and n.
	bool dp[101][1001];
	memset(dp,false,sizeof(dp));
	
	cout << "The subset sum is available : " << subsetSum(arr, n , sum , dp) << endl;;
	
	return 0;
	
}
