#include<iostream>
#include<vector>
using namespace std;

//插入排序像扑克牌整牌
//复杂度：O(N^2)
void insertionSort(vector<int>& nums){
    if(nums.size()<2) return;
    //假设0位置有序，然后从1位置看，往哪儿插入后停止（停止后0-1有序）.然后看2位置，
    //往哪里插入然后停止(停止后0-2有序)....
    for(int i=1;i<nums.size();++i){
        for(int j=i-1;j>=0&&nums[j]>nums[j+1];--j){
            swap(nums[j],nums[j+1]);
        }
    }
}

int main(){
    vector<int> nums={1,5,6,3,4,9,5,3};
    insertionSort(nums);
    for(auto num:nums){
        cout<<num<<"  ";
    }
    return 0;
}