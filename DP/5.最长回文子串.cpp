# include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<bool>> isPal(string& s){
    vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
    for(int i=0;i<s.size();++i){
        dp[i][i]=true;
    }
    for(int i=s.size()-1;i>=0;--i){
        for(int j=i;j<s.size();++j){
            if(s[i]==s[j]){
                if(j-i<2) dp[i][j]=true;
                else{
                    dp[i][j]=dp[i+1][j-1];
                }
            }else{
                dp[i][j]=false;
            }
        }
    }
    return dp;
}

string longestPalindrome(string& s){
    if(s.size()<=1) return s;
    vector<vector<bool>> dp=isPal(s);
    int longest_len=0;
    string ans="";
    for(int i=0;i<s.size();++i){
        for(int j=i;j<s.size();++j){
            if(dp[i][j]&&longest_len<(j-i+1)){
                longest_len=j-i+1;
                ans=s.substr(i,j-i+1);
            }
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}