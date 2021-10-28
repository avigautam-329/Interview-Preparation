//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++
#include<unordered_map>

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_map<int,int> isPresent;
        int count = 0;
        for(int i = 0; i < n ; i++){
            if(isPresent.count(a[i]) <= 0){
                isPresent[a[i]]++;
                count++;
            }
        }
        
        for(int i = 0; i < m; i++){
            if(isPresent.count(b[i]) <= 0){
                isPresent[b[i]]++;
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
