// Next Greater Left.


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> findNGL(int *arr , int n){
	// Let's create the 2 STL'S that we need.
	vector<int> ans(n , 0);
	stack<int> s1;
	
	// Now as we have to find the next greater left, we need to start from the left side of the array.
	ans[0] = -1;
	s1.push(arr[0]);
	
	for(int i = 1; i < n; i++){
		// Now we need to compare the top of the stack with the current element.
		// If the top is smaller, we will pop till we don't find a greater element or the stack becomes empty.
		while(!s1.empty()){
			if(s1.top() > arr[i]){
				ans[i] = s1.top();
				break;
			}else{
				s1.pop();
			}
		}
		
		if(s1.empty()){
			ans[i] = -1;
		}
		
		// After the current element has been processes, we push it into the stack.
		s1.push(arr[i]);
	}
	
	return ans;
}

int main(){
	
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<int> ans = findNGL(arr , n);
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	} 
	
	
	return 0;
}
