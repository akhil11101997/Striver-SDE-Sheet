#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    set<int> rows,columns;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                rows.insert(i);
                columns.insert(j);
            }
        }
    }
    for(auto i=rows.begin();i!=rows.end();i++){
        for(int j=0;j<matrix[0].size();j++){
            matrix[*i][j]=0;
        }
    }
    for(auto i=columns.begin();i!=columns.end();i++){
        for(int j=0;j<matrix.size();j++){
            matrix[j][*i]=0;
        }
    }
    return;
}
