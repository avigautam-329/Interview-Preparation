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
            
    // Storing the elements of array A in the map.
    for(int i = 0; i < n1; i++){
        firstArray[A[i]]++;
    }
            
    // Similarly for array B.
    for(int i = 0; i < n2; i++){
        secondArray[B[i]]++;
    }
    
    
    // In this for loop we check whether the i'th element of third array is present in both the arrays or not.
    for(int i = 0; i < n3; i++){
        if(firstArray.find(C[i]) != firstArray.end() && secondArray.find(C[i]) != secondArray.end()){
            if(firstArray[C[i]] > 0 && secondArray[C[i]] > 0){
            	
            	// Here after pushing the common element in finalAns, we make the common elements frequencies in order to avoid duplication.
                finalAns.push_back(C[i]);
                firstArray[C[i]] = 0;
                secondArray[C[i]] = 0;
            }
        }
    }
            
    return finalAns;
}
