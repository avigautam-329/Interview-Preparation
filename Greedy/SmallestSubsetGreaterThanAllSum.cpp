/*
Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.
Examples : 
 

Input : arr[] = {3, 1, 7, 1}
Output : 1
Smallest subset is {7}. Sum of
this subset is greater than all
other elements {3, 1, 1}

Input : arr[] = {2, 1, 2}
Output : 2
In this example one element is not 
enough. We can pick elements with 
values 1, 2 or 2, 2. In any case, 
the minimum count is 2.
*/

#include<bits/stdc++.h>
using namespace std;

int getMinElements(int* arr, int n, vector<int> &elements){
	sort(arr , arr + n);
	
	int sumAll = 0;
	for(int i = 0; i < n; i++){
		sumAll += arr[i];
	}
	
	int j = n - 1;
	
	int currSum = 0;
	int noOfElements = 0;
	while(j >= 1){
		sumAll -= arr[j];
		currSum += arr[j];
		noOfElements++;
		elements.push_back(arr[j--]);
		if(currSum > sumAll){
			return noOfElements;
		}
	}
	
	return 0;
}

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<int> elements;
	int minElements = getMinElements(arr , n, elements);
	
	cout << "The elements used are: " << endl;
	for(int i = 0; i < elements.size(); i++){
		cout << elements[i] << " ";
	}
	
	return 0;
}
