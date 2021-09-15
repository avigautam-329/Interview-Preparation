#include<iostream>
#include<climits>
typedef long long int lli;
using namespace std;


bool isValid(int arr[], int n, int paratha, lli x){
	int countOfParatha = 0;
	
	for(int i = 0; i < n; i++){
		lli sumTime = arr[i];
		
		int j = 2;
		while(sumTime <= x){
			countOfParatha++;
			sumTime += (arr[i] * j);
			j++;
		}
		
		if(countOfParatha >= paratha){
			return true;
		}
	}
	
	return false;
}

lli binarySearch(int arr[] ,int n , int paratha){
	lli lb = 0;
	lli ub = 1e8;
	lli timereq = -1;
	
	while(lb <= ub){
		lli x = (ub + lb) / 2;
		
		if(isValid(arr , n , paratha, x)){
			timereq = x;
			ub = x - 1;
		}else{
			lb = x + 1;
		}
	}
	
	return timereq;
}

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int paratha;
		cin >> paratha;
		
		int L;
		cin >> L;
		
		int arr[L];
		for(int i = 0; i < L ; i++){
			cin >> arr[i];
		}
		
		lli minTimeReq = binarySearch(arr, L, paratha);
		cout << minTimeReq << endl;
	}
	return 0;
}
