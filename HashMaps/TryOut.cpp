#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

string getMinSubstring(string s1, string s2){
	int desiredCount = s2.size();
	unordered_map<char, int> s2Freq;
	unordered_map<char, int> s1Freq;
	
	// First we will fill the s2Freq hashmap.
	for(int i = 0; i < s2.size(); i++){
		s2Freq[s2[i]]++;
	}
	
	int start = 0, end = 0;
	int matchCount = 0;
	
	// To store the results.
	string ans = "";
	string temp = "";
	while(end < s1.size()){
		s1Freq[s1[end]]++;
		
		//Now we need to check whether the letter put int hte map is a potential match or not.
		if(s2Freq.find(s1[end]) != s2Freq.end() && s1Freq[s1[end]] <= s2Freq[s1[end]]){
			matchCount++;
			
		}
		
		for(auto x:s1Freq){
			cout << x.first << " " << x.second << endl;
		}
	
		
		if(matchCount == desiredCount){
			while(start < end && matchCount == desiredCount){
				temp = s1.substr(start , end);
				cout << temp << endl;
				if(ans.size() == 0 || temp.size() < ans.size()){
					ans = temp;
				}
				
				s1Freq[s1[start]]--;
				if(s1Freq[s1[start]] < s2Freq[s1[start]]){
					matchCount--;
					cout << matchCount << " " << s1[start] << endl;
				}
			
				if(s1Freq[s1[start]] == 0){
					s1Freq.erase(s1[start]);
				}
				start++;	
			}	
		}

		end++;
	}
	

}

int main(){
	string s1 ,s2;
	getline(cin, s1);
	getline(cin, s2);
	
	string ans = getMinSubstring(s1 ,s2);
	cout << ans << endl;
	return 0;
}
