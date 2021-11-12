#include<bits/stdc++.h>
#include<deque>
using namespace std;

int maxOfAll(int *arr, int n, int k){
	// First thing is to create a deque.
	deque<int> d1;
	
	// Second: Get all the elements of the first k elements.
	int i = 0;
	for(; i < k; i++){
		// In this we will remove all previous greater elements from the rear of the deque.
		while(!d1.empty() && (arr[d1.back()] <= arr[i])){
			d1.pop_back();
		}
		
		d1.push_back(i);
	}
	
	// Third: We will get the greatest elements and also remove the useless greater elements.
	int sum = 0;
	for(; i < n; i++){
		sum += arr[d1.front()];
		
		// Now we will remove the elements which are not in the new window.
		while(!d1.empty() && d1.front() <= i - k){
			d1.pop_front();
		}
		
		while(!d1.empty() && arr[i] >= arr[d1.back()]){
			d1.pop_back();
		}
		
		d1.push_back(i);
	}
	
	sum += arr[d1.front()];
	
	return sum;
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int k;
	cin >> k;
	
	int maxSumOfAllSubArray = maxOfAll(arr , n , k);
	
	cout << maxSumOfAllSubArray << endl;
	return 0;
}
