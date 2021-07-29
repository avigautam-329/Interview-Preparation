#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

// This is the brute force recursive function.
int maxProfit(int *val, int *wt, int n, int maxWt){
	// Base Case.
	if(n == 0 || maxWt == 0){
		return 0;
	}
	
	// Now we will check the choice basic conditions.
	if(wt[n-1] <= maxWt){
		return max(val[n-1] + maxProfit(val,wt,n-1,maxWt-wt[n-1]) , maxProfit(val,wt,n-1,maxWt));
	}else{
		return maxProfit(val,wt,n-1,maxWt);
	}
}


int main(){
	int n;
	int maxWt;
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
	
	cout << "The max Profit is : " << maxProfit(val,wt,n,maxWt);
	
	return 0;
}
