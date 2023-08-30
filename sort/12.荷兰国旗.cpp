#include<iostream>
#include<vector>
using namespace std;
/** 前导
 * 给定一个数组arr，和一个数Num,请把小于等于num的数放在数组的左边，
 * 大于num的数放在数组的右边
 * 要求时间复杂度O(N)，额外空间复杂度为O(1)
*/
void partition(vector<int>& nums,int target){
    int left=0,right=nums.size()-1;
    while(left<right){
        //寻找左边第一个大于num的数
        while(left<right&&nums[left]<=target) left++;
        while(left<right&&nums[right]>target) right--;
        if(left<right){
            swap(nums[left++],nums[right--]);
        }
     }
}

/**
 * 荷兰国旗问题
 * 给定一个数组arr，和一个数Num，请把小于num的数放在数组的左边，等于Num的数放在数组的中间
 * 大于Num的数放在数组的右边.
 * 要求时间复杂度O(N)，额外空间复杂度为O(1)
*/
vector<int> partition1(vector<int>& nums,int left,int right,int target){
    int less=left-1;
    int more=right+1;
    int cur=left;
    while(cur<more){
        if(nums[cur]<target){
            swap(nums[++less],nums[cur++]);
        }else if(nums[cur]>target){
            swap(nums[--more],nums[cur]);
        }else{
            cur++;
        }
    }
    return vector<int>{less+1,more-1};   //返回等于区间的左右边界
}



int main(){
    vector<int> nums={5,6,2,4,6,7,3,5};
    int k=5;
    partition1(nums,0,nums.size()-1,k);
    for(auto num:nums){
        cout<<num<<"  ";
    }
    cout<<endl;
    return 0;
}