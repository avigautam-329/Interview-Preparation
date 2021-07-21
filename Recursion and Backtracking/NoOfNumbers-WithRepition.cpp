/*
Given a number n, find number of numbers that are greater than n using the same set of digits as n. n might have duplicate digits.

Input Format :
Integer n

Output Format :
Count of greater numbers

Sample Input :
122

Sample Output :
2
*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

long count(long n){
    long sum = 0;
    while(n != 0){
        sum++;
        n = n / 10;
    }
    return sum;
}

long denominatorSum(long *factorial, long *freq){
    long ans = 1;
    for(int i = 0; i < 10 ; ++i){
        ans *= factorial[freq[i]];
    }
    return ans;
}

long helperFunction(long num, long length, long *factorial, long *freq){
    // Base Case.
    if(length == 0 || length == 1)
        return 0;
    
    int current = num / (pow(10,length - 1));
    long denominator = denominatorSum(factorial, freq);
    
    long totalCount = 0;
    
    for(int i = current + 1; i < 10; ++i){
    	if(freq[i] > 0){
        	totalCount += (factorial[length - 1] * freq[i])/denominator;    
        }
    }
    
    freq[current]--;
    totalCount += helperFunction(num % (long)(pow(10,length - 1)), length - 1, factorial, freq);
    return totalCount;
}

long numberOfNumbersWithDuplicates(long num){
	// Write your code here
	long length = count(num);
    
    long *factorial = new long[length + 1];
    factorial[0] = 1;
    
    long freq[10] = {0};
    
    // Now populationg the frequency array.
    long temp = num;
    int i = 0;
    while(temp != 0){
        int remainder = temp % 10;
        
        freq[remainder]++;
        factorial[i + 1] = (i + 1) * factorial[i];
        
        ++i;
    	temp = temp / 10;
    }
    return helperFunction(num, length, factorial, freq);
}

int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
}
