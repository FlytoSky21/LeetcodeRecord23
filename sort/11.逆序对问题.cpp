/***
 * 逆序对问题：在一个数组中，左边的数如果比右边的数大，则这两个数构成一个逆序对，
 * 请打印所有逆序对
 * ***/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums,int left,int mid,int right){
    vector<int> help(right-left+1);
    int index=0;
    int p1=left,p2=mid+1;
    while(p1<=mid&&p2<=right){
        //如果左边的数比右边的数大，则打印该逆序对
        if(nums[p1]>nums[p2]){
            for(int i=p1;i<=mid;++i){
                cout<<"("<<nums[i]<<","<<nums[p2]<<")"<<endl;
            }
        }
        help[index++]=nums[p1]<nums[p2]?nums[p1++]:nums[p2++];
    }
    while(p1<=mid){
        help[index++]=nums[p1++];
    }
    while(p2<=right){
        help[index++]=nums[p2++];
    }
    for(int i=0;i<help.size();++i){
        nums[left+i]=help[i];
    }
}

void mergeSort(vector<int>& nums,int left,int right){
    if(left==right) return;
    int mid=left+(right-left)/2;
    mergeSort(nums,left,mid);
    mergeSort(nums,mid+1,right);
    merge(nums,left,mid,right);
}

void nixudui(vector<int>& nums){
    if(nums.size()<2) return;
    mergeSort(nums,0,nums.size()-1);
    for(auto num:nums){
        cout<<num<<"  ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums={3,2,1,0};
    nixudui(nums);
    return 0;
}