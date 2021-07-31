#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

//Print partitions as well dynamic programming.
bool isPossible(int *arr, int n, int k, bool *finalSolution, int **dp){
	if(n == 0){
		if(k == 0){
			return true;
		}else{
			return false;
		}
	}
	
	if(k == 0){
		return true;
	}
	
	if(dp[n][k] > -1){
		return dp[n][k] == 1;
	}
	
	if(arr[n-1] <= k){
		
		if(isPossible(arr,n-1,k-arr[n-1],finalSolution,dp)){
			dp[n][k] = 1;
			finalSolution[n-1] = true;
			return true;
		}
		
		if(isPossible(arr,n-1,k,finalSolution,dp)){
			dp[n][k] = 1;
			return true;
		}
		
	}else{
		if(isPossible(arr,n-1,k,finalSolution,dp)){
			dp[n][k] = 1;
			return true;
		}
	}
	
	dp[n][k] = 0;
	return false;
}


int main(){
	int n;
	cin >> n;
	
	int sumOfArray = 0;
	
	int *arr = new int[n];
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		sumOfArray += arr[i];
	}
	
	if(sumOfArray % 2 != 0){
		cout << "False";
	}else{
		// If sum is true now lets print the partitions.
		bool *finalSolution = new bool[n];
		memset(finalSolution,false,sizeof(finalSolution));
		
		int k = sumOfArray / 2;
		
		int **dp = new int*[n+1];
		for(int i = 0; i < n+1; ++i){
			dp[i] = new int[k+1];
			for(int j = 0; j < k+1; ++j){
				dp[i][j] = -1;
			}
		}
		
		bool ans = isPossible(arr,n,k,finalSolution,dp);
		if(ans){
			cout << "partition1 : ";
			for(int i = 0; i < n; i++){
				if(finalSolution[i]){
					cout << arr[i] << " ";
				}
			}
			cout << endl;
			cout << "partition2 : ";
			for(int i = 0; i < n; i++){
				if(!finalSolution[i]){
					cout << arr[i] << " ";
				}
			}
		}else{
			cout << "Not Possible.";
		}
	}
	
	return 0;
}
