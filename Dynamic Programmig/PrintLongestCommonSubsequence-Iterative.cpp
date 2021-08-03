#include<iostream>
#include<cstring>
#include<stack>
using namespace std;


void printLCS(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	
	stack<char> ans;
	
	// Now we have filled our tabulation matrix.
	for(int i = 1; i < n + 1; ++i){
		for(int j = 1; j < m + 1; ++j){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	// Now we need to traverse the tabulation array to find the longest common subsequence.
	// Meaning what all characters form the LCS.
	int i = n, j = m;
	while(i != 0 || j != 0){
		if(s1[i-1] == s2[j-1]){
			ans.push(s1[i-1]);
			
			// Move left diagonally.
			--i;
			--j;
		}else{
			if(dp[i-1][j] > dp[i][j-1]){
				--i;
			}else{
				--j;
			}
		}
	}
	
	//Print in correct order.
	while(!ans.empty()){
		cout << ans.top();
		ans.pop();
	}
	cout <<endl;
	return;
}

int main(){
	string s1;
	string s2;
	
	cin >> s1;
	cin >> s2;
	
	printLCS(s1,s2);
	//cout << ans << endl;
	return 0;
}
