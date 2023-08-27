#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//暴力解法
int subarraySum(vector<int>& nums,int k){
    int ans=0;
    for(int i=0;i<nums.size();++i){
        int sum=0;
        for(int j=i;j<nums.size();++j){
            sum+=nums[j];
            if(sum==k) ans++;
        }
    }
    return ans;
}

//前缀和+哈希表
int subarraySum1(vector<int>& nums,int k){
    int result=0,sum=0;
    unordered_map<int,int> mp;  //记录前缀和的个数
    //初始化{0，1}可以看作是在前缀和前多加了一个和，是为了防止从序号0开始加到i时刚好为k的情况出现时，没法找到对应数值计数
    mp[0]=1;
    for(int i=1;i<=nums.size();++i){
        sum+=nums[i-1];
        if(mp.find(sum-k)!=mp.end()){
            result+=mp[sum-k];
        }
        mp[sum]++;
    }
    return result;
}


int main(){
    // vector<int> nums;
    // int num;
    // while(cin>>num){
    //     nums.push_back(num);
    //     if(getchar()=='\n') break;
    // }
    // int k;
    // cin>>k;
    vector<int>nums={1,2,3};
    int k=3;
    int result=subarraySum(nums,k);
    cout<<result<<endl;
    return 0;
}