#include<iostream>
#include<vector>
#include<limits.h>  //INT_MIN,INT_MAX的头文件
using namespace std;

/**
 * 补充问题
 * 给定一个数组，求如果排序之后，相邻两数的最大差值，要求时间复杂度为O(N),且要求不能用非基于
 * 比较的排序
*/

/**
 * 1. 准备桶：如果有N个数，准备N+1个桶，先遍历数组，找到最大值和最小值，如果最大值==最小值，
 * 说明数组只有一种数，返回0。如果最大值！=最小值等，最小值放在0号桶，最大值放在N号桶，把最
 * 大值-最小值等分为N+1份，数字属于哪个范围，就进哪个桶。
 * 2. 每个桶只更新所有进入这个桶的最小值和最大值，以及这个桶进没进来数。
 * 3. 遍历完数组后，从1号桶开始，找它左边非空桶的最大值和当前桶的最大值，记录差值，答案一定
 * 在这些差值中。
 * 设定空桶是为了排除最大差值来自同一个桶内
*/

//某个数应该放在哪个桶中
int bucket(long num,long len,long min,long max){
    return (int)((num-min)*len/(max-min));
}

int maxGap(vector<int>& nums){
    if(nums.size()<2) return 0;
    int max_val=INT_MIN,min_val=INT_MAX;
    for(int i=0;i<nums.size();++i){
        min_val=min(min_val,nums[i]);
        max_val=max(max_val,nums[i]);
    }

    if(max_val==min_val) return 0;
    int n=nums.size();
    vector<int> max_nums(n+1),min_nums(n+1);
    vector<bool> has_num(n+1,false);
    int bid=0;
    for(int i=0;i<nums.size();++i){
        bid=bucket(nums[i],n,min_val,max_val);
        min_nums[bid]=has_num[bid]?min(min_nums[bid],nums[i]):nums[i];
        max_nums[bid]=has_num[bid]?max(max_nums[bid],nums[i]):nums[i];
        has_num[bid]=true;
    }

    int res=0;
    int lastMax=max_nums[0];
    for(int i=1;i<=n;++i){
        if(has_num[i]){
            res=max(res,min_nums[i]-lastMax);
            lastMax=max_nums[i];
        }
    }
    return res;
}


int main(){
    vector<int> nums={1,4,6,4,5,3,2,5,4,9};
    // int num;
    // while(cin>>num){
    //     nums.push_back(num);
    //     if(getchar()=='\n') break;
    // }
    // heapSort(nums);
    // for(auto ch:nums){
    //     cout<<ch<<"  ";
    // }
    cout<<maxGap(nums);
    cout<<endl;
    return 0;
}