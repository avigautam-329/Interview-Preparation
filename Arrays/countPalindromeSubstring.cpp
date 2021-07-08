/*
Palindrome substrings

Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.

Input Format :
String S

Output Format :
count of palindrome substrings

Constraints :
1 <= Length of S <= 1000

Sample Input :
aba

Sample Output :
4

**Note : Here 4 corresponds to ("a","b","a","aba").
*/

#include<bits/stdc++.h>
using namespace std;

/*
	The algorithm is that: 
    	- We need to first pick every element as mid. 
    	- move left and right of the mid and check if they are the same or not. if they are then it is a palindromic substring.	
		- But this will only give palindromic substring of odd length.
        - For even length, we will have to keep 2 elements as the mid.(mid_left, mid_right)
        - Then check wether the 2 mid elements are palindrome or not. 
        - If palindrome then check on its left and right to check for other substrings with that mid.
*/

int length(char input[]){
    int count = 0;
    for(int i = 0 ; input[i] != '\0' ; ++i){
        count++;   
    }
    return count;
}

int countPalindromeSubstrings(char arr[]) {
	// Write your code here
	// Since the question doesnt ask for unique palindromic substring, we can first count the total elements.
    int totalCount = length(arr);
    int len = length(arr);
    
    //To print the palindromic substring of odd length.
    int mid = 0;
    while(mid < len){
        int left= mid - 1, right = mid + 1;
        while(left >= 0 && right < len){
            if(arr[left] == arr[right]){
                totalCount++;
                left--;
                right++;
            }else{
                break;
            }
        }
        mid++;
    }
    //To print the palindromic substring of even length.
    int mid_left = 0, mid_right = 1;
    //int left = mid_left - 1, right = mid_right + 1;
    while(mid_right < len){
        
        if(arr[mid_left] == arr[mid_right]){
        	totalCount++;
            int left = mid_left - 1, right = mid_right + 1;
            while(left >= 0 && right < len){
            	if(arr[left] == arr[right]){
                	totalCount++;
                	left--;
                	right++;
            	}else{
                	break;
            	}
        	}
        }
        mid_left++;
        mid_right++;
    }
    
    return totalCount ;
}

int main(){
	char input[1000];
	cin.getline(input,1000);
	cout << countPalindromeSubstrings(input) << endl;
	return 0;
}
