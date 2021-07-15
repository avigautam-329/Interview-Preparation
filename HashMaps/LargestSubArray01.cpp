#include<bits/stdc++.h>
#include<tr1/unordered_map>

using namespace std;

int max(int arr[], int n) {
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	int sum = 0;
	int maxLength = 0;
	
	std::tr1::unordered_map<int , bool> totalSum;
	
	for(int i =0; i < n; ++i){
		if(arr[i] == 0){
			sum += -1;
		}else{
			sum += 1;
		}
		
		totalSum[sum] = true;
		
	}
	
}

int main(){
	
    int n=0;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    	
    cout << max(arr,n);
    	
	return 0;
}
