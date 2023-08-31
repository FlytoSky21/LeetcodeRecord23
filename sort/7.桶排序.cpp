#include<iostream>
#include<vector>
#include<limits.h>  //INT_MIN,INT_MAX的头文件
using namespace std;

/**
 * 桶排序、计数排序、基数排序的介绍
 * 桶排序是大概念，计数排序和基数排序是具体实现
 * 1. 非基于比较的排序，与被排序的样本的实际数据状况很有关系，所以实际上并不经常使用
 * 2. 时间复杂度为O(N)，额外空间复杂度为O(N)
 * 3. 稳定的排序
*/

/**
 * 桶排序：
 *一种数据状况出现的词频,桶是按照数据状况设计的容器，然后把数据扔进归属它的桶里，
 * 一个萝卜一个坑
*/

void bucketSort(vector<int>& nums){
    //Only for 0~200 value
    if(nums.size()<2) return;
    int max_val=INT_MIN;
    for(int i=0;i<nums.size();++i){
        max_val=max(max_val,nums[i]);
    }
    vector<int> bucket(max_val+1);
    for(int i=0;i<nums.size();++i){
        bucket[nums[i]]++;
    }
    int i=0;
    for(int j=0;j<bucket.size();++j){
        while(bucket[j]--){
            nums[i++]=j;
        }
    }
}

int main(){
    vector<int> nums={1,4,6,4,5,3,2,5,4,9};
    // int num;
    // while(cin>>num){
    //     nums.push_back(num);
    //     if(getchar()=='\n') break;
    // }
    bucketSort(nums);
    for(auto ch:nums){
        cout<<ch<<"  ";
    }

    cout<<endl;
    return 0;
}