#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/*
	Steps to be followed:
		1. get the first k elements in the priority queue using a for loop.
		2. keep an index j , to tell us at what place are we keeping the maximum element at.
		3. then in a for loop from k to n, get the max element from the pq first and pop it, and in the end add the lement at ith position into the array.
		4. for the left over elements in the pq, use a while loop and place them in the array.

*/


void kSort(int *arr, int n, int k){
	
	// By default the inbuilt priority queue is max.
	//  We can use this for ascending order: priority_queue<int,vector<int>,greater<int> > pq;
	priority_queue<int> pq;
	for(int i = 0; i < k; i++){
		pq.push(arr[i]);
	}
	
	int j = 0;
	for(int i = k; i < n; i++){
		arr[j++] = pq.top();
		pq.pop();
		
		pq.push(arr[i]);
	}
	
	while(!pq.empty()){
		arr[j++] = pq.top();
		pq.pop();
	}
	
}


// Input sample: 12 15 6 7 9, n = 5 and k = 3.
int main(){
	
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int k;
	cin >> k;
	
	kSort(arr, n, k);
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
