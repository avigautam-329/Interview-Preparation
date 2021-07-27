#include<bits/stdc++.h>
using namespace std;


int helperFunction(int n, int *memo){
	if(n == 1){
		// There is no way of reaching 1 from 1.
		return 0;
	}
	
	
	// What we do in this is we check whether we have already found a way to reach 1 from the current cell in the shortest way or not.
	if(memo[n] != -1){
		return memo[n];
	}
	
	// We can reach 1 from any element if we decrease 1 from the current element.
	int res = helperFunction(n - 1, memo);
	
	// Now we have the result for using the decrement path.
	
	// I will check if the current number is divisble by zero or not.
	if(n % 2 == 0){
		
		// This will check if we can reach 1 in the shortest path by decrementing one or by dividing by 2.
		res = min(res, helperFunction(n / 2, memo));
	}
	
	if(n % 3 == 0 ){
		
		// This will check if we can reach 1 in the shortest path by decrementing one or by dividing by 3.
		res = min(res,helperFunction(n / 3, memo));
	}
	
	// Now as we have the shortest path with us we can put it in the memo array.
	memo[n] = 1 + res;
	return memo[n];
}

int getMinPath(int n){
	
	// We will use the memorization technique of DP to contain the minSteps.
	int *memo = new int[n+1];
	
	//Initialize the memo array with all -1.
	for(int i = 0; i < n+1; ++i){
		memo[i] = -1;
	}
	
	memo[1] = 0;
	
	return helperFunction(n , memo);
}

int main(){
	int n;
	cin >> n;
	
	int ans = getMinPath(n);
	cout << "The minimum number of steps are : " << ans << endl;
	return 0;
}
