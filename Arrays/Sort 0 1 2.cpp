#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            arr[mid]=arr[low];
            arr[low]=0;
            mid++;
            low++;
        }
        else if(arr[mid]==2){
            arr[mid]=arr[high];
            arr[high]=2;
            high--;
        }
        else{
            mid++;
        }
    }
    return;
}
