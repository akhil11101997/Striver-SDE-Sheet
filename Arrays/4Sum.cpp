class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left=j+1,right=n-1;
                vector<int> temp(4,0);
                long long localTarget=1LL*target-nums[i]-nums[j];
                while(left<right){
                    if(nums[left]+nums[right]==localTarget){
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[left];
                        temp[3]=nums[right];
                        res.push_back(temp);
                        while(left<right && nums[left]==temp[2])
                            left++;
                        while(left<right && nums[right]==temp[3])
                            right--;
                    }
                    else if(nums[left]+nums[right]>localTarget){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1])
                    j++;
            }
            while(i+1<n && nums[i]==nums[i+1])
                i++;
        }
        return res;
    }
};
