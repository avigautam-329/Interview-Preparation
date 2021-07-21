#include<bits/stdc++.h>
using namespace std;

bool hasPathHelper(int **input, int size, int **solution, int x, int y){
	//Check whether we have reached the final position or not.
	if( x == size - 1 && y == size - 1){
		return true;
	}
	
	// Now check if the point we are on is a valid point or not.
	if(x < 0 || y < 0 || x >= size || y >= size || input[x][y] == 0 || solution[x][y] == 1){
		return false;
	}
	
	// Now as the point is valid , we should mark it as visited.
	solution[x][y] = 1;
	
	// Now moving to the next point and checking if it can lead to the final destination or not.
	if(hasPathHelper(input , size , solution , x - 1 , y)){
		return true;
	}
	
	if(hasPathHelper(input , size , solution , x + 1 , y)){
		return true;
	}
	
	if(hasPathHelper(input , size , solution , x , y - 1)){
		return true;
	}
	
	if(hasPathHelper(input , size , solution , x , y + 1)){
		return true;
	}
	
	// In case all of the above cases are false, then this point is not a valid point and we should mark it as unvisited and return false.
	solution[x][y] = 0;
	return false;
	
	
}

bool hasPath(int **input, int size){
	
	// We need to create a solutions matrix to keep track of all the cells which have been visited.
	int **solution = new int*[size];
	
	// We will initialize all of the cells of this 2D array as 0.
	// 0 -> Not Visited/Not Viable
	// 1 -> Visited / Viable
	
	for ( int i = 0; i < size; ++i){
		solution[i] = new int[size];
		for(int j = 0; j < size ; ++j){
			solution[i][j] = 0;
		}
	}
	
	// Then call the helper function which will actually find the path.
	// The last 2 values are the current position.
	return hasPathHelper(input,size,solution,0,0);
}


// The maze is of dimension n X n.
int main(){
	
	//Size of 2D array.
	int n;
	cin >> n;
	
	//Creating the maze.
	int **maze = new int*[n];
	
	for(int i = 0 ; i < n ; ++i){
		//Create a new row.
		maze[i] = new int[n];
		for(int j = 0 ; j < n; ++j){
			cin >> maze[i][j];
		}
	}
	
	bool ans = hasPath(maze,n);
	if(ans){
		cout << "It is possible to reach the final destination." << endl;
	}else{
		cout << "It is not possible to reach the final destination." << endl;
	}
	
	return 0;
		
}
