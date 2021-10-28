#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int ones = 0;
		int *arr = new int[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			if(arr[i] == 1){
				ones++;
			}
		}
		
		// Sorting in descending order inititally.
		sort(arr , arr + n, greater<int>());
		
		// Now as we have the numbner of ones, we will print the ones first.
		for(int i = 0; i < ones; i++){
			cout << "1 ";
		}
		
		// Next we need to take care of case 3 and case 2.
		if(n - ones == 2 && arr[0] == 3 && arr[1] == 2){
			cout << "2 3" << endl;
		}else{
			for(int i = 0; i < n- ones; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
