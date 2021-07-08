/*
You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
Note:
You need to change in the given array/list itself. Hence, no need to return or print anything. 
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers(all 0s, 1s and 2s) representing the elements in the array/list.
Output Format :
For each test case, print the sorted array/list elements in a row separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
7
0 1 2 0 2 0 1
Sample Output 1:
0 0 0 1 1 2 2 
Sample Input 2:
2
5
2 2 0 1 1
7
0 1 2 0 1 2 0
Sample Output 2:
0 1 1 2 2 
0 0 0 1 1 2 2
*/

#include<bits/stdc++.h>
using namespace std;

/*
The algorithm to do this question:
	- First create 2 variable to maintain the next position of the zeros and twos.
	- Evertime we encounter 0 or 2 we need to put them in their coorect place in the arry by swapping.
	- But for 2, we need to check wether it is being swapped with 0 or not.
	- If yes, we have to put  0 to its correct position after putting 2 to its correct position, hence no increment in 'i'.
*/

void swap(int *a, int *b){
	int *temp = a;
	a = b;
	b = temp;
}


// T.C = O(N) -> Single Scan
// S.C = O(1) -> Constant Space
void sort012(int *arr, int n){
	int nz = 0, nt = n-1;
	int i = 0;
	
	while(i <= nt){
		if(arr[i] == 0){
			swap(arr[i++],arr[nz++]);
		}
		
		// We didn't increment i as we need to check wether 2 has been replaced with 0 or not.
		else if(arr[i] == 2){
			swap(arr[i],arr[nt--]);
		}
		else{
			++i;
		}
	}
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i=0; i<n ; ++i){
		cin >> arr[i];
	}
	
	sort012(arr,n);
	
	for(int i=0; i<n ; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
