#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int duplicate(vector<int>& numbers){
    if(numbers.size()==0) return -1;
    sort(numbers.begin(),numbers.end());
    int n=numbers.size();
    if(numbers[0]<0||numbers[numbers.size()-1]>=n) return -1;
    for(int i=1;i<n;++i){
        if(numbers[i]==numbers[i-1]){
            return numbers[i];
        }
    }
    return -1;
}

int duplicate1(vector<int>& numbers){
    int n=numbers.size();
    vector<int> dp(n,-1);
    for(int i=0;i<numbers.size();++i){
        if(numbers[i]<0||numbers[i]>=n) return -1;
        if(dp[numbers[i]]==-1) dp[numbers[i]]=numbers[i];
        else return numbers[i];
    }
    return -1;
}

int duplicate2(vector<int>& numbers){
    for(int i=0;i<numbers.size();++i){
        //该位置本来就是对的
        if(numbers[i]==i) continue;
        //位置不对，需要换到自己对应的位置
        else{
            //对应位置相等，重复
            if(numbers[numbers[i]]==numbers[i]){
                return numbers[i];
            }else{
                //交换位置
                swap(numbers[numbers[i]],numbers[i]);
                i--;
            }
        }
    }
    //没有重复
    return -1;
}

int main(){
    vector<int> nums={2,3,1,0,2,5,3};
    cout<<duplicate2(nums)<<endl;
    return 0;
}