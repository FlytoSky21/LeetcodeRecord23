#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.begin()+k);
    for(int i=k;i<nums.size();++i){
        if(nums[i]>pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main(){
    vector<int> nums={3,2,1,5,6,4};
    int ans=findKthLargest(nums,2);
    cout<<ans<<endl;
    return 0;
}