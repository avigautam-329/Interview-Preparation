#include <bits/stdc++.h>
#include <cstring>
typedef long long ll;
using namespace std;

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
	if(n == 0){
		return 0;
	}
	
	int *tab = new int[n];
	for(int i = 0; i < n; ++i){
		tab[i] = 1;
	}
	
    int finalAns = INT_MIN;
	
	for(int i = 1; i < n ; ++i){
		
		int maxLength = INT_MIN;
		for(int j = i - 1 ; j >= 0; --j){
			if(arr[j] < arr[i]){
				if(tab[j] >= maxLength){
					maxLength = tab[j];
					tab[i] = maxLength + 1;
				}
			}
		}
        
        // This contains the length of the logest increasing subsequence.
        if(tab[i] >= finalAns){
            finalAns = tab[i];
        }
		
		
	}
	
	return finalAns;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
    return 0;
}
