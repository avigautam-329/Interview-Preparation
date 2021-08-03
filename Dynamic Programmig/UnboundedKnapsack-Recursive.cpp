#include<bits/stdc++.h>
using namespace std;

// Recursive code for unbounded knapsack.

int unboundedKnapsack(int *val, int *wt, int n, int maxWt){
	if(n == 0 || maxWt == 0){
		return 0;
	}
	
	// The minor change here is that if once included, it can be included again and again.
	// Hence instead of i-1 we can just pass i , in case of inclusion.
	if(wt[n-1] <= maxWt){
		return max(val[n-1] + unboundedKnapsack(val,wt,n,maxWt - wt[n-1]), unboundedKnapsack(val,wt,n-1,maxWt));
	}else{
		return unboundedKnapsack(val,wt,n-1,maxWt);
	}
}

int main(){
	int n , maxWt;
	cin >> n;
	cin >> maxWt;
	
	int *val = new int[n];
	int *wt = new int[n];
	
	for(int i = 0; i < n; ++i){
		cin >> val[i];
	}
	
	for(int i = 0; i < n; ++i){
		cin >> wt[i];
	}
	
	int finalProfit = unboundedKnapsack(val,wt,n,maxWt);
		
	cout << " The max profit out of unbounded knapsack is : " << finalProfit << endl;
	return 0;
}
