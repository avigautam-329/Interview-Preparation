//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#include <queue>
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> kthsmallest;
        priority_queue<int, vector<int>, greater<int> > kthlargest;
        int i = 0;
        while(i != k){
            kthsmallest.push(arr[i]);
            kthlargest.push(arr[i]);
            i++;
        }
        
        while(i <= r){
            if(arr[i] < kthsmallest.top()){
                kthsmallest.pop();
                kthsmallest.push(arr[i]);
            }
            i++;
        }
        return kthsmallest.top();
    }
    
    
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
