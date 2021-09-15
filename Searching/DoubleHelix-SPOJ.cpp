#include<bits/stdc++.h>
using namespace std;

int maxSumPath(int arr1[], int n1, int arr2[], int n2){
	int i = 0, j = 0;
	int sum1 = 0, sum2 = 0;
	int maxSum = 0;
	
	while(i < n1 && j < n2){
		if(arr1[i] < arr2[j]){
			sum1 += arr1[i++];
		}else if(arr1[i] > arr2[j]){
			sum2 += arr2[j++];
		}else{
			// When we have an intersection point.
			maxSum += max(sum1 , sum2);
			
			sum1 = 0;
			sum2 = 0;
			
			maxSum += arr2[j];
			i++;
			j++;
		}
	}
	
	while(i < n1){
		sum1 += arr1[i++];
	}
	while(j < n2){
		sum2 += arr2[j++];
	}
	
	maxSum += max(sum1, sum2);
	return maxSum;
}

int main(){
	
	vector<int> ans;
	while(1){
		int n1;
		cin >> n1;
		
		// Condition to break out of the for loop.
		if(n1 == 0){
			break;
		}
		
		int arr1[n1];
		for(int i = 0; i < n1; i++){
			cin >> arr1[i];
		}
		
		int n2;
		cin >> n2;
		
		int arr2[n2];
		for(int i = 0; i < n2; i++){
			cin >> arr2[i];
		}
				
		int maxSum = maxSumPath(arr1 , n1, arr2, n2);
		ans.push_back(maxSum);
	}
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans.at(i) << endl;
	}
	return 0;
}
