#include<iostream>
using namespace std;

// In this approach we will assume that in the starting c = 0 is the celebrity.
// Then we will loop and find if out current c know's anyone or not.
// If it does know , then c is no longer the celebrity and the new celebrity will be th i in this case.

// Once the loop finishes, we need to make sure that the potential celebrity we have found is known by everyone else.
// If not then we return -1.

// Time complexity : O(n)
// Space Complexity : O(1)

int findCeleb(int** matrix, int n){
	int c = 0;
	
	for(int i = 0; i < n; i++){
		if(matrix[c][i] == 1){
			c = i;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(i != c && (matrix[c][i] == 1 || matrix[i][c] == 0)){
			return -1;
		}
	}
	return c;
}

int main(){
	int n;
	cin >> n;
	
	int **matrix = new int*[n];
	for(int i = 0; i < n ; i++){
		matrix[i] = new int[n];
		for(int j = 0; j < n ; j++){
			cin >> matrix[i][j];
		}
	}
	
	int celebrity = findCeleb(matrix, n);
	cout << "The celebreity is: " << celebrity << endl;
	
	return 0;
}
