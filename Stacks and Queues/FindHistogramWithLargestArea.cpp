#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    long long* findNSL(long long arr[] , int n){
        stack<int> s1;
        long long *ans = new long long[n];
        
        // For finding nearest smallest left, we will start for the left.
        ans[0] = -1;
        s1.push(0);
        
        for(int i = 1; i < n; i++){
            while(!s1.empty()){
                if(arr[s1.top()] < arr[i]){
                    ans[i] = s1.top();
                    break;
                }else{
                    s1.pop();
                }
            }
            
            if(s1.empty()){
                ans[i] = -1;
            }
            
            s1.push(i);
        }
        
        return ans;
    }
    
    long long* findNSR(long long arr[] , int n){
        stack<int> s1;
        long long *ans = new long long[n];
        
        // For finding nearest smallest left, we will start for the left.
        ans[n - 1] = n;
        s1.push(n - 1);
        
        for(int i = n - 2; i >= 0; i--){
            while(!s1.empty()){
                if(arr[s1.top()] < arr[i]){
                    ans[i] = s1.top();
                    break;
                }else{
                    s1.pop();
                }
            }
            
            if(s1.empty()){
                ans[i] = n;
            }
            
            s1.push(i);
        }
        
        return ans;
    }
    
    
    long long getMaxArea(long long arr[], int n)
    {
        long long *nsl = findNSL(arr , n);
        long long *nsr = findNSR(arr , n);
        
        
        long long maxArea = INT_MIN;
        
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea , (nsr[i] - nsl[i] - 1) * arr[i]);
        }
        
        return maxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
