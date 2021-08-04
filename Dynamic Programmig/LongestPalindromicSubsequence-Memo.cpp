#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lps(string s1, string s2, int n, int m, int **dp){
	if(n == 0 || m == 0){
		dp[n][m] = 0;
		return 0;
	}
	
	if(dp[n][m] != -1){
		return dp[n][m];
	}
	
	if(s1[0] == s2[0]){
		dp[n][m] = 1 + lps(s1.substr(1),s2.substr(1),n-1,m-1,dp);
	}else{
		dp[n][m] = max(lps(s1,s2.substr(1),n,m-1,dp),lps(s1.substr(1),s2,n-1,m,dp));
	}
	return dp[n][m];
}

int main(){
	string a, b;
	cin >> a;
	b = a;
	reverse(b.begin(),b.end());
	
	int n = a.size();
	int m = n;
	
	int **dp = new int*[n + 1];
	for(int i = 0; i < n + 1; i++){
		dp[i] = new int[m + 1];
		for(int j = 0; j < m + 1; j++){
			dp[i][j] = -1;
		}
	}
	
	cout << "The longest Palindromic Substring is: " << lps(a,b,n,m,dp);
	
	return 0;
}
