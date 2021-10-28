#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long *arr1 , int size1 , long long *arr2, int size2, long long int& count, long long arr[]){
        int i = 0, j = 0;
        int k = 0;
        while(i < size1 && j < size2){
            if(arr1[i] <= arr2[j]){
                arr[k++] = arr1[i++];
            }else{
                count += (long long int)(size1 - i);
                arr[k++] = arr2[j++];
                
            }
        }
        
        while(i < size1){
            arr[k++] = arr1[i++];
        }
        
        while(j < size2){
            arr[k++] = arr2[j++];
        }
        
    }
    
    
    void mergeSort(long long arr[], long long size , long long int& count){
        if(size == 0 || size == 1){
            return;
        }
        
        int mid = size / 2;
        int size1 = mid;
        int size2 = size - mid;
        
        long long *arr1 = new long long[size1];
        long long *arr2 = new long long[size2];
        for(int i = 0; i < size1; i++){
            arr1[i] = arr[i];
        }
        
        int k = 0;
        for(int i = size1; i < size ; i++){
            arr2[k++] = arr[i];
        }
        
        mergeSort(arr1 , size1 , count);
        mergeSort(arr2 , size2 , count);
        merge(arr1 , size1 , arr2 , size2 , count , arr);
        
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long int count = 0;
        mergeSort(arr , N , count);
        
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
