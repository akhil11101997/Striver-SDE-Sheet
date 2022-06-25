bool is(long long minPages,vector<int> &A, int B){
    int students=1;
    long long sum=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum>minPages){
            students++;
            sum=A[i];
        }
        if(students>B)
            return 0;
    }
    return 1;   
}
int Solution::books(vector<int> &A, int B) {
    if(A.size()<B)
        return -1;
    long long high=0;
    long long low=INT_MIN;
    int n=A.size();
    for(int i=0;i<n;i++){
        high+=A[i];
        if(A[i]>low)
            low=A[i];
    }
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(is(mid,A,B)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
    
}

