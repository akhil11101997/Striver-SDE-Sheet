class Solution {
    private:
    vector<vector<int>> dp{100, vector<int> (100,-1)};
    int numsUniquePaths(int n, int m, int i, int j){
        if(i==n-1 || j==m-1)
            return 1;
        else {
            if(dp[i][j]!=-1)
                return dp[i][j];
            dp[i+1][j]=numsUniquePaths(n,m,i+1,j);
            dp[i][j+1]=numsUniquePaths(n,m,i,j+1);
            return dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
            
    }
public:
    int uniquePaths(int m, int n) {
        return numsUniquePaths(m,n,0,0);
    }
};
