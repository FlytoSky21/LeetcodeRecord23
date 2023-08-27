/*给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长连续子数组长度。如果不存在任意一个符合要求的子数组，则返回 0。*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//暴力法，两次遍历，求和为k
int maxSubArrayLen0(vector<int>& nums,int k){
    int max_len=0;
    for(int i=0;i<nums.size();++i){
        int sum=0;
        for(int j=i;j<nums.size();++j){
            sum+=nums[i];
            if(sum==k){
                max_len=max(max_len,j-i+1);
            }
        }
    }
    return max_len;
}

//前缀和
int maxSubArrayLen1(vector<int>& nums,int k){
    int max_len=0;
    vector<int> pre_sum;
    pre_sum.push_back(0);
    for(int i=1;i<=nums.size();++i){
        pre_sum[i]=pre_sum[i-1]+nums[i-1];
    }
    for(int i=0;i<=nums.size();++i){
        for(int j=i;j<=nums.size();++j){
            if(pre_sum[j]-pre_sum[i]==k){
                max_len=max(max_len,j-i);
            }
        }
    }
    return max_len;
}


//前缀和+哈希表
/*
通过字典存储pre_sum和对应的位置i，然后计算当前累加和k的差值pre_sum[i]-k，判断是不是在字典中，如果在字典中的话，
计算长度。需要注意，在记录位置i的过程中，只记录第一次出现的位置，因为我们需要求的是最大长度。
*/
int maxSubArrayLen(vector<int>& nums,int k){
    unordered_map<long,long> mp;  //无序哈希表，存储累计和和它们第一次出现的位置，后续快速查找累积和是否已经出现过
    long sum=0;   //当前位置之前的累积和
    mp[0]=0;
    long r=0;   //存储最长子数组的长度
    for(int i=0;i<nums.size();++i){
        sum+=nums[i];
        //如果当前累积和sum在哈希映射中不存在，将其加入映射中并与当前位置关联。
        if(!mp.count(sum)){   
            mp[sum]=i+1;
        }
        //如果存在之前的累积和等于sum-k，那么说明从之前的累积和到当前的位置的子数组和为k，更新r为当前最长子数组的长度
        if(mp.count(sum-k)){
            r=max(r,i-mp[sum-k]+1);
        }
    }
    return r;

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
    vector<int> nums={1,-1,5,-2,3};
    int k=3;
    cout<<maxSubArrayLen1(nums,k)<<endl;

    return 0;
}