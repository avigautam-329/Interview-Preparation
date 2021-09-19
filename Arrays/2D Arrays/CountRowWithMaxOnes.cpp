#include<iostream>
using namespace std;

/*
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    
	    // We will start from the top most right side.
	    // The intution is written in notes.
	    int col = m - 1;
	    int row = -1;
	    
        for(int i = 0; i < n; i++){
            
            for(int j = col ; j >= 0; j--){
                if(arr[i][j] == 1){
                    // First we will make this row the max row with one's.
                    row = i;
                    
                    // Second we will also  decrement the value of col.
                    // This is done soo that we dont visit this column again as we have found a 
                    // max 1's row for that column.
                    col--;
                }else{
                    
                    // If arr[i][j] == 0 then we don't need to traverse that row and we can
                    // move to the next row.
                    break;
                }
                
            }
        }
        
        return row;
	}
};
*/




// My code, same time complexity as the previous one, T.c = O(n + m).
int countMaxOnes(int **matrix, int n, int m){
	int i = 0, j = m - 1;
	int res = -1;
	
	while(i < n && j >= 0){
		if(matrix[i][j] == 1){
			res = i;
			j--;
		}else{
			i++;
		}
	}
	
	return res;
}

int main(){
	int n , m;
	cin >> n >> m;
	
	int **matrix = new int*[n];
	for(int i = 0; i < n; i++){
		matrix[i] = new int[m];
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	
	int maxOnes = countMaxOnes(matrix , n , m);
	
	cout << maxOnes << endl;
	
	return 0;
}
