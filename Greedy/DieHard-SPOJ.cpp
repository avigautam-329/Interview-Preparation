#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001][3];

// THIS IS A DYNAMIC PROGRAMMING SOLUTION.

int solve(int health, int armor, int prev){
	if(health <= 0 || armor <= 0){
		return 0;
	}
	
	if(dp[health][armor][prev] != -1){
		return dp[health][armor][prev];
	}
	
	// Now we need to choose from our 3 options.
	int x , y , z;
	x = y = z = INT_MIN;
	if(prev != 1){
		x = 1 + solve(health + 3 , armor + 2, 1);
	}
	if(prev != 2){
		y = 1 + solve(health - 5 , armor - 10, 2);
	}
	
	if(prev != 3){
		z = 1 + solve(health - 20, armor + 5 , 3);
	}
	
	dp[health][armor][prev] = max(x, max(y , z));
	
	return dp[health][armor][prev];
}

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int health , armor;
		
		cin >> health >> armor;
		
		for(int i = 0; i < 1001; i++){
			for(int j = 0; j < 1001; j++){
				for(int k = 0; k < 3; k++){
					dp[i][j][k] = -1;
				}
			}
		}
		
		cout << max(solve(health + 3 , armor + 2, 1), max(solve(health - 5, armor - 10, 2) , solve(health - 20, armor + 5, 3)));
		cout << endl;
	}
	return 0;
}
