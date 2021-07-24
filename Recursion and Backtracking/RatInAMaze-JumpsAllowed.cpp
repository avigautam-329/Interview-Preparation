#include<bits/stdc++.h>
using namespace std;

// We have printed all the paths.

void printSolution(int **solution, int size){
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			cout << solution[i][j] << " ";
		}
		cout << endl;
	}
}

void helperFunction(int **maze, int size, int x, int y, int **solution){
	
	if(x == size-1 && y == size-1){
		solution[x][y] = 1;
		printSolution(solution,size);
		return;	
	}
	
	// Now we will check if the current cell is viable or not.
	
	// First check if we have reached outer bound or not.
	if(x < 0 || y < 0 || x >= size || y >= size || solution[x][y] == 1 || maze[x][y] == 0){
		return;
	}
	
	solution[x][y] = 1;
	
	// As if step > 1, then we can all kinds of step till the given step.
	// If step = 2 , then at a time we can take 1 or even 2 step.
	// To check for each soltion we use this for loop.
	for(int i = 1; i <= maze[x][y]; ++i){
		
		helperFunction(maze,size, x + i,y,solution);
		
		helperFunction(maze,size,x, y + i,solution);
	}
	
	
	// Trigger back Tracking.
	solution[x][y] = 0;
	return;
}

void ratInMaze(int **maze, int size){
	
	// We will create a solutions 2D ARRAY.
	int **solution = new int*[size];
	for(int i = 0; i < size; ++i){
		solution[i] = new int[size];
		for(int j = 0; j < size; ++j){
			solution[i][j] = 0;
		}
	}
	
	// Maybe creating a maxSteps function will help
	
	helperFunction(maze,size,0,0,solution);
	
	
}

int main(){
	int n;
	cin >> n;
	
	int **maze = new int*[n];
	for(int i = 0; i < n; ++i){
		maze[i] = new int[n];
		for(int j = 0; j < n; ++j){
			cin >> maze[i][j];
		}
	}
	
	ratInMaze(maze , n);
	return 0;
}
