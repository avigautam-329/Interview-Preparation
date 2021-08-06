#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool solve(string s1, string s2){
	if(s2.size() < s1.size()){
		return false;
	}
	
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
	
	if(dp[n][m] == s1.size()){
		return true;
	}else{
		return false;
	}
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	bool ans = solve(s1,s2);
	if(ans){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}
	
	return 0;
}
