/*
You are given a sentence contained in given string S. Write a function which will replace all the words within the sentence whose length is even and greater than equal to 4, with a space between the two equal halves of the word.
Space complexity should be O(1).

Input Format :
String S

Output Format :
Updated string

Constraints :
1 <= Length of S <= 10000

Sample Input :
Helloo world good morniing

Sample Output :
Hel loo world go od morn iing
*/

#include<bits/stdc++.h>
using namespace std;

// I can pass the mid point of the string in which we want to add space in the mid.
int length(char input[]){
	int count = 0;
	for(int i = 0; input[i] != '\0'; ++i){
		count++;
	}
	return count;
}

void shiftToLeft(char arr[],int startIndex,int stringEnd){
	
	//startIndex is basically the mid. mid being calculated as mid = (start-end)/2.
	int i = stringEnd - 1;
	while(i >=startIndex){
		arr[i+1] = arr[i];
		--i;
	}
	arr[stringEnd + 1] = '\0';
	arr[startIndex] = ' ';
	
    
}

void breakWords(char* input)
{
	int len = length(input);
    
    int start = 0;
    int i = 0;
    for(i = 0; i < len; ++i){
    	if(input[i] == ' '){
    		//This if case is working.
    		
    		// Call to shift characters to the left.
    		if((i - start)%2 == 0 && (i - start) >= 4){
			
    			int mid = (start + i) / 2;
    			shiftToLeft(input, mid, len);
    			start = i+2;
    			++i;
    			len++;
			}else{
				start = i + 1;
			}
    		
		}
	}
    if((i - start)%2 == 0 && (i - start) >= 4){

    	int mid = (start + i) / 2;
    	shiftToLeft(input, mid, len);
    	start = i+2;
    	++i;
    	len++;
	}
    
}

int main(){
	char input[1000];
	cin.getline(input, 1000);
	int len = length(input);
	breakWords(input);
	cout << input << endl;
	return 0;
}
