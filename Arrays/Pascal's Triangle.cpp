#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> res;
    vector<long long int> temp={1};
    res.push_back(temp);
    while(n>1){
      vector<long long int> t1;
        t1.push_back(1);
        for(int i=0;i<res[res.size()-1].size()-1;i++){
            t1.push_back(res[res.size()-1][i]+res[res.size()-1][i+1]);
        }
        t1.push_back(1);
        res.push_back(t1);
        n--;
    }
    return res;
}
