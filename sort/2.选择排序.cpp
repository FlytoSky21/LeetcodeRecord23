#include<iostream>
#include<vector>
using namespace std;

//选择排序：0-N-1的位置找一个最小的放在0位置上，1-N-1的位置找一个最小的放在1位置上...
void selectionSort(vector<int>& nums){
    if(nums.size()<2) return;
    for(int i=0;i<nums.size()-1;++i){
        int min_idx=i;
        for(int j=i+1;j<nums.size();++j){
            if(nums[j]<nums[min_idx]){
                min_idx=j;
            }
        }
        swap(nums[i],nums[min_idx]);
    }
}

int main(){
    vector<int> nums={1,5,6,3,4,9,5,3};
    selectionSort(nums);
    for(auto num:nums){
        cout<<num<<"  ";
    }
    return 0;
}