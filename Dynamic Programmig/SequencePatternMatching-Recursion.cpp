#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//complete
bool solve(string s1, string s2,int n, int si, int count){
	if(s1.size() == 0){
		if(count == n){
			return true;
		}else{
			return false;
		}
	}
	
	for(int i = si; i < s2.size(); i++){
		if(s1[0] == s2[i]){
			si = i + 1;
			return solve(s1.substr(1),s2,n,si,count + 1);
		}
	}
	return false;
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	bool ans = solve(s1,s2,s1.size(),0,0);
	if(ans){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}
	
	return 0;
}
