#include<iostream>

using namespace std;

int main(){
	
	int n , i;
	cin >> n >> i;
	
	// As the left shit operator multiplies by pow(2,i), soo to save time we can do this as well.
	int m = 1 << i;
	
	int ans = n & m;
	if(ans == 0){
		cout << "The i'th bit is set.(1)" << endl;
	}else{
		cout << "The i'th bit is not set.(0)" << endl;
	}
	return 0;
}
