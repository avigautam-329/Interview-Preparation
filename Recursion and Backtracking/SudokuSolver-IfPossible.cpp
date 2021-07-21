/*
Code : Sudoku

Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.

Input Format :
9 Lines where ith line contains ith row elements separated by space

Output Format :
 true or false

Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6

Sample Output :
true

*/

#include<bits/stdc++.h>
using namespace std;

/*
	1. First we need to find an unassigned cell.
		-> We need to see if the sudoku is already filled or not.
		-> If not then assign the rows and columns with the unassigned values.
	2. We need to run a loop on the options we have for that cell.(1...9)
		-> We will take every option and check if it is safe to use.
	3. We need to make a funtion to see if the current option is safe to use or not.
		-> No duplicates in rows.
		-> No duplicates in columns.
		-> No duplicates in the grid.
		-> We need to have a function for each of this and in the end an isSafe() function.
	4. In the end if we go for it with an option, we will go forward and if in the end it is wrong then we will return false in the end.
	5. 
*/



// Writing the first function to check for Unassigned or empty cell.
bool findUnassignedCell(int board[9][9], int& rows, int& cols){
	for(rows = 0; rows < 9; ++rows){
		for(cols = 0; cols < 9; ++cols){
			if(board[rows][cols] == 0){
				return true;
			}
		}
	}
	return false;
}

// To check whether the current option is suitable for the row.
bool usedInRow(int board[9][9], int row, int option){
	for(int i = 0; i < 9; ++i){
		if(board[row][i] == option){
			return true;
		}
	}
	return false;
}

// To check whether the current option is suitable for the column.
bool usedInColumn(int board[9][9], int col, int option){
	for(int i = 0; i < 9; ++i){
		if(board[i][col] == option){
			return true;
		}
	}
	return false;
}

// To check whether the current option is present in the current grid or not.
bool usedInGrid(int board[9][9], int startRow, int startColumn, int option){
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(board[startRow + i][startColumn + j] == option){
				return true;	
			}
		}
	}
	return false;
}

// This is to check for the option and is it safe to use or not.
bool isSafe(int board[9][9], int rows, int cols, int option){
	return !usedInRow(board,rows,option) &&
			!usedInColumn(board,cols,option) &&
			!usedInGrid(board,rows - (rows % 3), cols - (cols % 3),option) &&
			board[rows][cols] == 0;
}

bool sudokuSolver(int board[][9]){

	// Initialize the rows and columns which will be assigned by reference in the check for an empty cell.
	int rows , cols;
	 
	// First we need to check whether the sudoku is already filled or not.
	if(!findUnassignedCell(board, rows, cols)){
		return true;
	}
	
	// Consider all the options frm 1 to 9.
	for(int option = 1; option <= 9 ; ++option){
		
		// We check whether the option is safe to use or not.
		if(isSafe(board,rows,cols,option)){
			
			// Make the assignment to the the cell for now.
			board[rows][cols] = option;
			
			// Now to call recursion on the rest of the board and see if we can find out answer.
			if(sudokuSolver(board)){
				return true;
			}
				
			// If we are not able to return true, it means that the option taken was wrong at some point.
			// Hence unassign the option in the grid as well.
			
			board[rows][cols] = 0; 
		}
	}
	
	return false;
}

int main(){
	int n = 9; 
	int board[9][9];
	for(int i = 0; i < n ;i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}		
	}
	if(sudokuSolver(board)){
		cout << "true";	
	}else{
		cout << "false";	
	}
	return 0;
}
