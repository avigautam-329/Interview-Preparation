#include<bits/stdc++.h>
using namespace std;


void printPathHelper(int **input, int size, int **solution, int x, int y){
	
	// We have reached the final solution and we should print the solution matrix to show the path.
	if(x == size-1 && y == size-1){
		
		// First make the end path marked as well.
		solution[x][y] = 1;
		
		for(int i = 0 ; i < size; ++i){
			for(int j = 0 ; j < size; ++j){
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	
	// Check whether we have a valid point in hand or not.
	if(x < 0 || y < 0 || x >= size || y >= size || input[x][y] == 0 || solution[x][y] == 1){
		return;
	}
	
	// Now to find the path we need to do the same thing.
	solution[x][y] = 1;
	
	//Call the helper funtion to check the path.
	printPathHelper(input, size, solution, x - 1, y);
	printPathHelper(input, size, solution, x + 1, y);
	printPathHelper(input, size, solution, x , y - 1);
	printPathHelper(input, size, solution, x , y + 1);
	
	solution[x][y] = 0;
	return;
}

void printPath(int **input, int size){
	
	int **solution = new int*[size];
	for(int i = 0; i < size; ++i){
		solution[i] = new int[size];
		for(int j = 0; j < size; ++j){
			solution[i][j] = 0;
		}
	}
	
	printPathHelper(input, size, solution, 0 ,0);
}

int main(){
	
	int n;
	cin >> n;
	
	int **maze = new int*[n];
	for(int i = 0 ; i < n ; ++i){
		maze[i] = new int[n];
		for(int j = 0; j < n; ++j){
			cin >> maze[i][j];
		}
	}
	
	printPath(maze , n);
	return 0;
}
