#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n;
	int MAX = 1000;
	cin >> n;

	string seq = "";
	int flag = 1;
	
	for(int i = 0; i < MAX; i++){
		seq += to_string(flag);
		flag++;
	}
	
	int num = seq[n - 1] - '0';
	if(num % 2 == 0){
		cout << "EVEN"; 
	}else{
		cout << "ODD";
	}

	return 0;
}
