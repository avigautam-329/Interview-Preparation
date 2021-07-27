#include<bits/stdc++.h>
using namespace std;

int minCostPath(vector<vector<int> >& maze, int si, int sj, int ei, int ej){
	if(si == ei && sj == ej){
		return maze[ei][ej];
	}
	
	// Now we will check if the current path is out of bounds or not.
	if( si > ei || sj > ej){
		return INT_MAX;
	}
	
	//Now we will call on the 3 available options.
	int option1 = minCostPath(maze,si+1,sj,ei,ej);
	int option2 = minCostPath(maze,si+1,sj+1,ei,ej);
	int option3 = minCostPath(maze,si,sj+1,ei,ej);
	
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
	
	cout << "The min Cost is : " << minCostPath(maze, 0 , 0 ,n-1, n-1) << endl;
}
