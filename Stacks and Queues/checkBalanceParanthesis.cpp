#include <iostream>
#include <string>
#include<unordered_map>
#include<stack>
using namespace std;



bool isBalanced(string s) 
{
    unordered_map<char , int> openBrackets({
        {'{' , 1},
        {'[' , 2},
        {'(' , 3}
    });
    unordered_map<char , int> closeBrackets({
        {'}' , 1},
        {']' , 2},
        {')' , 3}
    });
        
    stack<int> brackets;
        
    for(int i= 0; i < x.size(); i++){
        if(openBrackets.find(x[i]) != openBrackets.end()){
            brackets.push(openBrackets[x[i]]);
        }else if(!brackets.empty() && closeBrackets.find(x[i]) != closeBrackets.end()){
            if(brackets.top() == closeBrackets[x[i]]){
                brackets.pop();
            }else{
                return false;
            }
        }else if(brackets.empty() && closeBrackets.find(x[i]) != closeBrackets.end()){
            return false;
        }
    }
        
    return brackets.empty();
}
    
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
