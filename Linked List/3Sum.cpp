class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int i=0,n=nums.size();
        while(i<n){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j<n && nums[j]==nums[j-1])
                        j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            i++;
            while(i<n&&nums[i]==nums[i-1])
                i++;
        }
        return res;
    }
};
