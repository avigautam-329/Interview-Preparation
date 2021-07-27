#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int maxSumSubarray(int *arr, int n){
	
	if(n == 0){
		return 0;
	}
	
	int curr_max_end = 0;
	int maxSoFar = 0;
	for(int i = 0; i < n ; ++i){
		curr_max_end += arr[i];
		
		if(curr_max_end < 0){
			curr_max_end = 0;
		}
		
		if(curr_max_end >= maxSoFar){
			maxSoFar = curr_max_end;
		}
		
		
	}
	
	return maxSoFar;
	
}


int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n ; ++i){
		cin >> arr[i]; 
	}
	
	int ans = maxSumSubarray(arr,n);
	if(ans <= 0){
		cout << -1;
	}else{
		cout << ans << endl;
	}
	
	
	
	return 0;
}
