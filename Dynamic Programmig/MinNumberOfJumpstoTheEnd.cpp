#include<iostream>
#include<climits>
using namespace std;

int minJumps(int *arr, int n){
	// First we will create the dp array.
	int *dp = new int[n];
	for(int i = 0; i < n ; i++){
		dp[i] =  INT_MAX;
	}
	
	dp[0] = 0;
	
	for(int i = 1; i < n ; i++){
		for(int j = 0; j < i; j++){
			// Now we will check the maximum reach form the current position.
			if(j + arr[j] >= i && dp[j] != INT_MAX){
				if(dp[j] + 1 < dp[i]){
					dp[i] = dp[j] + 1;
					break;
				}
			}
		}
	}
	
	if(dp[n - 1] == INT_MAX){
		return -1;
	}
	return dp[n-1];
}


int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int jumps = minJumps(arr , n);
	
	cout << jumps << endl;
	return 0;
}
