#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int rodCutting(int *length, int *prices, int n, int maxLength){
	int dp[n+1][maxLength + 1];
	memset(dp,0,sizeof(dp));
	
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < maxLength +1; ++j){
			if(length[i-1] <= j){
				dp[i][j] = max(prices[i-1] + dp[i][j - length[i-1]], dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][maxLength];
}

int main(){
	int n , maxLength;
	cin >> n;
	cin >> maxLength;
	
	int *length = new int[n];
	int *prices = new int[n];
	
	for(int i = 0; i < n; ++i){
		cin >> length[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> prices[i];
	}
	
	int maxProfit = rodCutting(length,prices,n,maxLength);
	cout << "The maximum profit out of the max length " << maxLength << " is : " << maxProfit << endl;
	return 0;
}
