//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // In this question, we have to figure out such a number, from the range given in the constraints
        // Such that the number is equal to the number of elements after the number.
        
        int lb = 1;
        int ub = 2000;
        
        int size = (r * c);
        
        // This will decide the number of elements that should be less than the given number x.
        int l = (size) / 2;
        while(lb <= ub){
            int x = (lb + ub) / 2;
            int countOfElements = 0;
            for(int i = 0; i < r; i++){
                int start = 0, end = c - 1;
                while(start <= end){
                    int mid = start + (end - start) / 2;
                    if(matrix[i][mid] <= x){
                        start = mid + 1;
                    }else{
                        end = mid - 1;
                    }
                }
                
                countOfElements += start;
            }
            
            if(countOfElements <= l){
                lb = x + 1;
            }else{
                ub = x - 1;
            }
        }
        
        return lb;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends
