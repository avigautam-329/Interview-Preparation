#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int minDel(string s1,string s2, int n, int m, int **dp){
	if(n == 0 || m ==0){
		dp[n][m] = 0;
		return 0;
	}
	
	if(dp[n][m] != -1){
		return dp[n][m];
	}
	
	if(s1[0] == s2[0]){
		dp[n][m] = 1 + minDel(s1.substr(1),s2.substr(1),n-1,m-1,dp);
	}else{
		dp[n][m] = max(minDel(s1,s2.substr(1),n,m-1,dp),minDel(s1.substr(1),s2,n-1,m,dp));
	}
	return dp[n][m];
}

int main(){
	string s1, s2;
	cin >> s1;
	s2 = s1;
	
	reverse(s2.begin(),s2.end());
	
	int **dp = new int*[s1.size() + 1];
	for(int i = 0; i < s1.size() + 1; i++){
		dp[i] = new int[s2.size() + 1];
		for(int j = 0; j < s2.size() + 1; j++){
			dp[i][j] = -1;
		}
	}
	
	cout << "The min. Number of deletions requierd are: " << s1.size() - minDel(s1,s2,s1.size(),s2.size(),dp) << endl;
	
	return 0;
}
