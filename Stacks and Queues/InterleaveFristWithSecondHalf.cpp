/*
Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.
Only a stack can be used as an auxiliary space.
*/


#include<iostream>
#include<stack>
#include<queue>
using namespace std;

/*
	We can only use another stack to do this question.
	Approach:
		1. Soo in the final queue, the elements of the second half are present at the odd indices.
			And of the first half are present in the even indices.
		2. To achieve this we will take a stack and put the first n / 2 elements into to the stack.
		3. Then we will pop them and put them back into the stack. But now the first half will be inserted in reverse order.
			- We are doing this because we can see that to interleaf , we need the first half to be present in the correct order in the stack as well.
		4. Now, we will put the second half elements atthe back of the stack again by simply popping and pushing them back in.
		5. Again we will put the first half into the stack.
			- At this point the elements in the stack are present in the correct order as they were appreaing in the original queue.
		6. Now we will simply pop the elements from the stack and put them in the queue.
			- And for the first half we will dequeue them from the queue and enqueue them again.
			

*/

queue<int> interleave(queue<int>& q1){
	if(q1.empty()){
		return q1;
	}
	
	stack<int> s1;
	
	// Putting the first half in the stack.
	int mid = q1.size() / 2;
	
	int count = 0;
	while(count < mid){
		s1.push(q1.front()); q1.pop();
		count++;
	}
	
	// Insert the elements of the stack again into the queue.
	while(!s1.empty()){
		q1.push(s1.top());s1.pop();
	}
	
	// Putting the second half into the back of the queue.
	count = 0;
	while(count < mid){
		q1.push(q1.front());q1.pop();
		count++;
	}
	
	// Now putting the first half into the stack in correct order.
	count = 0;
	while(count < mid){
		s1.push(q1.front()); q1.pop();
		count++;
	}
	
	// Now interleaving the elements in the queue.
	while(!s1.empty()){
		q1.push(s1.top());s1.pop();
		
		q1.push(q1.front());q1.pop();
		
	}
	
	return q1;
}

int main(){
	int n;
	cin >> n;
	
	queue<int> q1;
	for(int i = 0; i < n; i++){
		int number;
		cin >> number;
		q1.push(number);
	}
	
	q1 = interleave(q1);
	
	while(!q1.empty()){
		cout << q1.front() << " ";
		q1.pop();
	}
	return 0;
}

