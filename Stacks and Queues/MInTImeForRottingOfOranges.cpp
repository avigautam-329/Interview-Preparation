/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. 
A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
*/

#include<bits/stdc++.h>
using namespace std;

/*
Approach:
	1. First, we need to understand that the rotting of oranges happens simultaneously, soo the time in one iteration is incremented by 1.
	2. We will try to find the positions of all the rotten oranges in the matrix and put their positions in a queue.
	3. The first iteration's will get the initial rotten oranges and will lead to rotting of all the adjacent fresh oranges.
	4. We need to input the positions of all of the oranges getting rotten as they may lead to rotting of oranges that are adjacent to the
		newly rotten oranges.
	5. To define the different timings of oranges getting rotten , we will use a delimiter.
	6. The concept of this divison is very similar to that of level order traversal printing row by row.
	7. Here the delimiter will be the position (-1 , -1) as this position is never present in the matrix.
	8. whenever we hit a delimite, it will mean that 1 second has passed and now the next set of rotten oranges will affect the other fresh oranges.
	9. Also as the question requires for all the oranges to rot, hence we will maintain count of fresh oranges initially and after all iterations.
*/

int xMove[] = {1 , -1 , 0 , 0};
int yMove[] = {0 , 0 , -1 , 1};

// To check if the position is in the matrix boundaries or not.
bool isValid(int **matrix , int n, int m, int x , int y){
	if(x >= 0 && y >= 0 && x < n && y < m){
		return true;
	}
	
	return false;
}


int findMinTimeToRot(int** matrix, int n , int m){
	if(n == 0 && m == 0){
		return -1;
	}
	
	// Now we will create a queue to store the rotten oranges position into.
	queue<pair<int ,int> > pendingOranges;
	
	// Initialising the oranges position which are rotten initially & also counting the fresh oranges.
	int countFresh = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 2){
				pendingOranges.push({i , j});
			}else if(matrix[i][j] == 1){
				countFresh++;
			}
		}
	}
	// Now we will add the delimiter to the queue.
	pendingOranges.push({-1 , -1});
	
	// Now that we have the positions of the intial rotten oranges, we will see what all oranges it can effect.
	int totalTime = 0;
	int totalChanged = 0;
	while(!pendingOranges.empty()){
		if(pendingOranges.front().first == -1 && pendingOranges.front().second == -1 && pendingOranges.size() == 1){
			pendingOranges.pop();
			break;
		}
		
		else if(pendingOranges.front().first == -1 && pendingOranges.front().second == -1 && pendingOranges.size() > 1){
			// This means that an iteration of chain reaction has ended and a new one will start.
			pendingOranges.pop();
			totalTime++;
			
			pendingOranges.push({-1 , -1});
		}
		
		else{
			// This means that we have encountered a poistion of rotten orange.
			// Soo we need to check it's 4 directions for an available fresh orange to affect.
			
			for(int i = 0; i < 4; i++){
				if(isValid(matrix , n , m , pendingOranges.front().first + xMove[i] , pendingOranges.front().second + yMove[i])){
					if(matrix[pendingOranges.front().first + xMove[i]][pendingOranges.front().second + yMove[i]] == 1){
						matrix[pendingOranges.front().first + xMove[i]][pendingOranges.front().second + yMove[i]] = 2;
						pendingOranges.push({pendingOranges.front().first + xMove[i] , pendingOranges.front().second + yMove[i]});
						totalChanged++;
					}
				}
			}
			pendingOranges.pop();
		}
	}
	
	if(totalChanged != countFresh){
		return -1;
	}
	
	return totalTime; 
}

int main(){
	// Let's make the matrix.
	
	int n , m;
	cin >> n >> m;
	
	int **matrix = new int*[n];
	for(int i = 0; i < n; i++){
		matrix[i] = new int[m];
		
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	
	
	int minTime = findMinTimeToRot(matrix, n , m);
	
	cout << "The minimum time is : " << minTime << endl;
	
	return 0;
}
