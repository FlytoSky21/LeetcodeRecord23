/**
 * 给定一个整型矩阵matrix， 请按照转圈的方式打印它
*/

#include<vector>
#include<iostream>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
    vector<int> ans;
    while(true){
        for(int j=left;j<=right;++j){
            ans.emplace_back(matrix[top][j]);
        }
        if(++top>bottom) break;
        cout<<top<<endl;
        for(int i=top;i<=bottom;++i){
            ans.emplace_back(matrix[i][right]);
        }
        if(--right<left) break;
        cout<<right<<endl;
        for(int j=right;j>=left;--j){
            ans.emplace_back(matrix[bottom][j]);
        }
        if(--bottom<top) break;
        cout<<bottom<<endl;
        for(int i=bottom;i>=top;--i){
            ans.emplace_back(matrix[i][left]);
        }
        if(++left>right) break;
        cout<<left<<endl;
    }
    return ans;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix={{1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {13,14,15,16}};
    vector<int> ans=printMatrix(matrix);
    for(int num:ans) cout<<num<<"  ";
    cout<<endl;
    return 0;
}