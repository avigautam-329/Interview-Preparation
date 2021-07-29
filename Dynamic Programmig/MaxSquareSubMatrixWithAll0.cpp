#include<bits/stdc++.h>
#include<climits>
using namespace std;


int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	if(n == 0 || m == 0){
		return 0;
	}
	// The Dp array should be of the same size as the input array.
	vector<vector<int> > dp(n,vector<int>(m,0));
	
	int maxDimension = INT_MIN;
	
	// Now initialize the base case of the tabulation array.
	
	// To fill the values for the first row.
	for(int i = 0; i < m; i++){
		if(arr[0][i] == 0){
			dp[0][i] = 1;
		}
	}
	
	// To fill up the value for the first column.
	for(int i = 0; i < n; i++){
		if(arr[i][0] == 0){
			dp[i][0] = 1;
		}
	}
	
	// Now we will assign the required values.
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
            if(arr[i][j] == 0){
                
				dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
				if(dp[i][j] > maxDimension){
					maxDimension = dp[i][j];
				}
            }else{
				dp[i][j] = 0;                
            }

		}
	}
	
	return maxDimension; 
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
