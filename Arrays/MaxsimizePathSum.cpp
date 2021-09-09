#include<bits/stdc++.h>
using namespace std;

int maxSumPath(int *arr1, int arr2, int n, int m){
    
    // First we need to initialize the variables.
    int maxSum = 0;
    int sum1 = 0, sum2 = 0;
    int i = 0, j = 0;
        
    while(i < n && j < m){
            
    	// This is where we add to the 2 options that we have which are sum1 and sum2 before the intersection point.
        if(arr1[i] < arr2[j]){
            sum1 += arr1[i++];
        }
        else if(arr1[i] > arr2[j]){
            sum2 += arr2[j++];
        }
            
        // This is where we have reached the intersection point.
        else{
            // Since we only need the maximum answer.
            maxSum += max(sum1, sum2);
                
            sum1 = 0;
            sum2 = 0;
                
            // Now we also need to add the value of the intersection point to the result.
            maxSum += arr1[i++];
            j++;
        }
    }
        
    // If some elements have been missed then we can simply add them in the result.
    while(i < n){
        sum1 += arr1[i++];
    }
        
    while(j < m){
        sum2 += arr2[j++];
    }
        
    maxSum += max(sum1, sum2);
        
    return maxSum;
}

int main(){
	int n, m;
	cin >> n >> m;
	
	int *arr1 = new int[n];
	int *arr2 = new int[m];
	
	for(int i =0; i < n; i++){
		cin >> arr1[i];
	}
	
	for(int j = 0; j < m; j++){
		cin >> arr2[j];
	}
	
	cout << maxSumPath(arr1, arr2, n , m) << endl;
	return 0;
}

