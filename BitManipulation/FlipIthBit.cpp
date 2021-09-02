#include<iostream>
using namespace std;

int main(){
	int n , i;
	cin >> n >> i;
	
	int m = (1 << i);
	int ans = n ^ m;
	cout << "The number after flipping the i'th bit is : " << ans << endl;
	
	return 0;
}
