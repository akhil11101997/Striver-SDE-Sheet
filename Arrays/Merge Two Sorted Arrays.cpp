#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    int index=m+n-1;
    int i=m-1,j=n-1;
    while(i>=0 && j>=0){
        if(arr1[i]>arr2[j]){
            arr1[index]=arr1[i];
            index--;
            i--;
        }
        else{
            arr1[index]=arr2[j];
            index--;
            j--;
        }
    }
    while(i>=0){
        arr1[index]=arr1[i];
            index--;
            i--;
    }
    while(j>=0){
        arr1[index]=arr2[j];
            index--;
            j--;
    }
    return arr1;
}
