class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0),right(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                if(height[i]>st.top()){
                    left[i]=height[i];
                    st.push(height[i]);
                }
                else{
                    left[i]=st.top();
                }
            }
            else{
                left[i]=height[i];
                st.push(height[i]);
            }
        }
        stack<int> st1;
        for(int i=n-1;i>=0;i--){
            if(!st1.empty()){
                if(height[i]>st1.top()){
                    right[i]=height[i];
                    st1.push(height[i]);
                }
                else{
                    right[i]=st1.top();
                }
            }
            else{
                right[i]=height[i];
                st1.push(height[i]);
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=min(left[i],right[i])-height[i];
        }
        return res;
        
    }
};
