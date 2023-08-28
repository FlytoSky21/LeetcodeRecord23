/*给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题
示例 1:
输入: [3,2,1,5,6,4], k = 2
输出: 5
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

//排序
static bool cmp(int& a,int& b){
    return a>b;
}
int findKthLargest(vector<int>& nums,int k){
    sort(nums.begin(),nums.end(),cmp);
    return nums[k-1];
}

//快速排序(普通版本，容易超时)
int partition(vector<int>& nums,int left,int right){
    //随机获取一个中轴数
    srand(time(0));
    int idx=(rand()%(right-left+1))+left;
    cout<<idx<<endl;
    swap(nums[left],nums[idx]);
    int pivot=nums[left];
    while(left<right){
        while(left<right&&nums[right]>=pivot) right--;
        if(left<right) nums[left]=nums[right];
        while(left<right&&nums[left]<pivot) left++;
        if(left<right) nums[right]=nums[left];
        if(left==right) nums[left]=pivot;
    }
    return left;
}
int findKthLargest1(vector<int>&nums,int k){
    int len=nums.size();
    int target=len-k;  //快排的话寻找下标为len-k的元素即为第k大的元素
    int left=0,right=nums.size()-1;
    while(true){  //一定可以找到答案
        int index=partition(nums,left,right);
        if(index==target) return nums[index];
        else if(index<target){
            left=index+1;
        }else{
            right=index-1;
        }
    }
}

int main(){
    vector<int> nums;
    int num,k;
    while(cin>>num){
        nums.push_back(num);
        if(getchar()=='\n') break;
    }
    cin>>k;
    cout<<findKthLargest1(nums,k)<<endl;
    return 0;
}