#include <bits/stdc++.h>
#include <cstring>
using namespace std;


// Although this solution should have O(m*n) time complexity.
// This code is not running for only 2 test cases on leetcode.
int helperFunction(string s1, string s2, int n, int m, vector<vector<int> >& dp){
	if(m == 0 || n == 0){
		return 0;
	}
	
	if(dp[n][m] > -1){
		return dp[n][m];
	}
	
	int ans;
	if(s1[0] == s2[0]){
		ans = 1 + helperFunction(s1.substr(1),s2.substr(1),n-1,m-1,dp);
	}else{
		int option1 = helperFunction(s1.substr(1),s2,n-1,m,dp);
		int option2 = helperFunction(s1,s2.substr(1),n,m-1,dp);
		ans = max(option1, option2);
	}
	
	dp[n][m] = ans;
	return ans;
}

int lcsDp(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	
	vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
	
	return helperFunction(s1 , s2 , n , m , dp);
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	//int n = s1.size();
	//int m = s2.size();
	
	cout << "The longest common subsequence is: " << lcsDp(s1,s2) << endl;
	return 0;
}
