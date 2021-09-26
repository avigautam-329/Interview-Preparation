// Implementing a method to put an element at the bottom of a stack.

#include<iostream>
#include<stack>
using namespace std;

stack<int> insertAtBottom(stack<int>& s1, int val){
	if(s1.empty()){
		s1.push(val);
		return s1;
	}
	
	int top = s1.top();s1.pop();
	s1 = insertAtBottom(s1 , val);
	s1.push(top);
	
	return s1;
}

int main(){
	
	// First we will create the initial stack.
	int n;
	cin >> n;
	
	stack<int> s1;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		s1.push(num);
	}
	
	// Now we will take input of the element to be inserted.
	int val;
	cin >> val;
	
	// Now we wwill call the function to input the element in the end.
	s1 = insertAtBottom(s1 , val);
	
	while(!s1.empty()){
		cout << s1.top() << " ";
		s1.pop();	
	}
	return 0;
}
