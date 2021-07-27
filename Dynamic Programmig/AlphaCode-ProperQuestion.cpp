#include <bits/stdc++.h>
#include <cstring>
typedef long long ll;
using namespace std;

/*
This is a working code, it passed all the test cases of the original question on HackerEarth.
Soo this is the correct solution and the one in coding ninjas is wrong.
*/

int main(){
	
	vector<ll> finalAns;
	string num;
	while(1){
		cin >> num;
		if(num != "0"){
			
			ll length = num.size();
			
			ll *tab = new ll[length + 1];
			for(int i = 0; i < length + 1; ++i){
				tab[i] = 0;
			}
			
			tab[0] = 1;
			tab[1] = 1;
			
			for(ll i = 2 ; i < length + 1; ++i){
				
				
				// When we are adding the single character to the previous string.
				// The no. of codes will not change as if I add c to ab , then abc is still having only 1 possible code, which is itself abc.
				if(num[i-1] - '0' > 0){
					tab[i] = tab[i - 1];
				}
				
				ll val = (num[i - 2] - '0')* 10 + num[i - 1] - '0';
				
				if(val >= 10 && val <= 26){
					if(i == 2){
						tab[i] += tab[1];
					}else{
						tab[i] += tab[i - 2];
					}
				}	
			}
			
			finalAns.push_back(tab[length]);
		}else{
			break;
		}
	}
	
	for(ll i = 0; i < finalAns.size(); ++i){
		cout << finalAns.at(i) << endl;
	}
	return 0;
	
}
