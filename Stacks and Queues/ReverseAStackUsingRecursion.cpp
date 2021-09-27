/*
Write a program to reverse a stack using recursion. 
You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
1.isEmpty(S) 
2.push(S) 
3.pop(S)

// We will use the concept of inserting at bottom here as well.

// We will create a function, reverseStack, in which we will consider that the stack being returned by it is already sorted and we have to put the current top at 
	the bottom.

*/

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s1, int val){
	if(s1.size() == 0){
		s1.push(val);
		return;
	}
	
	int top = s1.top(); s1.pop();
	
	insertAtBottom(s1, val);
	
	s1.push(top);
	
	return;
}

void reverseStack(stack<int>& s1){
	// This means we have reached the last element.
	if(s1.size() == 1){
		return;
	}
	
	int top = s1.top(); s1.pop();
	
	// Now we will call the reverse function on this stack.
	reverseStack(s1);
	
	// Now that we have the reversed stack we will try to put the top variable at the bottom.
	insertAtBottom(s1 , top);
	
	return; 	
}


int main(){
	
	int n;
	cin >> n;
	
	stack<int> s1;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		s1.push(num);
	}
	
	reverseStack(s1);
	
	while(!s1.empty()){
		cout << s1.top() << endl;
		s1.pop();
	}
	
	return 0;
}
