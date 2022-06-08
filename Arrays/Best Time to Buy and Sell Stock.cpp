#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini=prices[0];
    int res=0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]>mini){
            if(prices[i]-mini>res)
                res=prices[i]-mini;
        }
        else{
            mini=prices[i];
        }
    }
    return res;
    // Write your code here.
}
