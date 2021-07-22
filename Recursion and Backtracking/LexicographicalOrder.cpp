#include <bits/stdc++.h>
using namespace std;

void helperFunction(int num, int start){
    if(start * 10 > num){
        //cout << num << endl;
        return;
    }
    
    for(int i = start * 10 ; i < (start + 1) * 10 && i <= num; ++i){
        cout << i << endl;
        helperFunction(num, i);
    }
}

void lexicographicalOrder(int num){
	// Write your code here
    
    for(int i = 1; i <= 9 && i <= num; ++i){
        cout << i << endl;
        helperFunction(num, i);
    }
}

int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
}
