#include<bits/stdc++.h>
#include<cstring>
using namespace std;

// Lets write the recursive function first.
int lps(string s1, string s2, int n, int m){
	if(n == 0 || m == 0){
		return 0;
	}
	
	if(s1[0] == s2[0]){
		return 1 + lps(s1.substr(1),s2.substr(1),n-1,m-1);
	}
	else{
		return max(lps(s1,s2.substr(1),n,m-1),lps(s1.substr(1),s2,n-1,m));
	}
}

int main(){
	string a, b;
	cin >> a;
	
	b = a;
	reverse(b.begin(),b.end());
	
	// Now we have the 2 string s for LCS format.
	// Soo , now we can apply LCS directly to it,
	// Just think about through the tabulation approach of lcs.
	// We will uderstand why have we taken the reverse.
	int n = a.size();
	int m = a.size();
	
	cout << "The longest palindromic subsequence is: " << lps(a,b,n,m);
	
	return 0;
}
