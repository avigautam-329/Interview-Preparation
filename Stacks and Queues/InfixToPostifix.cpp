#include<bits/stdc++.h>
#include<stack>
#include<cstring>
using namespace std;

// Below 2 functions for evaluation of postix to answer.
bool isOperator(char c){
    
    //Checking if the character is a digit or not.
    if(c >= '0' && c <= '9'){
        return false;
    }
    
    return true;
}

int postfixToAns(string postfix){
    stack<int> subAns;
    for(int i = 0 ; i < postfix.size();i++){
        if(isOperator(postfix[i])){
            // Lets get the top 2 digits of our stack.
            int a = subAns.top(); subAns.pop();
            int b = subAns.top(); subAns.pop();
            int op;
            
            if(postfix[i] == '+'){
                op = b + a;
            }else if(postfix[i] == '-'){
                op = b - a;
            }else if(postfix[i] == '*'){
                op = b * a;
            }else if(postfix[i] == '/'){
                op = b / a;
            }
            
            subAns.push(op);
        }else{
            subAns.push(postfix[i] - '0');
        }
    }
    int ans = subAns.top();
    return ans;
}

// Below 2 functions for evaluation of infix to postfix.
int precedence(char c){
	if(c == '%'){
		return 3;
	}else if(c == '*' || c == '/'){
		return 2;
	}else if(c == '+' || c == '-'){
		return 1;
	}else{
		// For the bracket operators, hence the beackets cannot be removed until and unless the code removes them manually.
		return -1;
	}
}

void evaluatePostfix(string input) {
	stack<char> operators;
	string ans="";
	
	for(int i = 0; i < input.size(); i++){
		char x = input[i];
		//Following the rule, we should directly print an operand.
		if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9')){
			ans += x;
		}
		
		else if(x == '('){
			operators.push(x);
		}
		

		
		else if(x == ')'){
			while(!operators.empty() && operators.top() != '('){
				ans += operators.top();
				operators.pop();
			}
			
			// Removing the bracket manually.
			operators.pop();
		}
		
		// This method also handles the associativity rule.
		else{
			
			// Now we have to remove the operators till we reach an operator that has less precedence or the stack becomes empty.
			while(!operators.empty() && precedence(x) <= precedence(operators.top())){
				ans += operators.top();
				operators.pop();
			}
			
			operators.push(x);
		}
	}
	
	while(!operators.empty()){
		ans += operators.top();
		operators.pop();
	}
	
	for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    cout << endl;
    
    int calculation = postfixToAns(ans);
    cout << calculation;
    return;
}

int main(){
	string input;
	cin >> input;
	
	string ans;
	ans = infixToPostfix(input);
	cout << ans;
	
	return 0;
}

