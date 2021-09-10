/*
Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // First step: Sort the given intervals matrix.
        sort(intervals.begin() , intervals.end());
        
        // Lets create a stack of type vector to store the intervals into.
        stack<vector<int> > mergedIntervals;
        for(int i = 0; i < intervals.size(); i++){
            if(mergedIntervals.empty()){
            	
            	// If the stack is empty then we simply insert the interval.
                mergedIntervals.push(intervals[i]);
            }else{
            	
            	// If an interval is present we have 2 options present.
            	
            	// 1. If true: then we pop the top and update its value and insert the updated interval.
                if(intervals[i][0] <= mergedIntervals.top().at(1)){
                    vector<int> temp = mergedIntervals.top();
                    mergedIntervals.pop();
                    temp[1] = max(temp[1] , intervals[i][1]);
                    mergedIntervals.push(temp);
                }
				// If false: we simply insert the interval as it cannot be merged.
				else{
                    mergedIntervals.push(intervals[i]);
                }
            }
        }
        
        vector<vector<int> > finalAns;
        while(!mergedIntervals.empty()){
            finalAns.push_back(mergedIntervals.top());
            mergedIntervals.pop();
        }
        
        reverse(finalAns.begin(), finalAns.end());
        
        return finalAns;
    }
};
