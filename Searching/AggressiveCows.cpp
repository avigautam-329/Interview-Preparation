#include<iostream>
#include<algorithm>
typedef long long int lli;
using namespace std;

lli binarySearch(lli *arr, lli n, lli c){
	// Now we need to define a few variables.
	// The x will lie between the upperbound and lower bound values.
	// The lower and upper bound can be seen from the constraints.
	lli lb = 1;
	lli ub = 10e9;
	
	lli ans = -1;
	lli x;
	
	while(lb <= ub){
		
		// x is the distance we are taking between each cows.
		x = (lb + ub)/2;
		
		// As we will always keep a cow at the first stall soo...
		lli noOfCowsPlaced = 1;
		
		// This will keep the idea of the last stall in which the cow was placed.
		lli prev = arr[0];
		
		for(lli i = 1; i < n; i++){
			
			// This is the correct solution.
			if(arr[i] - prev >= x){
				
				prev = arr[i];
				noOfCowsPlaced++;
				if(noOfCowsPlaced == c){
					ans = x;
					break;
				}
			}
		}
		
		// Once out of the loop we need to check whether all of the cows are placed or not.
		if(noOfCowsPlaced == c){
			ans = x;
			lb = x + 1;
		}else{
			ub = x - 1;
		}
	}
	
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		// n = number of stalls and c = number of cows.
		lli n , c;
		
		cin >> n >> c;
		
		lli arr[n];
		for(int i  =0; i < n; i++){
			cin >> arr[i];
		}
		
		//After creating the array we also need to sort it.
		sort(arr , arr+n);
		
		lli largestMinDist = binarySearch(arr , n , c);
		cout << largestMinDist << endl;
			
	}
	return 0;
	
}
