#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestCommonSubsequence(string text1,string text2){
    if(text1.size()==0||text2.size()==0) return 0;
    vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));  //dp[i][j]:text1和text2的前I和前j个字母相同的最大长度
    for(int i=1;i<=text1.size();++i){
        for(int j=1;j<=text2.size();++j){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}

int main(){
    // string s1,s2;
    // cin>>s1>>s2;
    string s1="abcde",s2="ace";
    cout<<longestCommonSubsequence(s1,s2)<<endl;
    return 0;
}