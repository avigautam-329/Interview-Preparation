#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_map<int , bool> isVisited;
      
      for(int i = 0; i < N ;i++){
          isVisited[arr[i]] = false;
      }
      
      int tempLength = 0;
      int maxLength = INT_MIN;
      
      for(int i = 0; i < N; i++){
          
          // First we will check for elements ahead of arr[i].
          
          tempLength = 1;
          int k = arr[i];
          while(isVisited.count(++k) > 0 && !isVisited[k]){
              tempLength++;
              isVisited[k] = true;
          }
          
          k = arr[i];
          while(isVisited.count(--k) > 0 && !isVisited[k]){
              tempLength++;
              isVisited[k] = true;
          }
          
          arr[i] = true;
          if(tempLength > maxLength){
              maxLength = tempLength;
          }
      }
      return maxLength;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
