#include<iostream>
#include<tr1/unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicate(int *arr, int n){
	
	vector<int> output;
	std::tr1::unordered_map<int , bool> is_visited;
	
	for(int i = 0; i < n;++i){
		
		// We will check wether we have visited that element before.
		// If soo , then just continue normally.
		if(is_visited.count(arr[i]) > 0){
			continue;
		}
		
		//Else
		is_visited[arr[i]] = true;
		output.push_back(arr[i]);
	}
	
	return output;
}

int main(){
	int n;
	cin >> n;
	int *input = new int[n];
	
	for(int i = 0 ; i < n ; ++i){
		cin >> input[i];
	}
	
	vector<int> output = removeDuplicate(input, n);
	
	int j = 0;
	while(j < output.size()){
		
		cout << output.at(j) << " ";
		++j;
		
	}
	cout << endl;
}
