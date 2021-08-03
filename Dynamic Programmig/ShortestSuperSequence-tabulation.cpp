// Easiest solution of length of shortest superSequence.
#include<iostream>
#include<cstring>

using namespace std;

int shortestSuperSeq(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	
	// Worst case length of supersequence.
	// We want to minimize this.
	// Soo, we remove the recurring characters.
	int maxLength = n + m;
	
	// We can find the longest common subsequence and remove its occurence once. Soo that those elements only occur once.
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	return maxLength - dp[n][m];
}

int main(){
	string s1,s2;
	cin >> s1;
	cin >> s2;
	
	cout << "The shortest common superSequence possible is : " << shortestSuperSeq(s1,s2);
	
	return 0;
}
