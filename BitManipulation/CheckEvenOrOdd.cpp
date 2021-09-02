#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	// Now to check even or odd, we have to check the LSB of the given number.
	// To do that, since 2^0 = 1, we can take the AND operator of n with 1.
	
	int ans = n & 1;
	if(ans == 0){
		cout << "Even" << endl;
	}else{
		cout << "Odd" << endl;
	}
	
	return 0;
}
