/*
Largest Unique Substring

Given a string S, find the largest substring with no repetition i.e. largest substring which contain all unique characters.

Input Format :
String S

Output Format :
Largest unique substring

Constraints :
1 <= Length os String S <= 10^3

Sample Input:
abcdabceb

Sample Output:
dabce
*/

#include <bits/stdc++.h>
using namespace std;

int length(char input[]){
	int count = 0;
	for(int i=0; input[i] != '\0'; ++i){
		count++;
	}
	return count;
}

// In this function we will return the entire unique substring.
int largestUniqueSubstring(char input[], char output[]){
	int len = length(input);
	
	int start = 0, end = 0;
	
	// To store the length for max.
	int maxUniqueSubstring = 0;
	
	// To store the start and end for max.
	int maxUniqueStart = 0;
	int maxUniqueEnd = 0;
	
	vector<int> lastIndex(256,-1);
	
	while(input[end] != '\0'){
		
		if(lastIndex[input[end]] < start){
			end++;
		}else{
			
			int currentWindowLength = end - start;
			if(currentWindowLength > maxUniqueSubstring){
				maxUniqueSubstring = currentWindowLength;
				maxUniqueStart = start;
				maxUniqueEnd = end; 
			}
			start = lastIndex[input[end]] + 1;
			end++;
		}
		
		lastIndex[input[end - 1]] = end - 1;
		
	}
	
	int currentWindowLength = end - start;
	if(currentWindowLength > maxUniqueSubstring){
		maxUniqueSubstring = currentWindowLength;
		maxUniqueStart = start;
		maxUniqueEnd = end; 
	}
	
	int current = 0;
	for(int i = maxUniqueStart; i < maxUniqueEnd; ++i){
		output[current++] = input[i];
	}
	
	output[current] = '\0';
	
}


int main(){
	char input[1000], output[1000];
	cin.getline(input,1000);
	largestUniqueSubstring(input,output);
	cout << output << endl;
	return 0;
}
