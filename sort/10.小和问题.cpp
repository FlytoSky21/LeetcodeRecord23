/***
在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和
***/

#include<iostream>
#include<vector>
using namespace std;

//遍历  复杂度O(N^2)
int smallSum(vector<int>& nums){
    int ans=0;
    for(int i=1;i<nums.size();++i){
        for(int j=0;j<i;++j){
            if(nums[j]<nums[i]) ans+=nums[j];
        }
    }
    return ans;
}

//合并的时候求该小区间的小和
int merge(vector<int>& nums,int left,int mid,int right){
    vector<int> help(right-left+1);
    int res=0;  //该合并区间的小和
    int i=0;
    int p1=left,p2=mid+1;
    while(p1<=mid&&p2<=right){
        res+=nums[p2]>nums[p1]?nums[p1]*(right-p2+1):0;
        help[i++]=nums[p2]>nums[p1]?nums[p1++]:nums[p2++];
    }
    while(p1<=mid){
        help[i++]=nums[p1++];
    }
    while(p2<=right){
        help[i++]=nums[p2++];
    }
    for(int j=0;j<help.size();++j){
        nums[left+j]=help[j];
    }
    return res;
}

int mergeSort(vector<int>& nums,int l,int r){
    if(l==r) return 0;
    int mid=l+(r-l)/2;
    return mergeSort(nums,l,mid)+mergeSort(nums,mid+1,r)+merge(nums,l,mid,r);
}

int smallSum1(vector<int>& nums){
    if(nums.size()<2) return 0;
    return mergeSort(nums,0,nums.size()-1);
}

//归并排序法，数组划分为两半，然后再去分治

int main(){
    vector<int> nums={1,3,4,2,5};
    cout<<smallSum1(nums)<<endl;
    return 0;
}