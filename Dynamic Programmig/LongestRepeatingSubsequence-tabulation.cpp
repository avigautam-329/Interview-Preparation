#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int solve(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	
	int **dp = new int*[n + 1];
	for(int i = 0; i < n + 1; i++){
		dp[i] = new int[m + 1];
		for(int j = 0; j < m + 1; j++){
			if(i == 0 || j ==0){
				dp[i][j] = 0;
			}
		}
	}
	
	for(int i =1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			if(s1[i-1] == s2[j-1] && i != j){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	// THIS IS THE CODE TO PRINT THE LONGEST REPEATING SUBSEQUENCE AS WELL.
	stack<char> ans;
	int i = n, j = m;
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1] && i != j){
			ans.push(s1[i-1]);
			i--;
			j--;
		}else{
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
	}
	while(!ans.empty()){
		cout << ans.top();
		ans.pop();
	}
	cout << endl;
	return dp[n][m];
}

int main(){
	string s1,s2;
	cin >> s1;
	s2 = s1;
	
	//This repeats the length of the longest repeating subsequence.
	cout << "Longest repeating Subsequence: " << solve(s1,s2) << endl;
	
	
	return 0;	
}
