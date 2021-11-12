#include<bits/stdc++.h>
#include<unordered_map>
#include<cstring>
using namespace std;

int getCount(string binary){
	if(binary.size() == 0 || binary.size() == 1){
		return 0;
	}
	
	unordered_map<int , int> sumOfAll;
	
	
	
	int count = 0;
	int sum = 0;
	
	for(int i = 0; i < binary.size(); i++){
		if(binary[i] == '0'){
			sum += -1;
		}else{
			sum += 1;
		}
		if(sum == 0){
			count++;
		}else{
			if(sumOfAll.find(sum) != sumOfAll.end()){
				count += sumOfAll[sum];
				sumOfAll[sum]++;
			}
			else{
				sumOfAll[sum] = 1;
			}
		}
	}
	
	return count;
}

int main(){
	string binaryString;
	cin >> binaryString;
	
	int count = getCount(binaryString);
	cout << count;
	return 0;
}
