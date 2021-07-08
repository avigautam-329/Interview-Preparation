/*
Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always
*/


#include<bits/stdc++.h>
using namespace std;



void reverse(char *input, int startIndex, int endIndex){
	while(startIndex < endIndex){
        char temp = input[startIndex];
        input[startIndex] = input[endIndex];
        input[endIndex] = temp;
        
        startIndex++;
        endIndex--;
    }    
}

int length(char input[]){
	int count = 0;
	for(int i = 0; input[i] != '\0'; ++i){
		count++;
	}
	return count;
}

void reverseStringWordWise(char input[]) {
    // Write your code here
	int len = length(input);
	
	// Reversing the entire String.
	reverse(input,0,len-1);
	
	
	// Now we will reverse each word as soon as we encounter a space.
	
	int startIndex = 0, i = 0;
	while(i < len){
		if(input[i] == ' '){
			reverse(input,startIndex,i-1);
			startIndex = i+1;
			++i;
		}else{
			++i;
		}
	}
	
	// Just to reverse the last word.
	reverse(input,startIndex,i-1);
    
}

int main(){
	char input[1000], output[1000];
	cin.getline(input,1000);
	reverseStringWordWise(input);
	cout << input << endl;
	return 0;
}
