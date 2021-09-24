class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        map<int , int> elemPos;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            elemPos[arr[i]] = i;
        }
        
        for(int i = 0; i < n; i++){

            if(elemPos.find(-1 * arr[i]) != elemPos.end()){
                
                if(arr[i] < 0){
                    ans.push_back(arr[i]);
                    ans.push_back(-1 *arr[i]);      
                }else{
                    ans.push_back(-1 *arr[i]);
                    ans.push_back(arr[i]); 
                }
                
                elemPos.erase(arr[i]);
                elemPos.erase(-1 * arr[i]);
            }

        }
        
        if(ans.size() == 0){
            ans.push_back(0);
        }
        
        return ans;
    }
};
