#include<bits/stdc++.h>
using namespace std;

int lcsIterative(char *s1, char *s2){
	int n = strlen(s1);
	int m = strlen(s2);
	
	int **dp = new int*[n + 1];
	for(int i = 0; i < n + 1; ++i){
		dp[i] = new int[m + 1];
	}
	
	// Now we will fill the base cases of the dp array.
	// First we will fill the first column with all zeroes.
	for(int i = 0; i < n + 1 ; ++i){
		dp[i][0] = 0;
	}
	
	// Now we will make the first row all zeroes.
	for(int i = 0; i < m + 1; ++i){
		dp[0][i] = 0;
	} 
	
	// Now we will fill the rest of the left cells in the dp array.
	for(int i = 1; i<=n ; ++i){
		for(int j = 1; j <=m ; ++j){
			if(s1[n - i] == s2[m - j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				int option1 = dp[i-1][j];
				int option2 = dp[i][j-1];
				dp[i][j] = max(option1, option2);
			}
		}
	}
	return dp[n][m];
}

int main(){
	
	char *s1 = new char[100];
	char *s2 = new char[100];
	
	cin >> s1;
	cin >> s2;
	
	cout << "The longest common subsequence is: " << lcsIterative(s1,s2);
	return 0;
}
