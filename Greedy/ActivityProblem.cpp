#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    // By default I have to make the comparator function static.
    static bool comparator(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetingSchedule;
        
        for(int i = 0; i < n; i++){
            meetingSchedule.push_back({start[i] , end[i]});
        }
        
        // Now we will sort the meeting according to the ending time, for that we need to override the comparator of sort in-built function.
        sort(meetingSchedule.begin() , meetingSchedule.end(), comparator);
        
        int i = 0, j = i + 1;
        int finalCount = 1;
        while(j < n){
            if(meetingSchedule[i].second < meetingSchedule[j].first){
                finalCount++;
                i = j;
                j++;
            }else{
                j++;
            }
        }
        
        return finalCount;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
