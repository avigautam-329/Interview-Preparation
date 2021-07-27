#include<bits/stdc++.h>
using namespace std;

int alphaCode(int *num, int size){
	if(size == 0 || size == 1){
		return 1;
	}
	
	int smallAns = alphaCode(num , size - 1);
	
	// Now we have to club to integers to get a code and call for size - 2 as well.
	if((10 * num[size - 2]) + num[size - 1] <= 26){
		smallAns += alphaCode(num , size - 2);
	}
	
	return smallAns;
}


// Dynaic Programming using Memorization.
int alphaCodeDp1(int *num, int size, int *memo){
	
	if(size == 0 || size == 1){
		return 1;
	}
	
	if(memo[size] > 0){
		return memo[size];
	}
	
	int smallAns = alphaCodeDp1(num , size - 1, memo);
	if((num[size - 2] * 10 )+ num[size - 1] <= 26){
		smallAns += alphaCodeDp1(num , size - 2, memo);
	}
	
	// Before returning we will save it in the memo array as well.
	memo[size] = smallAns;
	return smallAns;	
}

int alphaCodeDp2(int *num, int size, int *tab){
	tab[0] = tab[1] = 1;
	for(int i = 2; i < size + 1; ++i){
		tab[i] += tab[i - 1];
		if((num[i - 1] * 10 )+ num[i] <= 26){
			tab[i] += tab[i - 2];
		}
	}
	return tab[size];
}


int main(){
	
	int n;
	cin >> n;
	
	int *num = new int[n + 1];
	for(int i = 0; i < n ; ++i){
		cin >> num[i];
	}
	
	int codes = alphaCode(num , n);
	
	cout << "The number of codes are : " << codes << endl;
	
	// Now we will do it using DP with memorization technique.
	int *memo = new int[n + 1];
	for(int i = 0; i < n + 1; ++i){
		memo[i] = 0;
	}
	
	codes = alphaCodeDp1(num , n , memo);
	cout << "Using DP memorization : " << endl;
	cout << "The number of codes are : " << codes << endl; 
	
	
	int *tab = new int[n + 1];
	for(int i = 0; i < n + 1; ++i){
		tab[i] = 0;
	}
	
	codes = alphaCodeDp2(num , n , tab);
	cout << "Using DP tabulation / iteration : " << endl;
	cout << "The number of codes are : " << codes << endl; 
	return 0;
}
