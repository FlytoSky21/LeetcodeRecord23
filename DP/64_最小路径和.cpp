#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid){
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));   //dp[i][j]：走到[i,j]时候路径上的数字最小总和
    dp[0][0]=grid[0][0];
    for(int j=1;j<n;++j){
        dp[0][j]=dp[0][j-1]+grid[0][j];
    }
    for(int i=1;i<m;++i){
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int m,n;   //矩阵行数和列数
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>matrix[i][j];
        }
    }
    //验证是否读入成功
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<minPathSum(matrix)<<endl;
    return 0;
}