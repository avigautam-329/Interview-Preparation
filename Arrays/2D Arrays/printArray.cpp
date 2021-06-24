#include<bits/stdc++.h>
using namespace std;

//Correct way of calling non dynamic arrays.
void printArray(int a[][100],int m, int n){
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n ; ++j){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


int main(){
	int m , n;
	int a[100][100];
	
	cin >> m >> n;
	
	for(int i=0; i < m;++i){
		for(int j = 0; j < n ; ++j){
			cin >> a[i][j] ;
		}
	}
	
	//Function to print the elements.
	
	printArray(a,m,n);
	
	return 0;
}
