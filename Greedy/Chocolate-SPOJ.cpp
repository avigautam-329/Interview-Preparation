#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	// m is the width and n is the height
	int t;
	cin >> t;
	
	while(t--){
		
		int m , n;
		cin >> m >> n;
		
		// The number of vertical cuts -> (m - 1)  | The number of horizontal cuts -> (n - 1).
		vector<int> verticalCuts;
		vector<int> horizontalCuts;
		
		for(int i = 0; i < m - 1; i++){
			int num;
			cin >> num;
			verticalCuts.push_back(num);
		}
		
		for(int j = 0; j < n - 1; j++){
			int num;
			cin >> num;
			horizontalCuts.push_back(num);
		}
		
		// Next we need to sort them in descending order.
		sort(verticalCuts.begin(), verticalCuts.end(), greater<int>());
		sort(horizontalCuts.begin(), horizontalCuts.end(), greater<int>());
		
		// Now we need to define the number of vertical and horizontal segments which initially are 1 each.
		int verticalSegs = 1;
		int horizontalSegs = 1;
		
		int res = 0;
		int i = 0;
		int j = 0;
		
		while(i < m - 1 && j < n - 1){
			if(verticalCuts[i] >= horizontalCuts[j]){
				res += (verticalCuts[i] * verticalSegs);
				horizontalSegs++;
				i++;
			}else{
				res += (horizontalCuts[j] * horizontalSegs);
				verticalSegs++;
				j++;
			}
		}
		
		while(i < m - 1){
			res += (verticalCuts[i] * verticalSegs);
			//verticalSegs++;
			i++;
		}
		
		while(j < n - 1){
			res += (horizontalCuts[j] * horizontalSegs);
			//verticalSegs++;
			j++;
		}
		
		
		cout << "The minimum cost is: " << res;
		cout << endl;
		
	}

	return 0;
}
