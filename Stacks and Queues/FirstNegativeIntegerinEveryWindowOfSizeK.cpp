#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
	vector<long long int> res;
	
	queue<long long int> onlyNegative;
	
	// Intially inputting the negative elements in the first window.
	for(long long int i = 0; i < k - 1; i++){
		if(arr[i] < 0){
			onlyNegative.push(arr[i]);
		}
	}
	
	// Now the first negative number occurence will always be at the front of the queue.
	long long int i = 0 , j = k - 1;
	while(j < n){
		// First we will put the last element of the current window, only if negative.
		if(arr[j] < 0){
			onlyNegative.push(arr[j]);
		}
		
		// Now we will see if the current window has a negative element or not.
		if(onlyNegative.size() == 0){
			res.push_back(0);
		}else{
			res.push_back(onlyNegative.front());
		}
		
		// Now that we have the negative from the current window, we need to remove it from the window and add the new element.
		if(arr[i] == onlyNegative.front()){
			onlyNegative.pop();
		}
		
		i++;
		j++;
	}
	
	
	return res;
 }
