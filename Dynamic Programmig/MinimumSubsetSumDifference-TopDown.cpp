#include<bits/stdc++.h>
using namespace std;

int minDiff(int *arr, int n, int k, bool **dp){
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < k + 1; ++j){
			if(arr[i-1] <= j){
				// We have 2 options and we just need to see any of the choices will lead to a subset for sum j.
				dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	// Now we have dp filled. So we need to find the maximum sum for sum1.
	//int maxSum1;
	int minimum = INT_MAX;
	for(int i = k/2; i >= 0; --i){
		if(dp[n][i] == true){
			//maxSum = i;
			minimum = k -  (2 * i) ;
			break;
		}
	}
	
	return minimum;
}

int main(){
	int n, sum = 0;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		sum += arr[i];
	}
	
	// Remember we need to minimize (sumOfArray - 2 * Sum1).
	// But for that we need to find all the sums that are possible from the (range 0 to sumOfArray).
	
	bool **dp = new bool*[n+1];
	for(int i = 0; i < n + 1; ++i){
		dp[i] = new bool[sum+1];
		for(int j = 0; j < sum + 1; ++j){
			if(i == 0 && j > 0){
				dp[i][j] = false;
			}
			if(j == 0){
				dp[i][j] = true;
			}
		}
	}
	
	cout << "The minimum subset possible is : " << minDiff(arr,n,sum,dp) << endl;
	
	return 0;
}
