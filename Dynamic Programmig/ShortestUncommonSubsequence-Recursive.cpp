#include<bits/stdc++.h>
#include<cstring>
#define MAX 1001
using namespace std;


// Time Complexity is O(2 ^ min(n,m)).
int shortestSubseq(string s1, string s2, int si1 = 0,int si2 = 0){
	// If s2 is zero. Then every element of s1 is uncommon shortest subsequence.
	
	// Since we are starting from the left.
	if(si2 == s2.size()){
		return 1;	
	}
	
	if(si1 == s1.size()){
		return MAX;
	}
	
	// We have 2 options, either we consider the current element or we dont.
	// First if we exclude the current element.
	int option1 = shortestSubseq(s1, s2, si1 + 1, si2);
	
	// If we include the first element.
	// First we need to find the first occurence of the current element in the second string.
	int k = -1;
	for(int i = si2; i < s2.size(); ++i){
		if(s1[si1] == s2[i]){
			k = i;
			break;
		}
	}
	
	// But if didnt find the current element in the other string that means that the current element is the shortest uncommon subsequence itself.
	if(k == -1){
		return 1;
	}
	
	// We have added one because we have considered the current element already in the shortest uncommon subsequence.
	int option2 = 1 + shortestSubseq(s1,s2,si1 + 1, k + 1);
	return min(option1, option2);
}

int main(){
	string s1, s2;
	cin >> s1; 
	cin >> s2;
	
	int n = s1.size();
	int m = s2.size();
	
	cout << shortestSubseq(s1,s2, 0, 0) << endl;
	
	return 0;
}

