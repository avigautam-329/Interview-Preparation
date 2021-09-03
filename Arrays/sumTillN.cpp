#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(i % 5 != 0 && i % 7 != 0){
			sum += i;
		}
	}
	cout << sum;
	return 0;
}
