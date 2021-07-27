#include<bits/stdc++.h>
using namespace std;
// This is a dp optimized solution(memorization). I tried on leetCode as well.
int minCostPath(vector<vector<int> >& maze, int si, int sj, int ei, int ej, vector<vector<int> >& dp){
	if(si == ei && sj == ej){
		return maze[ei][ej];
	}
	
	// Now we will check if the current path is out of bounds or not.
	if( si > ei || sj > ej){
		return INT_MAX;
	}
	
	if(dp[si][sj] > -1)
		return dp[si][sj];
	
	//Now we will call on the 3 available options.
	int option1 = minCostPath(maze,si+1,sj,ei,ej,dp);
	int option2 = minCostPath(maze,si+1,sj+1,ei,ej,dp);
	int option3 = minCostPath(maze,si,sj+1,ei,ej,dp);
	
	// Now we will save the current minimum value before returning.
	dp[si][sj] = maze[si][sj] + min(option1, min(option2,option3));
	
	return maze[si][sj] + min(option1, min(option2,option3));
}

int main(){
	int n;
	cin >> n;
	
	vector<vector<int> > maze(n,vector<int>(n,0));
	for(int i = 0; i < n; ++i){
		for(int j = 0 ; j < n; ++j){
			cin >> maze[i][j];
		}
	}
	
	// Now we will create a dp array to store the cost of reaching the final solution from each cell.
	vector<vector<int> > dp(n, vector<int>(n,-1));
	
	cout << "The min Cost is : " << minCostPath(maze, 0 , 0 ,n-1, n-1, dp) << endl;
}
