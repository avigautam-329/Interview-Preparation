#include<bits/stdc++.h>
using namespace std;

long long findMinWork(int *arr, int n){
	vector<pair<int, int> > buy;
	vector<pair<int, int> > sell;
	
	for(int i = 0; i < n; i++){
		if(arr[i] < 0){
			sell.push_back({arr[i] , i});
		}else{
			buy.push_back({arr[i] , i});
		}
	}
	
	int i = 0;
	int j = 0;
	
	long long minTime = 0;
	
	
	while(i < buy.size() && j < sell.size()){
		
		
		// We will find the max amount of wine we cann trade, hence we just need the absolute value in this case.
		int x = min(buy[i].first , -1 * sell[j].first);
		
		// Once we have found the min, we will add and subtract it from both the buy and sell.
		buy[i].first -= x;
		sell[j].first += x;
		
		// This is found using the positions of the house on the lane/array.
		int work = abs(buy[i].second - sell[j].second);
		
		minTime += (long long)(x * work);
		
		if(buy[i].first == 0){
			i++;
		}
		if(sell[j].first == 0){
			j++;
		}
	}
	
	return minTime;
}

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		
		int *arr = new int[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		long long minWork = findMinWork(arr , n);
		cout << minWork << endl;
	}
	
	return 0;
}
