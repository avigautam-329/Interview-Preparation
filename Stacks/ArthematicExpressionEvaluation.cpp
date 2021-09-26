/*
The stack organization is very effective in evaluating arithmetic expressions. 
Expressions are usually represented in what is known as Infix notation, in which each operator is written between two operands (i.e., A + B). 
With this notation, we must distinguish between ( A + B )*C and A + ( B * C ) by using either parentheses or some operator-precedence convention. Thus, the order of operators and operands in an arithmetic expression does not uniquely determine the order in which the operations are to be performed. 
*/

// Soo the approach should be:
//	1. We can either find out the postfix or prefix expressiong of the given expression.
//	2. Then we can evaluate the expression that we have created.


#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

// For evaluating the postfix Expression.
int  getValue(string exp){
	stack<int> s1;
	
	for(int i = 0; i < exp.size(); i++){
		char curr = exp[i];
		
		if(curr >= '0' && curr <= '9'){
			int number = curr - '0';
			s1.push(number);
		}
		
		else{
			int res;
			int val1 = s1.top();s1.pop();
			int val2 = s1.top();s1.pop();
			
			if(curr == '+'){
				res = val2 + val1;
			}else if(curr == '-'){
				res = val2 - val1;
			}else if(curr == '*'){
				res = val2 * val1;
			}else if(curr == '/'){
				res = val2 / val1;
			}
			
			s1.push(res);
		}
	}
	
	return s1.top();
}


// For creating the infix to postfix expression.
int precedence(char x){
	if(x == '^'){
		return 3;
	}else if(x == '*' || x == '/'){
		return 2;
	}else if(x == '+' || x == '-'){
		return 1;
	}else{
		return -1;
	}
}

string convertToPostfix(string exp){
	string res = "";
	
	stack<char> s1;
	
	for(int i = 0; i < exp.size(); i++){
		char curr = exp[i];
		
		// If the current character is a number.
		if(curr >= '0' && curr <= '9'){
			// We push it directly into the answer expression.
			res += curr;
		}
		
		//Now we will check if the expression is a open braces.
		else if(curr == '('){
			s1.push(curr);
		}
		
		// Now we will check if the current character is a closing braces.
		else if(curr == ')'){
			// Then we need to pop all the operators out of the stack till the occurence of an open braces.
			while(s1.top() != '('){
				res += s1.top();
				s1.pop();
			}
			
			s1.pop(); // To remove the open braces.
		}
		
		// Lastly we have to check whether the element is a operatorn or not.
		// If it is, then we need to check it's precendence and insert accordingly.
		else{
			while(!s1.empty() && precedence(s1.top()) >= precedence(curr)){
				res += s1.top();
				s1.pop();
			}
			
			s1.push(curr);
		}
	}
	
	//Finally push the remaining operators in the stack as well.
	while(!s1.empty()){
		res += s1.top();
		s1.pop();
	}
	
	return res;
}

int main(){
	string exp;
	getline(cin , exp);
	
	string postfixExp = convertToPostfix(exp);
	
	cout << "The value of the expression is: "  << getValue(postfixExp);
	
	return 0;
}
