#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

int lps(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	
	int **dp = new int*[n + 1];
	for(int i = 0; i < n + 1; i++){
		dp[i] = new int[m + 1];
		for(int j = 0; j < m + 1; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
		}
	}
	
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	return dp[n][m];
}

int main(){
	string a,b;
	cin >> a;
	b = a;
	reverse(b.begin(),b.end());
	
	cout << "The longest Palindromic Subsequence is: " << lps(a,b);
	return 0;
}
