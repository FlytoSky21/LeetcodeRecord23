#include<iostream>
#include<vector>
using namespace std;

/**
 * 在行列都排好序的矩阵中找数
 * 【 题目】 给定一个有N*M的整型矩阵matrix和一个整数K，matrix的每一行和每一列都是排好序
 * 的。 实现一个函数， 判断K是否在matrix中。 例如： 0 1 2 5, 2 3 4 7 ,4 4 4 8, 5 7 7 9
 *  如果K为7， 返回true； 如果K为6， 返回false。
 * 【 要求】 时间复杂度为O(N+M)， 额外空间复杂度为O(1)。
*/

bool isContains(vector<vector<int>>& matrix,int k){
    int m=matrix.size();
    int n=matrix[0].size();
    int cur_r=0,cur_c=n-1;
    while(cur_r<m&&cur_c>=0){
        if(matrix[cur_r][cur_c]==k) return true;
        else if(matrix[cur_r][cur_c]>k){
            cur_c--;
        }else{
            cur_r++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix={{0,1,2,5},{2,3,4,7},{4,4,4,8},{5,7,7,9}};
    int k=6;
    cout<<isContains(matrix,k)<<endl;
    return 0;
}