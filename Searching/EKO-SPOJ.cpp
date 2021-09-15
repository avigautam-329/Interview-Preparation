#include<iostream>
#include<climits>
typedef long long int lli;
using namespace std;


bool isValid(lli *arr, lli n, lli c, lli height){
	lli sum = 0;
	
	for(int i = 0; i < n; i++){
		if(height <= arr[i]){
			sum += (arr[i] - height);
			if(sum >= c){
				return true;
			}
		}
	}
	
	return false;
}

lli binarySearch(lli *arr, lli n, lli c){
	lli lb = 1;
	lli ub = 10e9;
	
	lli res = -1;
	
	while(lb <= ub){
		lli x = (ub + lb) / 2;
		
		if(isValid(arr , n , c , x)){
			res = x;
			lb = x + 1;
		}else {
			ub = x - 1;
		}
	}
	
	return res;
}

int main(){
	lli n , c;
	cin >> n >> c;
	
	lli *arr = new lli[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	lli maxHeight = binarySearch(arr , n , c);
	cout << maxHeight << endl;
	
	return 0;
}
