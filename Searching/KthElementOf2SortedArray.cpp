#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    int binarySearch(int arr1[], int arr2[], int n, int m, int k){
        
        // We will always search in the smaller array.
        if(n > m){
            binarySearch(arr2, arr1 , m , n , k);
        }
        
        // This is to just reduce our search by creating a starting and a definite starting point such that
        // The element k will lie in between.
        
        
        // These start and end indices decide on which half does the elements lie on.
        int start = max(0 , k - m), end = min(k , n);
        while(start <= end){
            
            //All of this code has the same intuition as that of 
            // median of 2 sorted arrays.
            int cut1 = (start + end)/2;
            int cut2 = k - cut1;
            
            int l1 = (cut1 == 0)?INT_MIN:arr1[cut1 - 1];
            int l2 = (cut2 == 0)?INT_MIN:arr2[cut2 - 1];
            int r1 = (cut1 == n)?INT_MAX:arr1[cut1];
            int r2 = (cut2 == m)?INT_MAX:arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1 , l2);
            }
            else if(l1 > r2){
                end = cut1 - 1;
            }else{
                start = cut1 + 1;
            }
            
        }
        
        return 1;
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {

        int elem = binarySearch(arr1, arr2 , n , m , k);
        return elem;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends
