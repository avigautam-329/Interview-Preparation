#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int lcs(string s1, string s2, int n, int m, int **dp){
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	
	stack<char> ans;
	
	int i = n, j = m;
	while(i > 0 || j > 0){
		if(s1[i-1] == s2[j-1]){
			ans.push(s1[i-1]);
			i--;
			j--;
		}else{
			if(dp[i][j-1] > dp[i-1][j]){
				ans.push(s2[j-1]);
				j--;
			}else{
				ans.push(s1[i-1]);
				i--;
			}
		}
	}
	
	while(!ans.empty()){
		cout << ans.top();
		ans.pop();
	}
	cout << endl;
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	int **dp = new int*[s1.size() + 1];
	
	
	for(int i = 0 ; i < s1.size() + 1; i++){
		dp[i] = new int[s2.size() + 1];
		for(int j = 0; j < s2.size() + 1; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}		
		}
	}
	
	lcs(s1,s2,s1.size(),s2.size(),dp);
	
	return 0;
}
