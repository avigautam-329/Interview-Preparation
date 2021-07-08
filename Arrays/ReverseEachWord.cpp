/*
Code : Reverse each word

Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.

Example:
Input Sentence: "Hello, I am Aadil!"
The expected output will print, ",olleH I ma !lidaA".

Input Format:
The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.

Output Format:
The only line of output prints the sentence(string) such that each word in the sentence is reversed. 

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Sample Input 1:
Welcome to Coding Ninjas

Sample Output 1:
emocleW ot gnidoC sajniN

Sample Input 2:
Always indent your code

Sample Output 2:
syawlA tnedni ruoy edoc
*/

#include<bits/stdc++.h>
using namespace std;


//This is my code where I have not done the operation on the main string as it is. Just printed the output.
void reverseEachWordStack(char input[]) {
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

//Second more easier method using the reverse() fnction is:
void reverseEachWordFunction(char input[]) {
    // Write your code here
	int start = 0, i = 0;
    while(input[i] != '\0'){
        if(input[i] == ' '){
            reverse(input + start, input + i);
            start = i + 1;
        }
        ++i;
    }
    
    reverse(input + start, input + i);

}

int main(){
	char arr[500];
	cin.getline(arr,100);
	
	reverseEachWord(arr);
	return 0;
}
