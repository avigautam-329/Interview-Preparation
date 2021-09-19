#include<iostream>
using namespace std;

void transpose(int **matrix, int n){
	for(int i = 0; i < n;i++){
		for(int j = i + 1; j < n; j++){
			swap(matrix[i][j] , matrix[j][i]);
		}
	}
}

void rotate90(int **matrix, int n){
	// First step is to transpose the matrix.
	transpose(matrix , n);
	
	// Next step is to mirror about the column mid.
	for(int row = 0; row < n; row++){
		int i = 0 , j = n - 1;
		while(i < j){
			swap(matrix[row][i++] , matrix[row][j--]);
		}
	}

}

int main(){
	int n;
	cin >> n;
	
	int **matrix = new int*[n];
	for(int i = 0; i < n; i++){
		matrix[i] = new int[n];
		for(int j = 0; j < n;j++){
			cin >> matrix[i][j];
		}
	}
	
	rotate90(matrix, n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
