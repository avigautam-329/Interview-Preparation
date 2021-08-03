#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
/*
Shortest Uncommon Subsequence
 
Given two strings S and T, find the length of the shortest subsequence in S which is not a subsequence in T. If no such subsequence is possible, return -1. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. A string of length n has 2^n different possible subsequences.
String S of length m (1 <= m <= 1000) 
String T of length n (1 <= n <= 1000)
 
Examples: 

Input : S = “babab” T = “babba”
Output : 3
The subsequence “aab” of length 3 is 
present in S but not in T.

Input :  S = “abb” T = “abab”
Output : -1
There is no subsequence that is present 
in S but not in T.
*/

int lcSubstring(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	
	int **dp = new int*[n + 1];
	for(int i = 0; i < n + 1; ++i){
		dp[i] = new int[m + 1];
		for(int j = 0; j < m + 1; ++j){
			if(i == 0 ||  j == 0){
				dp[i][j] = 0;
			}
		}
	}
	
	// To store the longest common count.
	// We have made dp[i][j] = 0, as we have found a point of discontinuity(Where the characters of the string do not match).
	int res = INT_MIN;
	for(int i = 1; i < n  + 1 ; ++i){
		for(int j = 1; j < m + 1; ++j){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				res = max(res, dp[i][j]);
			}else{
				dp[i][j] = 0;
			}
		}
	}
	
	return res;
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	cout << "The longest substring is : " << lcSubstring(s1,s2) << endl;
	
	return 0;
}
