#include<bits/stdc++.h>
using namespace std;

// This is more of a backtracking method to do this problem.

bool subsetSum(int *arr, int n, int sum){
	
	//Base Case.
	if(n == 0){
		if(sum == 0){
			return true;
		}else{
			return false;
		}
	}
	
	if(sum == 0){
		return true;
	}
		
	if(sum > 0){
		if(arr[n-1] <= sum){
			if(subsetSum(arr,n-1,sum - arr[n-1])){
				return true;
			}
			
			// Not include the element.
			if(subsetSum(arr,n-1,sum)){
				return true;
			}
			//subsetSum(arr,n-1,sum)
		}else{
			if(subsetSum(arr,n-1,sum)){
				return true;
			}
		}
		
		
	}
	
	return false;
}

int main(){
	int n , sum;
	cin >> n;
	cin >> sum;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << "Is there a subset avaiable : " << subsetSum(arr,n,sum);
	
	return 0;
}
