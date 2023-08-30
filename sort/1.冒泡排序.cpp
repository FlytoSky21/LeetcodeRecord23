#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*冒泡排序：先看01位置的数，如果0位置数字大于1位置的数，交换。。一轮下来，
最大的数来到了最后的位置，第二轮对比0-n-1位置的数*/
//时间复杂度：O(N^2)
void bubbleSort(vector<int>& nums){
    if(nums.size()<2) return;
    for(int end=nums.size()-1;end>0;--end){
        for(int i=0;i<end;++i){
            if(nums[i]>nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
        }
    }
}
int main(){
    vector<int> nums={1,5,6,3,4,9,5,3};
    bubbleSort(nums);
    for(auto num:nums){
        cout<<num<<"  ";
    }
    return 0;
}