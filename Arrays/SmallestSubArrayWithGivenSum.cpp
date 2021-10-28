#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int maxStart = INT_MIN, maxEnd = INT_MIN;
        int minLength = INT_MAX;
        
        int start = 0 , end = 0;
        int tempLength = 0;
        
        int sum = 0;
        
        while(end < n){
            sum += arr[end++];    
            while(sum > x && start <= end){
                
                tempLength = end - start;
                minLength = min(minLength , tempLength);
                sum -= arr[start++];
                
            }
            
            
        }
        
        return minLength;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends
