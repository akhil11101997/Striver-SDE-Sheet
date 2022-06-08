#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int index1=-1;
    int index2=-1;
    for(int i=n-2;i>=0;i--){
        if(permutation[i]<permutation[i+1])
        {
            index1=i;
            break;
        }
    }
    if(index1!=-1){
        for(int i=n-1;i>=0;i--){
        if(permutation[i]>permutation[index1]){
            index2=i;
            break;
        }
        }
        int temp=permutation[index1];
    permutation[index1]=permutation[index2];
    permutation[index2]=temp;
    }
    int i=index1+1,j=n-1;
    while(i<j){
    int temp=permutation[i];
    permutation[i]=permutation[j];
    permutation[j]=temp;
        i++;
        j--;
    }
    return permutation;
}
