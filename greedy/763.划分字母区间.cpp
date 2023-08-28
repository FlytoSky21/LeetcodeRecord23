/*给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
返回一个表示每个字符串片段的长度的列表

示例 1：

输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 */


#include<string>
#include<iostream>
#include<vector>
using namespace std;

vector<int> partitionLabels(string s){
    int left=0;
    int max_range=0;
    vector<int> result;
    //记录每个字母最后出现的位置
    int mp[27]={0};
    for(int i=0;i<s.size();++i){
        mp[s[i]-'a']=i;
    }

    for(int i=0;i<s.size();++i){
        max_range=max(mp[s[i]-'a'],max_range);     //当前范围内字符出现的最远边界
        if(i==max_range){
            result.push_back(i-left+1);
            left=i+1;
        }
    }
    return result;
}

int main(){
    string s;
    cin>>s;
    vector<int> result=partitionLabels(s);
    for(auto num:result){
        cout<<num<<"  ";
    }
    cout<<endl;
    return 0;
}