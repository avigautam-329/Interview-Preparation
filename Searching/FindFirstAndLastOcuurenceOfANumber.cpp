#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


int binarySearch(int arr[], int n, int target, char flag){
    
    int start = 0, end = n - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == target){
            // I have 2 ways to return an answer.
            if(flag == 'f'){
                if(mid == 0 || arr[mid - 1] != arr[mid]){
                    return mid;
                }else{
                    end = mid - 1;
                }
            }
            
            if(flag == 'l'){
                if(mid == n - 1 || arr[mid + 1] != arr[mid]){
                    return mid;
                }else{
                    start = mid + 1;
                }
            }
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    
    return -1;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    int firstOccur = binarySearch(arr , n , x , 'f');
    int lastOccur = binarySearch(arr , n , x, 'l');
    
    vector<int> ans;
    ans.push_back(firstOccur);
    ans.push_back(lastOccur);
    return ans;
}
