#include<iostream>
#include<cstring>
using namespace std;

int lcs(string s1, string s2, int n, int m, int **dp){
	if(n == 0 || m == 0){
		dp[n][m] = 0;
		return 0;
	}
	
	if(dp[n][m] != -1){
		return dp[n][m];
	}
	
	if(s1[0] == s2[0]){
		dp[n][m] = 1 + lcs(s1.substr(1),s2.substr(1), n-1, m-1, dp);
	}else{
		dp[n][m] = max(lcs(s1.substr(1),s2, n-1, m, dp),lcs(s1,s2.substr(1), n, m-1, dp));
	}
	
	return dp[n][m];
}

pair<int, int> minDelInsert(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	
	int **dp = new int*[n + 1];
	for(int i = 0; i < n + 1; i++){
		dp[i] = new int[m + 1];
		for(int j = 0; j < m + 1; j++){
			dp[i][j] = -1;
		}
	}
	
	int lcsLength = lcs(s1,s2,n,m,dp);
	pair<int, int> ans;
	ans.first = n - lcsLength;
	ans.second = m - lcsLength;
	return ans;
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	pair<int ,int> p1;
	p1 = minDelInsert(s1,s2);
	cout << "No. of Deletions : " << p1.first << endl;
	cout << "No. of Insertions : " << p1.second << endl;
	
	return 0;
}
