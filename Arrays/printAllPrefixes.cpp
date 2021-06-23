#include<bits/stdc++.h>
using namespace std;

void printAllPrefixes(char input[]){
	// i will be used as the stopping index.
	for(int i = 0; i < strlen(input); ++i){
		
		// j will be used as the starting index.
		for(int  j = 0; j <= i; ++j){
			cout << input[j];
		}
		cout << endl;
	}
	
}


int main(){
	
	char arr[100];
	cin >> arr;
	
	printAllPrefixes(arr);
	
	return 0;
}
