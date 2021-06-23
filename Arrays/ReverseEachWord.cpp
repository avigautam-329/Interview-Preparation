#include<bits/stdc++.h>
using namespace std;


//This is my code where I have not done the operation on the main string as it is. Just printed the output.
void reverseEachWord(char input[]) {
    // Write your code here
    stack<char> substring;
    for(int i=0; i < strlen(input);++i){
        if(input[i] != ' '){
            substring.push(input[i]);
        }else{
            
            while(!substring.empty()){
                cout << substring.top();
                substring.pop();
                
            }
            
            cout << ' ';
        }
    }
    while(!substring.empty()){
        cout << substring.top();
        substring.pop();
    }
}

int main(){
	char arr[500];
	cin.getline(arr,100);
	
	reverseEachWord(arr);
	return 0;
}
