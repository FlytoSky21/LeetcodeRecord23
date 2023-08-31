/**
 * 给定一个矩阵matrix， 按照“之” 字形的方式打印这个矩阵， 例如： 1 2 3 4, 5 6 7 8, 9 10 11 12
 * “之” 字形打印的结果为： 1， 2， 5， 9， 6， 3， 4， 7， 10， 11，8， 12
 * 【 要求】 额外空间复杂度为O(1)
*/

#include<iostream>
#include<vector>
using namespace std;


void printLevel(vector<vector<int>>& matrix,int a_r,int a_c,int b_r,int b_c,bool from_up){
    if(from_up){
        while(a_r!=b_r+1){
            cout<<matrix[a_r++][a_c--]<<"  ";
        }
    }else{
        while(b_r!=a_r-1){
            cout<<matrix[b_r--][b_c++]<<"  ";
        }
    }
}
void printMatrixZigZag(vector<vector<int>>& matrix){
    int a_r=0,a_c=0,b_r=0,b_c=0;
    int end_r=matrix.size()-1;
    int end_c=matrix[0].size()-1;
    bool fromUp=false;
    while(a_r!=end_r+1){
        printLevel(matrix,a_r,a_c,b_r,b_c,fromUp);
        a_r=a_c==end_c?a_r+1:a_r;
        a_c=a_c==end_c?a_c:a_c+1;
        b_c=b_r==end_r?b_c+1:b_c;
        b_r=b_r==end_r?b_r:b_r+1;
        fromUp=!fromUp;
    }
    cout<<endl;
}


int main(){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printMatrixZigZag(matrix);
    return 0;
}