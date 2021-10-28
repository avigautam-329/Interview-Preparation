#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //In theory we have to take the intersection of all 3 arrays.
            if(n1 == 0 || n2 == 0 || n3 == 0){
                vector<int> finalAns;
                finalAns.push_back(-1);
                return finalAns;
            }
            vector<int> finalAns;
            
            // For storing elements in the unordered_map.
            unordered_map<int , int> firstArray;
            unordered_map<int , int> secondArray;
            map<int , int>  finalElements;
            
            for(int i = 0; i < n1; i++){
                firstArray[A[i]]++;
            }
            
            for(int i = 0; i < n2; i++){
                secondArray[B[i]]++;
            }
            
            for(int i = 0; i < n3; i++){
                if(firstArray.find(C[i]) != firstArray.end() && secondArray.find(C[i]) != secondArray.end()){
                    if(firstArray[C[i]] > 0 && secondArray[C[i]] > 0){
                        finalAns.push_back(C[i]);
                        firstArray[C[i]] = 0;
                        secondArray[C[i]] = 0;
                    }
                }
            }
            
            return finalAns;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends
