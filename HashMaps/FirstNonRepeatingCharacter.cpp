#include<iostream>
#include<cstring>
using namespace std;

string getNonRepeating(string S) {
    //code here
    unordered_map<char , int> elemFreq;
    unordered_map<char , int> elemIndex;
    
    for(int i = 0; i < S.size(); i++){
        elemFreq[S[i]]++;
        elemIndex[S[i]] = i;
    }
    
    int minPos = INT_MAX;
    for(auto x:elemFreq){
        if(x.second == 1){
            minPos = min(minPos , elemIndex[x.first]);
        }
    }
    string ans = "";
    if(minPos == INT_MAX){
        ans += "-1";
    }else{
        ans = S[minPos];
        ans += " ";
    }
    return ans;
}

int main(){
	string s1;
	cin >> s1;
	
	string ans = getNonRepeating(s1);
	cout << ans << endl;
	return 0;
}
