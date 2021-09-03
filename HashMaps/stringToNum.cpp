#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

long long convertToNumber(string number){
	unordered_map<string, long long> stringToNum(
	{
		{"zero",0},
		{"one",1},
		{"two",2},
		{"three",3},
		{"four",4},
		{"five",5},
		{"six",6},
		{"seven",7},
		{"eight",8},
		{"nine",9},
		{"ten",10},
		{"eleven",11},
		{"twelve",12},
		{"thirteen",13},
		{"fourteen",14},
		{"fifteen",15},
		{"sixteen",16},
		{"eighteen",18},
		{"nineteen",19},
		{"twenty",20},
		{"thirty",30},
		{"fourty",40},
		{"fifty",50},
		{"sixty",60},
		{"seventy",70},
		{"eight",80},
		{"ninety",90}	
	});
	unordered_map<string, long long> multiplier({
		{"hundred",100},
		{"thousand", 1000},
		{"million",1000000}
	});	
	string curr="";
	bool is_negative = false;
	long long totalNumber = 0;
	long long currNumber =  1;
	for(int i = 0; i< number.size(); i++){
		if(number[i] != ' '){
			curr += number[i];
		}else{
			if(stringToNum.find(curr) != stringToNum.end()){
				currNumber = 1;
				currNumber = currNumber * stringToNum[curr];
				totalNumber += currNumber;
			}else if(curr == "negative"){
				is_negative = true;
			}else{
				totalNumber *= multiplier[curr];
			}
			curr = "";
		}
	}
	
	if(stringToNum.find(curr) != stringToNum.end()){
		currNumber = 1;
		currNumber = currNumber * stringToNum[curr];
		totalNumber += currNumber;
	}else if(curr == "negative"){
		is_negative = true;
	}else{
		totalNumber *= multiplier[curr];
	}
	if(is_negative){
		totalNumber *= -1;
	}
	return totalNumber;
}

int main(){
	string number;
	getline(cin, number);
	
	long long finalAns = convertToNumber(number);
	
	cout << finalAns;
}
