#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

string getMinSubString(string s1, string s2){
	// First we need to store the number of character frequencey for p2.
	unordered_map<char, int> s2Freq;
	unordered_map<char, int> s1Freq;
	string ans = "";
	string temp = "";
	
	// First we will populate the frequency for s2 string.
	for(int i = 0; i < s2.size(); i++){
		s2Freq[s2[i]]++;
	}
	
	// Now we will initialize the variables for out window.
	int matchCount = 0;
	int start = -1, end = 0;

	
	
	while(end < s1.size()){
		
		s1Freq[s1[end]]++;
		if(s2Freq.find(s1[end]) != s2Freq.end() && s1Freq[s1[end]] <= s2Freq[s1[end]]){
			matchCount++;
		}
		if(matchCount == s2.size()){
			// Now we will start to release the characters till we don't loose a needed character.
			while(end > start && matchCount == s2.size()){
					
				s1Freq[s1[start]]--;
					
				if(s2Freq.find(s1[start]) != s2Freq.end() && s1Freq[s1[start]] < s2Freq[s1[start]]){
					matchCount--;
						
					// Now we need to check whether this is the potenstial answer or not.
					temp = s1.substr(start , end);
					if(ans.size() == 0 || temp.size() < ans.size()){
						ans = temp;
					}
				}
					
				if(s1Freq[s1[start]] == 0){
					s1Freq.erase(s1[start]);
				}
				start++;
			}
		}
		
		end++;
		
	}
	return ans;
}

int main(){
	string s1 , s2;
	cin >> s1 >> s2;
	
	string ans = getMinSubString(s1 ,s2);
	cout << ans;
	return 0;
}
