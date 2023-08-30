/**
 * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），
 * 可知至少存在一个重复的整数。假设 nums 只有 一个重复的整数 ，返回 这个重复的数
*/

#include<vector>
#include<iostream>
using namespace std;

int findDuplicate(vector<int>& nums){
    vector<int> dp(nums.size()+1,0);
    for(auto num:nums){
        if(dp[num]==0){
            dp[num]++;
        }else{
            return num;
        }
    }
    return 0;
}

//龟兔赛跑（快慢指针）
/**
 * 1. 如果数组中没有重复的数，以数组[1,3,4,2]为例，我们将数组下标n和nums[n]建立一个映射关系
 * f(n)，映射关系n->f(n)：0->1,1->3,2->4,3->2，我们从下标0出发，根据f(n)计算出一个值，以这个
 * 值为新的下标，再用这个函数计算，，以此类推，直到下标越界，这样可以产生一个类似链表一样的序列
 * 0->1->3->2->4->null
 * 2. 如果数组中有重复的数字，以数组【1,3,4,2,2】为例，将数组下标和nums[n]建立一个映射关系，
 * 映射关系n->f(n)：0->1,1->3,2->4,3->2,4->2，同样的，从下标0出发，根据f(n)计算一个值，再以
 * 这个值为新的下标，再用这个函数计算，以此类推产生一个类似链表一样的序列。0->1->3->2->4->2->
 * 4...这里2->4就是循环，。
 * 从理论上将，数组中如果有重复的数，那么就会产生多对以的映射，这样形成的链表就一定会有环路。
 * 1.数组有一个重复的数《==》链表中存在环
 * 2.找到数组中的重复数<==>找到链表的环入口。
*/
int findDuplicate1(vector<int>& nums){
    if(nums.size()<2) return 0;
    int slow=0,fast=0;
    slow=nums[slow];
    fast=nums[nums[fast]];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    fast=0;
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}

int main(){
    vector<int> nums={1,3,4,2,2};
    cout<<findDuplicate1(nums)<<endl;
    return 0;
}