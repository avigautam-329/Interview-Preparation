#include<bits/stdc++.h>
using namespace std;



// First step is to find the inorder traversal for the given tree,
// The left child is at 2i + 1 and right child will be at 2i + 2.

void findInorderTraversal(int* arr, int n, vector<int>& in, int idx){
	if(idx >= n){
		return;
	}
	
	findInorderTraversal(arr , n , in , 2 * idx + 1);
	in.push_back(arr[idx]);
	findInorderTraversal(arr , n , in , 2 * idx + 2);
	
	return;
}


// To count minimum number of swaps we will use the same method as we do for arrays.



int findMinSwaps(int* arr, int n){
	if(n == 0 || n == 1){
		return 0;
	}
	
	vector<int> in; 
	findInorderTraversal(arr , n , in , 0);
	
	int countSwaps = 0;
	
	// First we need to create a vector of pair type to store the positions and sort to later compare swaps.
	vector<pair<int , int> > sortedArray;
	for(int i = 0; i < n; i++){
		sortedArray.push_back({in[i] , i});
	}
	
	sort(sortedArray.begin() , sortedArray.end());
	
	// Now we shall compare, the poisitons of elements in the sorted array with the original array.
	for(int i = 0; i < n; i++){
		if(i == sortedArray[i].second){
			continue;
		}else{
			countSwaps++;
			swap(sortedArray[i] , sortedArray[sortedArray[i].second]);
			
			i--;
		}
	}
	
	return countSwaps;
}


int main(){
	// First we will take the normal input of the tree in an array.
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n;i++){
		cin >> arr[i];
	}
	
	int minSwaps = findMinSwaps(arr , n);
	
	cout << "The minimum inversions required are: " << minSwaps << endl;
	
	return 0;
}
