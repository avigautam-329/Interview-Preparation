#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i=0;i<n;++i){
		int num;
		cin >> arr[i];
	}
	
	//Implement lINEAR SEARCH.
	int k;
	cout << "Enter the element to be searched: ";
	cin >> k;
	
	bool found= false;
	int i;
	for(i=0;i<n;++i){
		if(arr[i] == k){
			found = true;
			break;
		}
	}
	if(found){
		cout << "The element was found at position: "<< i;
	}else{
		cout << " The e;ement was not found.";
	}
}
