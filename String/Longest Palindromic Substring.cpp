class Solution {
public:
    void getPalin(int l, int r, int &st, int &maxi, string s){
        int n=s.size();
        while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            if(r-l-1>maxi)
            {
                maxi=r-l-1;
                st=l+1;
            }
    }
    string longestPalindrome(string s) {
        if(s.size()==1)
            return s;
        int n=s.size();
        int st=0;
        int maxi=1;
        for(int i=0;i<n-1;i++){
            //odd length
            getPalin(i,i,st,maxi,s);
            //even length
            getPalin(i,i+1,st,maxi,s);
        }
        return s.substr(st,maxi);
    }
};
