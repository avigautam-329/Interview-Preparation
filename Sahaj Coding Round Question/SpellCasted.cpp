#include<bits/stdc++.h>
#include<string>
#include<tr1/unordered_map>
using namespace std;

/*
T.C = O(N)
S.C = O(1)
*/
int checkResult(string spellBook[],string spellCasted, int size){
	
	/*std::tr1::unordered_map<string , int> lengthSpell;
	
	for(int i = 0; i < size;++i){
		lengthSpell[spellBook[i]] = spellBook[i].length();
	}*/
	
	int spellCasted_len = spellCasted.length();
	int lenCovered = 0;
	
	for(int j = 0; j < size; ++j){
		if(spellCasted.find(spellBook[j]) != string::npos){
			lenCovered += spellBook[j].length();
		}
	}
	
	return spellCasted_len - lenCovered;
}

int main(){
	int n;
	cin >> n;
	
	string *spellBook = new string[n];
	for(int i = 0; i < n; ++i){
		cin >> spellBook[i];
	}
	
	string spellCasted;
	cin >> spellCasted;
	
	int ans = checkResult(spellBook,spellCasted,n);
	if(ans == 0){
		cout << "Harry" << endl;
	}else{
		cout << "Voldermort" << endl;
	}
	return 0;
}
