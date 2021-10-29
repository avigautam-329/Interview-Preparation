#include<iostream>
#include<cstring>
using namespace std;

string getString(string num){
	int z = 0;
	string ans = "";
	for(int i = 0; i < num.size(); i++){
		if(num[i] == '0'){
			z++;
		}else{
			ans += num[i];
		}
	}
	
	for(int i = 0; i < z; i++){
		ans += 'a';
	}
	
	return ans;
}

int main(){
	string num;
	cin >> num;
	
	string res = getString(num);
	
	cout << res << endl;
	return 0;
}

