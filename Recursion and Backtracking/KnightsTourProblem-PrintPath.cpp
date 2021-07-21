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

bool isPossibleHelper(int board[N][N], int **solution, int x, int y , vector<int> &path){
	
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
	path.push_back(board[x][y]);
	
	// Knight moves upwards.
	if(isPossibleHelper( board , solution , x  - 1 , y + 2 , path)){
		return true;
	}
	
	if(isPossibleHelper( board , solution , x  + 1 , y + 2 , path)){
		return true;
	}
	
	// Knight moves to the right.
	if(isPossibleHelper( board , solution , x  + 2 , y + 1 , path)){
		return true;
	}
	
	if(isPossibleHelper( board , solution , x  + 2 , y - 1 , path)){
		return true;
	}
	
	// Knight moves to the left.
	if(isPossibleHelper( board , solution , x  - 2 , y + 1 , path)){
		return true;
	}

	if(isPossibleHelper( board , solution , x  - 2 , y - 1 , path)){
		return true;
	}
	
	// Knight moves downwards.
	if(isPossibleHelper( board , solution , x  + 1 , y - 2 , path)){
		return true;
	}
	
	if(isPossibleHelper( board , solution , x  - 1 , y - 2 , path)){
		return true;
	}
	
	// If non of the conditions matches then the current cell is not a possible move.
	solution[x][y] = 0;
	path.pop_back();
	return false;
}

bool isPossible(int board[N][N] , vector<int> &path){
	
	// Creating a 2D Array to keep track of viable move.
	int **solution = new int*[N];
	for(int i = 0; i < N; ++i){
		solution[i] = new int[N];
		for(int j = 0; j < N ; ++j){
			solution[i][j] = 0;
		}
	}
	
	return isPossibleHelper(board,solution,0,0,path);
}


int main(){
	int board[N][N];
	vector<int> solPath;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
		}
	}
	
	if(isPossible(board,solPath)){
		cout << "Yes, the knight can reach every cell exactly once." << endl;
		cout << "The path taken is:" << endl;
		for(int i = 0; i < solPath.size(); ++i)
			cout << solPath[i] << " ";
		cout << endl;
	}else{
		cout << "Not possible." << endl;
	}
	return 0;
}
