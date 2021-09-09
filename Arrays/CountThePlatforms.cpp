/*
Count the Platforms

Given two arrays (both of size n), one containing arrival time of trains and other containing the corresponding trains departure time (in the form of an integer) respectively. Return the minimum number of platform required, such that no train waits.
Arrival and departure time of a train can't be same.

Input Format :
Line 1: Integer n, number of elements in arrival and departure array
Line 2: Elements of Arrival Array (separated by spaces).
Line 3: Elements of Departure Array (separated by spaces).

Output Format:
Minimum Number of Platform Needed

Constraints :
1 <= n <= 100

Sample Input 1 :
6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000
Sample Output 1 :
3

Sample Input 2 :
4
1100 1101 1103 1105
1110 1102 1104 1106
Sample Output 2 :
2
*/

#include<bits/stdc++.h>
using namespace std;

int platformsNeeded(int arrival[], int departure[], int n) {
    /*
     * Don't write main().
     * Don't read input, it is passed as function argument.
     * Don't print anything just return integer value.
     */
    int plat_need = 1, result = 1;
    int i = 1, j = 0;
    
    //Sort the two arrays for succeeful application of merge sort.
    sort(arrival, arrival+n);
    sort(departure, departure+n);
    
    while(i < n && j < n){
		if(arrival[i] <= departure[j]){
            plat_need++;
            i++;
        }else if(arrival[i] > departure[j]){
            plat_need--;
            j++;
        }
        
        if(plat_need > result){
            result = plat_need;
        }
    }
    
	return result;
}

int main(){
	int n;
	cin>>n;
    int* arr=new int[n];
    int* dep=new int[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	for(int i=0;i<n;i++)
    {
    	cin>>dep[i];
	}
    cout<< platformsNeeded(arr, dep, n);	
	return 0;
}
