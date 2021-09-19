#include<iostream>
using namespace std;

// Time Complexity = O(n^2log(n))
// Space Complexity = O(n^2)


int nextGap(int gap){
	if(gap <= 1){
		return 0;
	}
	return (gap / 2) + (gap % 2);
}

void merge(int *arr, int start, int mid , int end , int size){
	int i;
	int gap = end - start + 1;
	
	for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)){
		for(int i = start; i + gap <= end; i++){
			if(arr[i] >= arr[i + gap]){
				swap(arr[i] , arr[i + gap]);
			}
		}
	}
	
	return;
}


void mergeSort(int *arr, int start, int end, int size){
	if(start >= end){
		return;
	}
	
	int mid = start + (end - start) / 2;
	mergeSort(arr, start , mid, size);
	mergeSort(arr, mid + 1, end , size);
	
	merge(arr , start , mid , end, size);
}

int** sortMatrixRowCol(int **matrix, int n, int m){
	// The first step is to flatten out the matrix.
	int *temp = new int[n * m];
	int k = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			temp[k++] = matrix[i][j];
		}
	}
	// Now our matrix is flattened into a 1D array.
	
	mergeSort(temp, 0 , (n * m) - 1, (n * m));
	
	int **ans = new int*[n];
	k = 0;
	for(int i = 0; i < n; i++){
		ans[i] = new int[m];
		for(int j = 0; j < m; j++){
			ans[i][j] = temp[k++]; 
		}
	}
	
	
	return ans;
}


int main(){
	int n , m;
	cin >> n >> m;
	
	int **matrix = new int*[n];
	for(int i = 0; i < n; i++){
		matrix[i] = new int[m];
		for(int j = 0 ; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	
	cout << "Before sorting row and column Wise: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			 cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int **sorted = sortMatrixRowCol(matrix , n, m);
	
	cout << "After sorting row and column wise: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			 cout << sorted[i][j] << " ";
		}
		cout << endl;
	}
}
