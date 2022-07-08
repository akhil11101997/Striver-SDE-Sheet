#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2){
    if(p1.first==p2.first){
        return p1.second.second<p2.second.second;
    }
    return p1.first<p2.first;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int,int>>> meetings;
    for(int i=0;i<start.size();i++){
        meetings.push_back({end[i],{start[i],i+1}});
    }
    sort(meetings.begin(),meetings.end(),compare);
    vector<int> res={meetings[0].second.second};
    int x=meetings[0].second.first;
    int y=meetings[0].first;
    for(int i=1;i<meetings.size();i++){
        if(meetings[i].second.first>y){
            x=meetings[i].second.first;
            y=meetings[i].first;
            res.push_back(meetings[i].second.second);
        }
    }
    return res;
}
