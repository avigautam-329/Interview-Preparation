/*
Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, 
where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
*/

#include<bits/stdc++.h>
using namespace std;

/*
Intution:
	1. As this is a binary matrix , soo there must be a zeronext to one, hence the max minimum distance can be 1.
	2. Hence we will try to find all the indices from where 0 is at a distance of 1 from 1.
	
Approach:
	1. We will put all the indices where a zero exists in a queue.
	2. Then we will try to go through the queue (BFS) to find the 0.
	3. Again , we can move in 4 directions.
	4.  
*/


vector<vector<int> > findDistances(int **matrix, int n , int m)
{
	int n = matrix.size();
	int m = matrix[0].size();
    int xMove[] = {-1 , 1 , 0 ,0};
    int yMove[] = {0 , 0 ,-1 , 1};
    	
    queue<pair<int , int> > pendingPositions;
    vector<vector<int> > res(n , vector<int>(m , INT_MAX));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m ; j++){
    		if(matrix[i][j] == 1){
    				
    			res[i][j] = 0;
    			pendingPositions.push({i , j});
    		}
    	}
	}
    	
    // Now for the positions in the queue, we will search in the 4 directions for a 0.
    while(!pendingPositions.empty()){
    	int x = pendingPositions.front().first;
    	int y = pendingPositions.front().second;
    	pendingPositions.pop();
    	for(int i = 0; i < 4; i++){
    		int currX = x + xMove[i];
    		int currY = y + yMove[i];
    		if(currX >= 0 && currX < n && currY >= 0 && currY < m){
    			// Now we have to check, whether the distance from the current block to the next 0 block is actually less than
    			// The distance already stored for it in the res matrix.
    				
    			if(res[x][y] + 1 < res[currX][currY]){
    					
    				res[currX][currY] = res[x][y] + 1;
    					
    				pendingPositions.push({currX , currY});
    			}
    		}
    	}
    		
    		
    }
    	
    return res;
}

int main(){
	int n , m;
	
	cin >> n >> m;
	
	int **matrix = new int*[n];
	for(int i = 0; i < n; i++){
		matrix[i] = new int[m];
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	
	vector<vector<int> > ans = findDistances(matrix , n , m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}	

	return 0;
}

