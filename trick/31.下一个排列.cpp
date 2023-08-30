/**
 * 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据
 * 其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的
 * 那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按
 * 升序排列）。 
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//复杂度为O(N^2)
void nextPermutation(vector<int>& nums){
    //从右边开始寻找第一个比它大的数字，并进行交换，交换后，该位右边的数字倒序。
    for(int i=nums.size()-1;i>=0;--i){
        for(int j=nums.size()-1;j>i;--j){
            if(nums[j]>nums[i]){
                swap(nums[i],nums[j]);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
        }
    }
    //到这里说明整个数组都是倒序的，如4 3 2 1，反转一个即可。
    reverse(nums.begin(),nums.end());
}
void nextPermutation1(vector<int>& nums){
    int i=nums.size()-2;
    while(i>=0&&nums[i]>=nums[i+1]){
        i--;
    }
    if(i>=0){
        int j=nums.size()-1;
        while(j>i&&nums[j]<=nums[i]){
            --j;
        }
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1,nums.end());
}

int main(){
    vector<int> nums={1,2,3};
    nextPermutation1(nums);
    for(auto num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}