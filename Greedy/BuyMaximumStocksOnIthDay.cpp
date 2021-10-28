#include<bits/stdc++.h>
using namespace std;

static bool comparator(pair<int, int> a, pair<int, int> b){
	return a.first > b.first;
}

int findMaxStocks(vector<int> prices, int n, int maxAmount){
	if(n == 0){
		return 0;
	}
	
	// We can make a vector of pairs.
	// Each pair holding 2 values, first the amount and next the maximum stocks we can buy of that amount.
	
	vector<pair<int , int>> stockPricesDays;
	
	for(int i = 0; i < n; i++){
		stockPricesDays.push_back({prices[i] , i + 1});
	}
	
	sort(stockPricesDays.begin(), stockPricesDays.end());
	
	int countStocks = 0;
	for(int i = 0; i < n; i++){
		int x = min(maxAmount / stockPricesDays[i].first , stockPricesDays[i].second);
		
		countStocks += x;
		
		maxAmount -= (x * stockPricesDays[i].first);
	}
	
	return countStocks;
}

int main(){
	int n;
	cin >> n;
	
	vector<int> prices;
	for(int i = 0; i < n; i++){
		int price;
		cin >> price;
		
		prices.push_back(price);
	}
	
	int maxAmount;
	cin >> maxAmount;
	
	int maxStocks = findMaxStocks(prices, n, maxAmount);
	
	cout << "The max stocks we can buy are: " << maxStocks << endl;
	
	return 0;
}
