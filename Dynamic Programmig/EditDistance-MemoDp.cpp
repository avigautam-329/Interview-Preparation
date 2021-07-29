#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int helperFunction(string s1, string s2, int n, int m, vector<vector<int> >& dp){
	if(n == 0){
		return m;
	}
	if(m == 0){
		return n;
	}
	
	if(dp[n][m] > -1){
		return dp[n][m];
	}
	
	int ans;
	
	// We will not do any operation in this case.
	if(s1[0] == s2[0]){
		ans = helperFunction(s1.substr(1),s2.substr(1),n-1,m-1,dp);  
	}else{
		
		// If we subsitute.
		int option1 = 1 + helperFunction(s1.substr(1),s2.substr(1),n-1,m-1,dp);
		
		// If we delete.
		int option2 = 1 + helperFunction(s1.substr(1),s2,n-1,m,dp);
		
		// If we insert.
		int option3 = 1 + helperFunction(s1,s2.substr(1),n,m-1,dp);
		
		ans = min(option1, min(option2,option3));
	}
	
	dp[n][m] = ans;
	return ans;
}

int editDistance(string s1, string s2){
	// We would a need a dp array and the lengths of the strings taken.
	int n = s1.size();
	int m = s2.size();
	
	vector<vector<int> > dp(n+1, vector<int>(m+1,-1));
	
	return helperFunction(s1,s2,n,m,dp);
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}
