#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int target){
    sort(arr, arr + size);
    
    int i = 0, j = i + 1;
    while(j < size){
        int sum = arr[j] - arr[i];
        
        if(sum < target){
            j++;
        }else if(sum > target){
            i++;
        }else{
            return true;
        }
    }
    return false;
    
}
