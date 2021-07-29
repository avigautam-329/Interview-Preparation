#include<bits/stdc++.h>
#include <cstring>
using namespace std;

int lcs(string s1, string s2){
	if(s1.size() == 0 || s2.size() == 0){
		return 0;
	}
	
	if(s1[0] == s2[0]){
		return 1 + lcs(s1.substr(1),s2.substr(1));
	}else{
		int option1= lcs(s1.substr(1),s2);
		int option2 = lcs(s1,s2.substr(1));
		return max(option1, option2);
	}
}

int main(){
	string s1;
	string s2;
	
	cin >> s1 >> s2;
	
	cout << " The longest commom subsequence : " << lcs(s1,s2);
	
	return 0;
}
