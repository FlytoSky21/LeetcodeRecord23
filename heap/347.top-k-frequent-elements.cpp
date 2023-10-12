#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
/**
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按任意顺序返回答案
*/
static bool cmp(pair<int,int>& a,pair<int,int>& b){
    return a.second>b.second;
}
vector<int> topKFrequent(vector<int>& nums,int k){
    //统计频率
    unordered_map<int,int> hashmap;
    for(auto num:nums){
        hashmap[num]++;
    }
    vector<pair<int,int>> vec(hashmap.begin(),hashmap.end());
    sort(vec.begin(),vec.end(),cmp);
    vector<int> ans;
    for(int i=0;i<k;++i){
        ans.push_back(vec[i].first);
    }
    return ans;
}


//最小堆
//当求某个数组的第k大的值时候，使用小跟堆，这样每次替换的时候就可以直接取出当前数组中最小的值，换为较大的值
vector<int> topKFrequent1(vector<int>& nums, int k) {
    //统计频率
    unordered_map<int,int> hashmap;
    for(auto num:nums){
        hashmap[num]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> pq(cmp);
    for(auto um:hashmap){
        pq.push(um);
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int> ans;
    for(int i=0;i<k;++i){
        auto cur=pq.top(); pq.pop();
        ans.push_back(cur.first);
    }
    return ans;
}

int main(){
    vector<int> nums={1,1,1,2,2,3};
    int k=2;
    vector<int> ans=topKFrequent(nums,k);
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}