#include<vector>
#include<iostream>
using namespace std;


//归并排序：先左侧排好序，再右侧排好序，然后使用外排的方式排好所有。
//时间复杂度：O(NlogN)，额外空间复杂度O(N)

void merge(vector<int>& nums,int L,int mid,int R){
    vector<int> help(R-L+1);
    int i=0;
    int p1=L,p2=mid+1;
    while(p1<=mid&&p2<=R){
        help[i++]=nums[p1]<nums[p2]?nums[p1++]:nums[p2++];
    }
    //两个只有一个越界
    while(p1<=mid){
        help[i++]=nums[p1++];
    }
    while (p2<=R)
    {
        help[i++]=nums[p2++];
    }
    for(int j=0;j<help.size();++j){
        nums[L+j]=help[j];
    }
}

void sortProcess(vector<int>& nums,int L,int R){
    if(L==R) return;
    int mid=L+(R-L)/2;
    sortProcess(nums,L,mid);
    sortProcess(nums,mid+1,R);
    merge(nums,L,mid,R);
}

void mergeSort(vector<int>& nums){
    if(nums.size()<2) return;
    sortProcess(nums,0,nums.size()-1);
}

int main(){
    vector<int> nums={1,5,6,3,4,9,5,3};
    mergeSort(nums);
    for(auto num:nums){
        cout<<num<<"  ";
    }
    return 0;
}