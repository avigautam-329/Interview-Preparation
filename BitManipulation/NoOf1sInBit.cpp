#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int count = 0;
	
	while(n > 0){
		n = n & (n-1);
		count++;
	}
	
	cout << "The number of 1's in its binary representation are :" << count;
	return 0;
}
