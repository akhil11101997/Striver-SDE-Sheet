class Solution {
    private:
    int merge(vector<int>&nums,int left, int middle, int right){
        int inv_c=0;
        int j=middle;
        for(int i=left;i<middle;i++){
            while(j<=right && 1LL*nums[i]>2LL*nums[j])
                j++;
            inv_c+=(j-middle);
        }
        vector<int> temp;
        int i=left;
        j=middle;
        while(i<middle && j<=right){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<middle){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=right){
           temp.push_back(nums[j]);
            j++; 
        }
        for(i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }
        return inv_c;
        
    }
    int mergeSort(vector<int> &nums, int left, int right){
        int inv_c=0;
        if(left<right){
            int mid=left+(right-left)/2;
            inv_c+=mergeSort(nums,left,mid);
            inv_c+=mergeSort(nums,mid+1,right);
            inv_c+=merge(nums,left,mid+1,right);
        }
        return inv_c;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
