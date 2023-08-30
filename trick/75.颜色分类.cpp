/**
 * 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，
 * 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
*/

#include<vector>
#include<iostream>
using namespace std;

//使用桶排序，时间复杂度O(1)，空间复杂度O(N)
void sortColors(vector<int>& nums){
    int dp[3]={0};
    for(int num:nums){
        dp[num]++;
    }
    int i=0;
    for(int j=0;j<3;++j){
        while(dp[j]--){
            nums[i++]=j;
        }
    }
}

//使用双指针,类似于快排的Partition，把小于1的放在左边，大于1的放在右边，等于1的放中间
void partition(vector<int>& nums){
    int less=-1,more=nums.size();
    int cur=0;
    while(cur<more){
        if(nums[cur]<1){
            swap(nums[cur++],nums[++less]);
        }else if(nums[cur]>1){
            swap(nums[--more],nums[cur]);
        }else{
            cur++;
        }
    }
}

int main(){
    vector<int> nums={2,0,2,1,1,0};
    // sortColors(nums);
    partition(nums);
    for(auto num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}