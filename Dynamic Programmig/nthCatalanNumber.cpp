#include<bits/stdc++.h>
using namespace std;

int catalanDp(int n){
	// Create the dp array.
	vector<int> catalan(n+1,0);
	catalan[0] = catalan[1] = 1;
	for(int i = 2; i < n + 1; ++i){
		for(int j = 0; j < i ; ++j){
			catalan[i] += catalan[j] * catalan[i - j - 1];
		}
	}
	
	return catalan[n];
}

int main(){
	int n;
	cin >> n;
	
	cout << "The nth Catalan Number is : " << catalanDp(n) << endl;   
	return 0;
}
