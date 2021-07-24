#include <bits/stdc++.h>
using namespace std;

void printBoard(int **solution, int n){
    for(int i = n-1; i >= 0 ; --i){
        for(int j = n-1; j >= 0; --j){
            cout << solution[i][j] << " ";
        }
        //cout << endl;
    }
    cout << endl;
}


bool isSafe(int **solution, int row, int col, int n){
    // Check for queens in columns on the left side of current column.
    
    int i,j;
    
    for(i = 0; i < col; ++i){
        if(solution[row][i] == 1){
            return false;
        }
    }
  	
    // Now we will check for upper left diagnoal.
    for(i = row, j = col; i >= 0 && j >= 0; --i, --j){
        if(solution[i][j] == 1){
            return false;
        }
    }
    
    // Now we will check for lower left diagonal.
    for( i = row, j = col; i < n && j >=0 ; ++i, --j){
        if(solution[i][j] == 1){
            return false;
        }
    }
    
    return true;
}

void helperFunction(int **solution, int n, int column){
	// For base case.
    // As we will check the viable position for queen from column to solumn soo, the base case is.
    if(column >= n){
        printBoard(solution, n);
        return;
    }
    
    // Now we need to check a viable position for the queen.
    for(int i = 0; i < n ; ++i){
        
        if(isSafe(solution,i,column,n)){
        	// We will make this current cell as visited.
        	solution[i][column] = 1;
            
            helperFunction(solution , n , column + 1);
                
            
            // If the cell is not viable, then unvisit.
            solution[i][column] = 0;
        }
    }
    
	return;
}


void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
	int **solution = new int*[n];
    for(int i = 0; i < n; ++i){
        solution[i] = new int[n];
        for(int j = 0; j < n; ++j){
            solution[i][j] = 0;
        }
    }
    helperFunction(solution, n, 0);

}

int main(){
	int n; 
	cin >> n ;
	placeNQueens(n);
	return 0;
}
