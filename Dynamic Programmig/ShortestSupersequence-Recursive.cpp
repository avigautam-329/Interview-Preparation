// Worst case time complexity for shortest supersequence is using recursion.
#include<iostream>
#include<cstring>

using namespace std;


// Time Complexity = O(2 ^ min(n,m)).
int shortestSuperSeq(string s1, string s2, int n, int m){
	if(n == 0){
		return m;
	}
	if(m == 0){
		return n;
	}
	
	// If the current element is equal, then we take its occurence only once in the supersequence.
	if(s1[n-1] == s2[m-1]){
		return 1 + shortestSuperSeq(s1,s2,n-1,m-1);
	}
	else{
		return 1 + min(shortestSuperSeq(s1,s2,n,m-1),shortestSuperSeq(s1,s2,n-1,m));
	}
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	int n = s1.size();
	int m = s2.size();
	
	cout << shortestSuperSeq(s1,s2,n,m) << endl;
	return 0;
}
