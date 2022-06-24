int countNumberLesserThanEqual(int median,vector<int> A){
    int low=0,high=A.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]<=median){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int start=1,end=1e9;
    int n=A.size(),m=A[0].size();
    while(start<=end){
        int mid=start+(end-start)/2;
        int count=0;
        for(int i=0;i<n;i++){
            count+=countNumberLesserThanEqual(mid,A[i]);
        }
        if(count<=(n*m/2)){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return start;
}
