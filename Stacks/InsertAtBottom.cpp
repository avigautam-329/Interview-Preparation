// Implementing a method to put an element at the bottom of a stack.

#include<iostream>
#include<stack>
using namespace std;

// The Approach is:
/*
	1. We want to insert a new element at the end of the stack.
		- To do soo, we will have to empty the stack first, but as we don't want to use any auxiliary space, we can use recursion.
	2. We will first empty the stack, once the base case is reached we will insert the element.
		- Then we will simply as we pop the functions from the recursion stack, they will input back the top value which was popped.
		
	Time Complexity: O(N)
	Space Complexity: O(1)
*/

void insertAtBottom(stack<int>& s1, int val){
	if(s1.empty()){
		s1.push(val);
		return;
	}
	
	int top = s1.top();s1.pop();
	insertAtBottom(s1 , val);
	s1.push(top);
	
	return;
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
	insertAtBottom(s1 , val);
	
	while(!s1.empty()){
		cout << s1.top() << " ";
		s1.pop();	
	}
	return 0;
}
