#include<bits/stdc++.h>
#include<vector>
#define N 8
using namespace std;


bool notVisited(int **solution){
	for(int i = 0; i < N ; ++i){
		for(int j = 0; j < N ; ++j){
			if(solution[i][j] == 0){
				return true;
			}
		}
	}
	return false;
}

bool isPossibleHelper(int board[N][N], int **solution, int x, int y ){
	
	// Means all of the cells are visited once.
	if(!notVisited(solution)){
		return true;
	}
	
	//Check if the current cell is valid or not.
	if(x < 0 || y < 0 || x >=N || y >=N || solution[x][y] == 1){
		return false;
	}
	
	// Mark the current cell as visited for now.
	solution[x][y] = 1;
	
	
	// Knight moves upwards.
	if(isPossibleHelper( board , solution , x  - 1 , y + 2 )){
		return true;
	}
	
	if(isPossibleHelper( board , solution , x  + 1 , y + 2 )){
		return true;
	}
	
	// Knight moves to the right.
	if(isPossibleHelper( board , solution , x  + 2 , y + 1 )){
		return true;
	}
	
	if(isPossibleHelper( board , solution , x  + 2 , y - 1 )){
		return true;
	}
	
	// Knight moves to the left.
	if(isPossibleHelper( board , solution , x  - 2 , y + 1 )){
		return true;
	}

	if(isPossibleHelper( board , solution , x  - 2 , y - 1 )){
		return true;
	}
	
	// Knight moves downwards.
	if(isPossibleHelper( board , solution , x  + 1 , y - 2 )){
		return true;
	}
	
	if(isPossibleHelper( board , solution , x  - 1 , y - 2 )){
		return true;
	}
	
	// If non of the conditions matches then the current cell is not a possible move.
	solution[x][y] = 0;
	
	return false;
}

bool isPossible(int board[N][N]){
	
	// Creating a 2D Array to keep track of viable move.
	int **solution = new int*[N];
	for(int i = 0; i < N; ++i){
		solution[i] = new int[N];
		for(int j = 0; j < N ; ++j){
			solution[i][j] = 0;
		}
	}
	
	return isPossibleHelper(board,solution,0,0);
}


int main(){
	int board[N][N];
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
		}
	}
	
	if(isPossible(board)){
		cout << "Yes, the knight can reach every cell exactly once." << endl;

	}else{
		cout << "Not possible." << endl;
	}
	return 0;
}
