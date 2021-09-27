#include<iostream>
using namespace std;

// This is the naive solution.
//	1. We will keep 2 arrays.
//		- in[n] = for each value of in[i] will hold, how many people know the i'th person.
//		- out[n] = for each value of out[i] will hold, how many people does the i'th person know.
//	2. After populating these 2 arrays, we will then finally check if for an i'th person in in[n] and out[n], if the i'th person in known by everyone but deos not know anyone.
 
// Time Complexity: O(n^2)
// Space Complexity: O(n)

int findCeleb(int **matrix , int n){
	// Let's create the 2 arrays.
	int in[n] = {0};
	int out[n] = {0};
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == 1){
				in[j]++;
				out[i]++;
			}	
		}

	}
	
	// Now we look for the celebrity using another for loop.
	for(int i = 0; i < n; i++){
		if(in[i] == n - 1 && out[i] == 0){
			return i;
		}
	}
	
	return -1;
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
