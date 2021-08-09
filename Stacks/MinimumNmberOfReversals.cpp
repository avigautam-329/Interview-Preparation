/*
Minimum bracket Reversal

For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.

Note:
You don't have to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec

Sample Input 1:
{{{
Sample Output 1:
-1

Sample Input 2:
{{{{}}
Sample Output 2:
1
*/



#include <iostream>
#include <string>
#include <stack>
using namespace std;

int countBracketReversals(string input) {

    // Variation of balance paranthesis.
    
    // First check.
    if(input.size() % 2 != 0){
        return -1;
    }
    
    // Create the stack.
    stack<char> unbalanced;
    
    // Now remove the balanced part using the conditions.
    for(int i = 0; i < input.size(); i++){
        char c = input[i];
        
        if(c == '}' && unbalanced.empty()){
            unbalanced.push(c);
        }
        else if(c == '}' && !unbalanced.empty()){
            if(unbalanced.top() == '{'){
                unbalanced.pop();
            }else{
                unbalanced.push(c);
            }
        }
        else if(c == '{'){
            unbalanced.push(c);
        }
        
    }
    
    // Now we will have the stack containing only the umbalanced part.
    // Plus it will be of even length.
    
    int reversals = 0;
    while(!unbalanced.empty()){
        char c1 = unbalanced.top(); unbalanced.pop();
        char c2 = unbalanced.top(); unbalanced.pop();
    	
        if( c1 == c2){
            reversals += 1;
        }else{
            reversals += 2;
        }
    }
    
    return reversals;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
