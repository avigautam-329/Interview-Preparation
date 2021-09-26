#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> findNSL(int* arr , int n){
	// Let's create the necessary STL's.
	vector<int> ans(n , 0);
	stack<int> s1;
	
	// Now as we need to find the Next Smallest left, we will simply start from the left of the array.
	ans[0] = -1;
	s1.push(arr[0]);
	
	for(int i = 1; i < n; i++){
		// Now again, we have to check whether the top of the stack is less than the current element.
		// If not, we have to pop till we don't find one or the stack becomes empty.
		// The top of the stack will always be the last processed next lesser to the left element.
		while(!s1.empty()){
			if(s1.top() < arr[i]){
				ans[i] = s1.top();
				break;
			}else{
				s1.pop();
			}
		}
		
		if(s1.empty()){
			ans[i] = -1;
		}
			
		// Since it has been processed now.
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
	
	vector<int> ans = findNSL(arr , n);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
