#include<bits/stdc++.h>
#include<cstring>
using namespace std;
// Not complete
bool subsetSum(int *arr, int n, int k, int dp[][1001]){
	if(n == 0){
		if(k == 0){
			return true;
		}else{
			return false;
		}
	}
	if(k == 0){
		return true;
	}
	
	if(dp[n][k] > -1){
		return dp[n][k] == 1;
	}
	
	if(k > 0){
		if(arr[n-1] <= k){
			// I have 2 choices.
			// First to include the element.
			if(subsetSum(arr,n-1,k-arr[n-1],dp)){
				dp[n][k] = true;
				return true;
			}
			
			if(subsetSum(arr,n-1,k,dp)){
				dp[n][k] = true;
				return true;
			}
			
		}else{
			return dp[n-1][k];
		}
	}
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
	int dp[101][1001];
	memset(dp,-1,sizeof(dp));
	
	cout << "The subset sum is available : " << subsetSum(arr, n , sum , dp) << endl;;
	
	return 0;
	
}
