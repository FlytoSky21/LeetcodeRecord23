#include<vector>
#include<iostream>
#include<ctime>
using namespace std;

/*
快速排序，其实是一种分治算法，本质是将一个大规模的问题分解为若干个规模较小的相同子问题，分而治之
先从数列中取出一个元素作为基准元素。一基准元素为标准，将问题分解为两个子序列，
使小于或者等于基准元素的子序列在左侧，使大于基准元素的子序列在右侧。
快速排序每一次都排定一个元素（这个元素呆在了它最终应该呆的位置），然后递归地去排它左边的部分和右边的部分，依次进行下去，直到数组有序
*/

//切分：把切分元素放在排序以后最终应该在的位置(1.把一个区间按照数值大小进行划分，
//2.排定一个元素的位置)

//经典快排,一次只能确定一个数的位置
//额外空间复杂度O(logN),时间复杂度（N*logN)
void quickSort(vector<int>& arr,int l,int r){
    if(l>=r) return;
    int left=l,right=r;
    int pivot=arr[left];
    while(left<right){
        while(left<right&&arr[right]>=pivot){
            --right;
        }
        if(left<right){
            arr[left]=arr[right];
        }
        while(left<right&&arr[left]<=pivot){
            ++left;
        }
        if(left<right){
            arr[right]=arr[left];
        }
        if(left>=right) arr[left]=pivot;
    }
    quickSort(arr,l,right-1);
    quickSort(arr,right+1,r);
}

//小于在左边，等于在中间，大于等于右边
vector<int> partition(vector<int>& arr,int l,int r){
    int less=l-1,more=r;
    int cur=l;

    while(cur<more){
        if(arr[cur]<arr[r]){
            swap(arr[cur++],arr[++less]);
        }else if(arr[cur]>arr[r]){
            swap(arr[cur],arr[--more]);
        }else{
            cur++;
        }
    }
    swap(arr[more],arr[r]);   //把大于区域的第一个元素与最后一个元素交换，则中间都是等于区域
    return vector<int>{less+1,more};
}
//改进快排,中间等于目标的数的位置都确定
void quickSort1(vector<int>& arr,int l,int r){
    if(l>=r) return;
    srand(time(0));
    int idx=(rand()%(r-l+1))+l;   //随机快排
    swap(arr[r],arr[idx]);
    vector<int> p=partition(arr,l,r);
    quickSort1(arr,l,p[0]-1);
    quickSort1(arr,p[1]+1,r);
}

int main(){
    vector<int> nums={1,4,6,4,5,3,2,5,4,9};
    // int num;
    // while(cin>>num){
    //     nums.push_back(num);
    //     if(getchar()=='\n') break;
    // }
    quickSort1(nums,0,nums.size()-1);
    for(auto ch:nums){
        cout<<ch<<"  ";
    }
    cout<<endl;
    return 0;
}