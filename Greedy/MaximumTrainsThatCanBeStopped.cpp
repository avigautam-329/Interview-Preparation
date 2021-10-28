#include<bits/stdc++.h>
using namespace std;

class TrainInfo{
	public:
		int arrTime;
		int deptTime;
		int platformNo;
		
		TrainInfo(){
			
		}
		
		TrainInfo(int arrTime, int deptTime, int platformNo){
			this->arrTime = arrTime;
			this->deptTime = deptTime;
			this->platformNo = platformNo;
		}
};

static bool comparator(pair<int, int> a, pair<int , int> b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	
	return a.second < b.second;
}

int main(){
	
	// n is the number of platforms.
	// M is the total number of trains.
	
	int n , m;
	cin >> n >> m;
	
	vector<TrainInfo> dataTrains;
	for(int i = 0; i < m; i++){
		TrainInfo temp;
		cin >> temp.arrTime;
		cin >> temp.deptTime;
		cin >> temp.platformNo;
		
		dataTrains.push_back(temp);
	}
	
	// This problem is very much related to that of activity selection problem.
	// Here also we are more focused on the dept time of the trains to find the trains which can be stopped.
	
	// The first step is to put all the trains in different rows of a vector according to their platform numbers.
	vector<vector<pair<int,int>> > platformRows(n);
	for(int i = 0; i < m; i++){
		TrainInfo temp = dataTrains[i];
		platformRows[temp.platformNo - 1].push_back({temp.arrTime , temp.deptTime});
	}
	
	// Now that we have separated the data, we will simply sort each row according to increasing order of dept time.
	for(int i = 0; i < n; i++){
		sort(platformRows[i].begin(), platformRows[i].end(), comparator);
	}
	
	int count = n;
	for(int i = 0; i < n; i++){
		// We will use the activity selection method, but for each row separately.
		int x = 0;
		int j = x + 1;
		
		while(j < platformRows[i].size()){
			if(platformRows[i][x].second < platformRows[i][j].first){
				x = j;
				j++;
				count++;
			}else{
				j++;
			}
		}
	}
	
	cout << "The maximum trains that can be stopped are: " << count << endl;
	return 0;
}

// Test Case: 1
/*
3 6
1000 1030 1
1010 1030 1
1000 1020 2
1030 1230 2
1200 1230 3
0900 1005 1
*/

// Output = 5
