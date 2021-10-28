#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int w , h , n;
		
		cin >> w >> h >> n;
		
		vector<int> xPos;
		vector<int> yPos;
		
		xPos.push_back(0);
		yPos.push_back(0);
		
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			
			xPos.push_back(x);
			yPos.push_back(y);
		}
		
		xPos.push_back(w + 1);
		yPos.push_back(h + 1);
		
		sort(xPos.begin() , xPos.end());
		sort(yPos.begin() , yPos.end());
		
		int maxHeight = INT_MIN;
		int maxWidth = INT_MIN;
		
		for(int i = 0; i < xPos.size() - 1; i++){
			maxHeight = max(maxHeight , (xPos[i + 1] - xPos[i] - 1));
			maxWidth = max(maxWidth , (yPos[i + 1] - yPos[i] - 1));
		}
		
		cout << maxHeight * maxWidth << endl;
	}
	
	
	return 0;
}
