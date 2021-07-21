#include<bits/stdc++.h>
using namespace std;

// For now this is a code which can also work in the case of repitied digits.
// In this case we are taking the number in form of an array.

int totalNumCount(int *input, int size, int *factorial, int *frequency){
	// Base Case.
	// If the number length is 0 or 1 , then there is no other permutation possible.
	if(size == 0 || size == 1)
		return 0;
		
	int totalCount = 0;
		
	// Now we will look for numbers greater than input[0] in the frequency array.
	for(int i = input[0] + 1; i < 10; ++i){
		if(frequency[i] > 0){
			totalCount += factorial[size - 1];
		}
	}
	
	// Moving onto the recursive part.
	// As we are considering that the input[0] position is fixed, we should decrement its frequency as well.
	frequency[input[0]]--;
	totalCount += totalNumCount(input + 1, size - 1, factorial, frequency);
	return totalCount;
}

int main(){
	
	// Storing the number of digits.
	int n;
	cin >> n;
	
	int *input = new int[n];
	
	// Keeping 2 arrays. One for the pre-computation of factorial and Second a Frequency array.
	int *factorial = new int[n+1];
	int freq[10] = {0};

	
	factorial[0] = 1;
	
	for(int i = 0; i < n; ++i){
		cin >> input[i];
		
		// Stroing the frequency of the digits.
		freq[input[i]]++;
		
		// Smart way of computing factorial, to get the factorial of the next number, multiply it with the factorial of current number.
		factorial[i + 1] = (i + 1) * factorial[i];
	}
	
	// Now we will call the function we will make.
	cout << "The total Count is : ";
	cout << totalNumCount(input, n, factorial, freq) << endl;
	return 0;
}
