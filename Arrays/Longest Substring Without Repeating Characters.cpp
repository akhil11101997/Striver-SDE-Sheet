class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        set<char> st;
        st.insert(s[0]);
        int tail=0;
        int res=1;
        for(int i=1;i<s.size();i++){
            if(st.count(s[i])){
                while(tail<s.size() && s[tail]!=s[i]){
                    st.erase(s[tail]);
                    tail++;
                }
                tail++;
            }
            else{
                st.insert(s[i]);
            }
            res=max(res,i-tail+1);
        }
        return res;
    }
};
