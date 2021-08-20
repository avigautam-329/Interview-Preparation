#include<iostream>
#include<queue>
#include<vector>
using namespace std;


void minPriorityQueue(){
	
	// Syntax to create a minimum prority queue.
	priority_queue<int, vector<int>, greater<int> > pq;
	
	
	pq.push(12);
	pq.push(6);
	pq.push(5);
	pq.push(100);
	pq.push(1);
	pq.push(9);
	pq.push(0);
	pq.push(14);
	
	cout << "Size : " << pq.size() << endl;
	cout << "Max Element : " << pq.top() << endl;
	
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}


// In this function the priority queue being made is a max priority queue(by default).
void defaultPeiorityQueue(){
	priority_queue<int> pq;
	
	pq.push(12);
	pq.push(6);
	pq.push(5);
	pq.push(100);
	pq.push(1);
	pq.push(9);
	pq.push(0);
	pq.push(14);
	
	cout << "Size : " << pq.size() << endl;
	cout << "Max Element : " << pq.top() << endl;
	
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main(){
	// By default our priority queue is a max priority queue.

	defaultPeiorityQueue();
	
	minPriorityQueue();
	
	return 0;
}
