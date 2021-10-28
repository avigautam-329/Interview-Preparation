#include<iostream>
#include<cstring>
using namespace std;

string getSmallestNumber(int sum, int digits){
	if(9 * digits < sum){
		return "-1";
	}
	
	string res = "";
	
	// Now we need to start with the rightmost digits place.
	for(int i = digits - 1; i >= 0; i--){
		if(i == 0){
			res = to_string(sum) + res;
		}else{
			if(sum > 9){
				res = to_string(9) + res;
				sum -= 9;
			}else{
				res = to_string(sum - 1) + res;
				sum = 1;
				
				
				while(i > 1){
					res = to_string(0) + res;
					i--;
				}
			}
		}
	}
	
	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int sum , digits;
		cin >> sum >> digits;
		
		string res = getSmallestNumber(sum , digits);
		
		cout << res << endl;
	}
	
	return 0;
}
