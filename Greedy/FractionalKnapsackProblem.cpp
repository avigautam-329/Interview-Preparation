#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool comparator(Item a, Item b){

        
        return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
    }
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // The approach for this question is a greedy apprach.
        // We will sort the values in the array according to the (value/weight) ratio in decreasing order.
        
        sort(arr, arr + n, comparator);
        
        double res = 0.0;
        
        for(int i = 0; i < n; i++){
            // We have 2 choices, either the item can be fit as a whole or as a fraction.
            if(arr[i].weight <= W){
                res += arr[i].value / 1.0;
                W -= arr[i].weight;
            }else{
                double temp = ((double)arr[i].value / (double)arr[i].weight) * (double)W;
                res += temp;
                return res;
            }
        }
        
        return res;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
