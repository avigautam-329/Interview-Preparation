/*
You have been given a random integer array/list(ARR) of size N. You have been required to push all the zeros that are present in the array/list to the end of it. Also, make sure to maintain the relative order of the non-zero elements.
Note:
Change in the input array/list itself. You don't need to return or print the elements.

You need to do this in one scan of array only. Don't use extra space.


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the elements of the array/list in the desired order separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
7
2 0 0 1 3 0 0
Sample Output 1:
2 1 3 0 0 0 0
*/
#include<bits/stdc++.h>
using namespace std;

// Time complexity = O(n) -> Hence done in a single scan.
// Space Complexity = O(1) -> Constant Space Required.

void pushZeroesEnd(int *arr, int n){
	//Count is ti count the number odf non-zero elements.
	//First step is to move all the non zewro elements to the start and count them as well.
	int count = 0;
	int i = 0;
	
	
	// IN THIS LOOP WE WIL COPY ALL THE NON ZERO ELEMENTS TO THE START AND COUNT THEM AS WELL.
	for(i; i < n;++i){
		if(arr[i] != 0){
			arr[count++] = arr[i];
		}
	}
	
	// IN THE NEXT LOOP WE WILL FILL THE REMAINING VALUES WITH ZERO.
	while(count < n){
		arr[count++] = 0;
	}
	
}

int main(){
	int n;
	cin >> n;
	
	
	int *arr = new int[n];
	for(int i=0;i<n;++i){
		cin >> arr[i];
	}
	
	pushZeroesEnd(arr,n);
	
	for(int i=0;i<n;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
