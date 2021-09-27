#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> findNSR(int* arr, int n){
	vector<int> ans(n , 0);
	stack<int> s1;
	
	ans[n - 1] = -1;
	s1.push(arr[n - 1]);
	
	for(int i = n - 2; i >= 0; i--){
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
	
	vector<int> ans = findNSR(arr , n);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
