#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    
        // To find out the number of trailing zeroes, we need the number of 5 in the prime factor of x:
        // count = floor(x / 5) + floor(x / 25) + floor(x / 125) + ....
        bool isValid(int x , int n){
            int count = 0;
            int den = 5;
            
            while(den <= x){
                count += (x / den);
                den *= 5;
            }
            
            return count >= n;
        }
    
        int findNum(int n)
        {
            
            if(n == 1){
                return 5;
            }
            // Going according to maths.
            // The minimum factorial conatining n zeros is given by (5 * n);
            // hence our lower and upper bound of searches are:
            // Since lb < ub, soo our answer will be at lb.
            int lb = 0;
            int ub = 5 * n;
            
            //int ans = -1;
            
            while(lb < ub){
                int x = (lb + ub)/2;
                
                if(isValid(x , n)){
                    //ans = x;
                    ub = x;
                }else{
                    lb = x + 1;
                }
            }
            
            return lb;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends
