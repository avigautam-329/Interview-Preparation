#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

string getMinSubString(string s1, string s2){
	// First we need to store the number of character frequencey for p2.
	unordered_map<char, int> s2Freq;
	unordered_map<char, int> s1Freq;
	string ans = "";
	string temp;
	
	
	// First we will populate the frequency for s2 string.
	for(int i = 0; i < s2.size(); i++){
		s2Freq[s2[i]]++;
	}
	
	// Now we will initialize the variables for out window.
	int desiredCount = s2.size();
	int matchCount = 0;
	int start = -1, end = -1;

	while(true){
		bool f1 = false;
		bool f2 = false;
		
		
		// The loop to acquire characters in the s1Freq map.
		while(end < s1.size() && matchCount < desiredCount){
			end++;
			s1Freq[s1[end]]++;
			if(s1Freq[s1[end]] <= s2Freq[s1[end]]){
				matchCount++;
			}
			
			f1 = true;
		}
		
		// To check the found substring and to release the acquired characters.
		while(start < end && matchCount == desiredCount){
			temp = s1.substr(start + 1, end + 1);
			if(ans.size() == 0 || temp.size() < ans.size()){
				ans = temp;
			}
			
			start++;
			if(s1Freq[s1[start]] == 1){
				s1Freq.erase(s1[start]);
			}else{
				s1Freq[s1[start]]--;
			}
			
			if(s1Freq[s1[start]] < s2Freq[s1[start]]){
				matchCount--;
			}
			
			f2 = true;
		}
		
		if(!f1 && !f2){
			break;
		}
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
