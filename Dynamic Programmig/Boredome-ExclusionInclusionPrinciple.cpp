/*
Boredom

Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Note: The element to be picked is also removed from the list.

Input Format :
Line 1 : Integer N 
Line 2 : A list of N integers

Output Format :
Maximum points Gary can recieve from the Game setup

Constraints :
1<=N<=10^5
1<=A[i]<=1000

Sample Input :
2
1 2
Sample Output :
2
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> A){
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	vector<int> freq(1001,0);
    
    // Calculating the frequencies.
    for(int i = 0;i < A.size(); ++i){
        freq[A[i]]++;
    }
    
    // Now creating the dp array to store the states of maximum points.
    vector<int> dp(1001,0);
    
    dp[1] = freq[1] * 1;
    dp[2] = freq[2] * 2;
    
    for(int i = 3; i < 1001; ++i){
        dp[i] = max(dp[i-2] + (freq[i] * i),dp[i-1]);
    }
    
    return dp[1000];
    
}

int main(){
	int n;
	vector<int>A;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
	return 0;
}
