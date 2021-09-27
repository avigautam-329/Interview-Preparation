/*
Given a string of balanced expression, find if it contains a redundant parenthesis or not. 
A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. 
Print ‘Yes’ if redundant, else ‘No’.
Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.
*/


#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool isOperator(char x){
	if( x == '(' || x == '+' || x == '-' || x == '*' || x == '/'){
		return true;
	}
	return false;
}

bool checkRedundancy(string exp){
	if(exp.size() == 0){
		return true;
	}
	
	stack<char> operators;
	
	for(int i = 0; i < exp.size(); i++){
		
		char curr = exp[i];
		if(isOperator(curr)){
			operators.push(curr);
		}else if(curr == ')'){
			// Now we will pop the elements from the stack.
			if(operators.top() == '('){
				return true;
			}else{
				while(operators.top() != '('){
					operators.pop();
				}
				
				operators.pop();
			}
		}
	}
	
	return false;
}

int main(){
	
	string exp;
	getline(cin , exp);
	
	bool isRedundant = checkRedundancy(exp);
	
	if(isRedundant){
		cout << "The expression has redundant parenthesis." << endl;
	}else{
		cout << "The expression is correct." << endl;
	}
	return 0;
}
