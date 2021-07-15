/*
Zero Sum Sub-Array

You are given with an array (of size N) consisting of positive and negative integers that contain numbers in random order.
Write a program to return true if there exists a sub-array whose sum is zero else, return false.

Input Format :
Line 1 : An Integer N i.e. size of array 
Line 2 : N integers, elements of the array (separated by space)

Output Format :
true or false

Constraints :
1 <= N <= 10^5

Sample Input 1 :
6 
7 1 3 -4 5 1

Sample Output 1 :
true

Sample Input 2 :
5 
-6 7 6 2 1

Sample Output 2 :
false
*/

#include<bits/stdc++.h>
#include<tr1/unordered_map>

using namespace std;

bool subArrayZeroSum(int input[], int n) {
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Taking input and printing output is handled automatically. Return only true or false.
    */
    
    std::tr1::unordered_map<int , bool> allElements;
    bool flag = false;
    
    int sum = 0;
    for(int i = 0; i < n;++i){
    	sum += input[i];
    	
    	// Basically after each sum, check wether that sum has occured before or not, if yes them it means that the sum was consecutively zero for some subarray.
    	// Each entry of map holds the sum and that yes it occured.
    	
    	if(sum == 0 || allElements.count(sum) ){
    		flag = true;
		}
		
		allElements[sum] = true;
	}
	
	return flag;
}

int main(){
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    bool val = subArrayZeroSum(input, n);
    if(val)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}
