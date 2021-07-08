#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here
    std::tr1::unordered_map<int , int> negativeInteger;
    int totalCount = 0;
    
    for(int i =0; i < n; ++i){
        if(arr[i] <= 0){
            ++negativeInteger[arr[i]];
        }
    }
    
    for(int i = 0; i < n; ++i){
        if(negativeInteger.count(-arr[i]) > 0){
            for(int j = 0; j < negativeInteger[-arr[i]]; ++j){
            	totalCount++;    
            }
        }
    }
    return totalCount;
}

int main(){
	
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
