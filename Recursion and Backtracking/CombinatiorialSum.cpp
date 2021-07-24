#include <bits/stdc++.h>
#include <vector>
using namespace std;

void helperFunction(vector<int>& input, int sum , int startIndex , vector<int>& output, vector<vector<int>>& res){
    // Base case.
    if(sum == 0){
    	res.push_back(output);
        return;
    }
    
    while(startIndex < input.size() && sum - input[startIndex] >= 0){
        output.push_back(input[startIndex]);
        
        // Basically we will call the while loop fir current element if see if the current element can add up to sum.
        helperFunction(input , sum - input[startIndex], startIndex, output , res);
        startIndex++;
        
        output.pop_back();
        
    }
    
}

vector<vector<int> > combinationSum(vector<int>& ar, int sum){

    // Sort the given array.
	sort(ar.begin(),ar.end());
    
    // Remove the duplicates from the array.
    ar.erase(unique(ar.begin(),ar.end()),ar.end());
    
    vector<int> output;
    vector<vector<int>> res;
    
    helperFunction(ar , sum , 0 , output , res);
    return res;
}

int main(){
    int n;
    cin >> n;
    int x;
	vector<int> ar;
    for(int i = 0; i < n; i++){
        cin >> x;
    	ar.push_back(x);
    }
    int sum;
    cin >> sum;
	vector<vector<int> > res = combinationSum(ar, sum);
	if (res.size() == 0) {
		cout << "Empty";
		return 0;
	}
	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
