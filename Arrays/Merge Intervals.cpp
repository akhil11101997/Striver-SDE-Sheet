#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int i=0;
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end());
    while(i<intervals.size()){
        vector<int> temp=intervals[i];
        i++;
        while(i<intervals.size()){
            if(intervals[i][0]<=temp[1]){
                temp[1]=max(intervals[i][1],temp[1]);
                i++;
            }
            else{
                break;
            }
        }
        res.push_back(temp);
    }
    return res;
}
