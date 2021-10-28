//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int arr[], int size)
{
        
    int currMaxElem = arr[0];
    int currMaxCount = 1;
        
    // After this for loop we will have out majority element of the array.
    for(int i = 0; i < size; i++){
        if(arr[i] != currMaxElem){
            currMaxCount--;
            if(!currMaxCount){
                currMaxElem = arr[i];
                currMaxCount = 1;
            }
        }else{
            if(i != 0)
                currMaxCount++;
        }
    }
    
    // But we still need to check whether this majority element satisfies the condition of its 
    // freq being greater than (size / 2).
    
    int flag = size/2;
    currMaxCount = 0;
    for(int i = 0; i < size; i++){
        if(currMaxElem == arr[i]){
            currMaxCount++;
        }
    }
    
    return (currMaxCount > flag)?currMaxElem:-1;
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
