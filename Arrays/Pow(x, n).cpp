class Solution {
public:
    double myPow(double x, int n) {
        long long nn;
        if(n<0){
            nn=-1LL*n;
        }
        else{
            nn=n;
        }
        double ans=1.0;
        while(nn){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans=ans*x;
                nn=nn-1;
            }
        }
        if(n<0){
            ans=1/ans;
        }
        return ans;
    }
};
