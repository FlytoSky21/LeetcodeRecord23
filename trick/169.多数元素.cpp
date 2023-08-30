#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majorityElement(vector<int>&nums){
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}

int main(){
    vector<int> nums={1,1,1,1,4};
    cout<<majorityElement(nums)<<endl;
    return 0;
}