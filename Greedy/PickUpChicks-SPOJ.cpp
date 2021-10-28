#include<iostream>
using namespace std;

int main(){
	// n -> the initial locations of the chicks.
	// k -> minimum number of chicks that have to reach the barn.
	// b -> barn position.
	// t -> max time to reach the barn.
	
	int t;
	cin >> t;
	int x = 1;
	while(t--){
	
		int n , k , b , mt;
		cin >> n >> k >> b >> mt;
		
		int *chickPos = new int[n];
		for(int i = 0; i < n; i++){
			cin >> chickPos[i];
		}
		
		int *chickVelocity = new int[n];
		for(int i = 0; i < n; i++){
			cin >> chickVelocity[i];
		}
		
		int cannotReach = 0;
		int minSwaps = 0;
		
		
		int i = n - 1;
		int canReach = 0;
		while(i >= 0){
			int distToBeCovered = b - chickPos[i];
			
			int maxDistThatCanBeCovered = chickVelocity[i--] * mt;
			
			if(maxDistThatCanBeCovered >= distToBeCovered){
				canReach++;
				minSwaps += cannotReach;
			}else{
				cannotReach++;
			}
		}
		
		if(canReach >= k){
			cout << "Case #" << x << ": " << minSwaps;
		}else{
			cout << "Case #" << x << ": IMPOSSIBLE";
		}
		x++;
		cout << endl;
	}
	
	return 0;
}
