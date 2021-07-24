/*
TEST CASE : 
12 10
1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 0 1 1 1 1
1 0 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1
*/

#include<bits/stdc++.h>
#include<climits>
using namespace std;

// These are the possible moves from a cell.
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

void markUnSafe(int **playField, int row, int col, int **solution){
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			if(playField[i][j] == 0){
				
				int k = 0;
				solution[i][j] = 1;
				while(k < 4){
					if(i + rowNum[k] >=0 && j + colNum[k] >= 0 && i + rowNum[k] < row && j + colNum[k] < col){
						solution[i + rowNum[k]][j + colNum[k]] = 1;
					}
					++k;
				}
			}
		}
	}
	
	
	cout << endl;
	cout << "After marking the land mine field looks like : " << endl;
	for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

void helperFunction(int **playField, int row, int col, int x, int y, int **solution, int& minSteps, int currSteps){
	
	// Since we can finish at any column of the 
	if(y == col - 1){
		solution[x][y] = 1;
		if(currSteps < minSteps){
			minSteps = currSteps;
		}
		return;
	}
	
	if(currSteps > minSteps){
		return;
	}
	
	if(x < 0 || y < 0 || x > row - 1 || y > col - 1 || solution[x][y] == 1 || playField[x][y] == 0){
		return;
	}
	
	solution[x][y] = 1;
	
	for(int i = 0 ; i < 4 ; ++i){
		helperFunction(playField , row , col , x + rowNum[i], y + colNum[i], solution , minSteps , currSteps + 1);
	}
	
	solution[x][y] = 0;
	
}

void safestRoute(int **playField, int row, int col){
	
	// Now we will create the solution array.
	int **solution = new int*[row];
	for(int i = 0; i < row; ++i){
		solution[i] = new int[col];
		for(int j =0; j < col; ++j){
			solution[i][j] = 0;
		}
	}
	
	int minSteps = INT_MAX;
	
	// In the solutions 2D array, we can mark the dangerous cells before moving to recursion.
	
	markUnSafe(playField, row, col, solution);
	for(int i = 0; i < row ; ++i){
		helperFunction(playField , row , col , i , 0 , solution , minSteps , 0);
	}
	
	cout << "The shortest path to reach the end is : " << minSteps << endl;
}

int main(){
	int row , col;
	cin >> row >> col;
	
	int **playField = new int*[row];
	for(int i = 0; i < row; ++i){
		playField[i] = new int[col];
		for(int j = 0; j < col; ++j){
			cin >> playField[i][j];
		}
	}
	
	safestRoute(playField, row, col);
	
	return 0;
}


