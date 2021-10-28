#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    
	    // We will keep a vector of pair data type.
	    // Each pair will store the index and the value present at thet index.
	    // Then we will sort this vector using the value parameter of the pair.
	    // Lastly we will just try to form the original array from this sorted vector.
	    // This will be done as:
	    //  1. if the index i of the sorted vector is not equal to vector[i].second, this means 
	   //   that the element/pair at i has been moved from it's position in the original array. 
	int minSwaps(vector<int>&nums)
	{
        vector<pair<int , int>> sortedNums;
        for(int i = 0; i < nums.size(); i++){
            sortedNums.push_back({nums[i] , i});
        }
        
        // Now we will sort the sortedNums.
        sort(sortedNums.begin(), sortedNums.end());
        
        // After sorting, now we will try to make the original array.
        int countSwaps = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(i == sortedNums[i].second){
                continue;
            }else{
                countSwaps++;
                // This is to keep the pair in its correct position as comapred to the original nums vector.
                swap(sortedNums[i] , sortedNums[sortedNums[i].second]);
                
                // We decrement i to check if the swapped pair has reached to its correct position or not.
                i--;
            }
        }
        
        return countSwaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
