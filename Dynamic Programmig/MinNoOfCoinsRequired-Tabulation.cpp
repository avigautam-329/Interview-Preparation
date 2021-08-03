#include<bits/stdc++.h>
using namespace std;

int minCoins(int *coins, int n, int amount){
	// Now we have to create the dp array.
	int dp[n+1][amount+1];
	
	// Inititalize the first row and column of the dp matrix.
	for(int i = 0; i < n + 1; ++i){
		for(int j = 0; j < amount + 1; ++j){
			if(i == 0 && j >= 0){
				dp[i][j] = INT_MAX - 1;
			}
			if(j == 0 && i > 0){
				dp[i][j] = 0;
			}
		}
	}
	
	// Now we have to initialise the second row as well.
	for(int i = 1; i < amount + 1;  ++i){
		if(i % coins[0] == 0){
			dp[1][i] = i / coins[0];
		}else{
			dp[1][i] = INT_MAX - 1;
		}
	}
	
	for(int i = 2; i < n + 1; ++i){
		for(int j = 1; j < amount + 1; ++j){
			if(coins[i-1] <= j){
				dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][amount];
}


int main(){
	int n , amount;
	cin >> n;
	cin >> amount;
	
	int *coins = new int[n];
	for(int i = 0; i < n ; ++i){
		cin >> coins[i];
	}
	
	cout << "The minimum number of coins required are: " << minCoins(coins, n , amount) << endl;
	return 0;
}
