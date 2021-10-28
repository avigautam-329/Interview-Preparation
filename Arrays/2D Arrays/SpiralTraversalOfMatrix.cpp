#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int fr = 0 , fc = 0;
        int lr = r - 1, lc = c - 1;
        
        int direction = 0;
        
        vector<int> ans;
        
        while(fr <= lr && fc <= lc){
            if(direction % 4 == 0){
                for(int i = fc ; i <= lc ; i++){
                    ans.push_back(matrix[fr][i]);
                }
                fr++;
                direction++;
            }
            
            else if(direction % 4 == 1){
                for(int i = fr; i <= lr; i++){
                    ans.push_back(matrix[i][lc]);
                }
                
                lc--;
                direction++;
            }
            
            else if(direction % 4 == 2){
                for(int i = lc ; i >= fc ; i--){
                    ans.push_back(matrix[lr][i]);
                }
                
                lr--;
                direction++;
            }
            
            else{
                for(int i = lr ; i >= fr; i--){
                    ans.push_back(matrix[i][fc]);
                }
                fc++;
                direction++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
