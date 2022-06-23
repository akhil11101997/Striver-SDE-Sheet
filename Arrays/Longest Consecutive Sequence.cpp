class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for(int num:nums){
            hashSet.insert(num);
        }
        int res=0;
        for(int num:nums){
            if(!hashSet.count(num-1)){
                int count=1;
                int element=num;
                while(hashSet.count(element+1)){
                    element++;
                    count++;
                }
                res=max(res,count);
            }
        }
        return res;
    }
};
