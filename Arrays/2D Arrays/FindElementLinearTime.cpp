#include<bits/stdc++.h>
using namespace std;


void findElement(int a[][100], int m, int n, int x){
	// j = n-1 is the top right column.
	int i = 0, j = n-1;
	
	
	//Cause i will move downwards and j will move towards left.
	while(i < m && j >= 0){
		if(a[i][j] == x){
			cout << i << " " << j << endl;
			return;
		}
		
		//Move downwards.
		//Move downwards if the element is greater than the top right.		
		else if(a[i][j] < x){
			++i;
		}
		
		//Move towards left.
		else{
			--j;
		}
	}
	
	cout << "-1" << endl;
	return;
}

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
	int a[100][100];
	int m,n;
	
	cin >> m >> n;
	
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	
	cout << "Enter the element to be searched: ";
	int val;
	cin >> val;
	
	printArray(a,m,n);
	
	//calling the function.
	findElement(a,m,n,val);
	
	return 0;
}
