#include<bits/stdc++.h>
#include<cstring>
#define MAX 1000

using namespace std;


// x-> starting index of string s1.
// y-> starting index of string s2.
int shortestSubseq(string s1, string s2, int x, int y, int **dp){
	
	// If s1 is zero and we have reached the end.
	if(x == s1.size()){
		return 1000;
	}
	
	// if s2 is zero and we have reached it's end.
	if(y == s2.size()){
		return 1;
	}
	
	// If we have already computed the answer for this case before.
	if(dp[x][y] != -1){
		return dp[x][y];
	}
	
	// Current element is not included.
	int option1 = shortestSubseq(s1, s2, x + 1, y, dp);
	
	//If we want to have the current element.
	int k = -1;
	
	// Loop to find the first occurence.
	for(int i = y; i < s2.size(); i++){
		if(s1[x] == s2[i]){
			k = i;
			break;
		}
	}
	
	if(k == -1){
		dp[x][y] = 1;
		return 1;
	}
	
	int option2 = 1 + shortestSubseq(s1,s2,x + 1, k + 1,dp);
	dp[x][y] = min(option1, option2);
	return dp[x][y];
}

int solve(string s1, string s2) {
	int **dp = new int*[s1.size()];
    for(int i = 0; i < s1.size(); i++){
        dp[i] = new int[s2.size()];
        for(int j = 0; j < s2.size(); j++){
            dp[i][j] = -1;
        }
    }

    return shortestSubseq(s1,s2,0,0,dp);
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	cout << solve(s1,s2) << endl;
	
	return 0;
}
