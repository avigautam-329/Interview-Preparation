#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	// Now to see if this is a power of 2 we will take its AND with n - 1;
	
	int ans = n & (n-1);
	if(ans == 0){
		cout << "Yes, a power of 2." << endl;
	}else{
		cout << "It's not a power of 2." << endl;
	}
	
	return 0;
}
