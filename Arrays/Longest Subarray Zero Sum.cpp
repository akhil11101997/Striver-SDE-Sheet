#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    int sum=0;
    int maxi=0;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==0)
            maxi=i+1;
        if(mp.find(sum)!=mp.end()){
            maxi=max(maxi,(i-mp[sum]));
        }
        else
            mp[sum]=i;
    }
    return maxi;

}
