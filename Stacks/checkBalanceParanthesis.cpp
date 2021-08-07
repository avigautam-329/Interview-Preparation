#include <iostream>
#include <string>
#include<tr1/unordered_map>
#include<stack>
using namespace std;



bool isBalanced(string s) 
{
    std::tr1::unordered_map<char,int> open_brac = {
        {'{' , 1},
        {'[' , 2},
        {'(' , 3},
    };
    
    std::tr1::unordered_map<char, int> close_brac = {
        {'}' , 1},
        {']' , 2},
        {')' , 3},
    };
    
    stack<int> bracket_check;
    
    for(auto x:s){
        if(open_brac.count(x) > 0){
            bracket_check.push(open_brac[x]);
        }
        
        else if(close_brac.count(x) > 0){
            if(!bracket_check.empty() && bracket_check.top() == close_brac[x]){
                bracket_check.pop();
            }
            else{
                return false;
            }
        }
    }
	return bracket_check.empty();
    
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
