#include<iostream>
#include<vector>
using namespace std;

/**
 * 堆排序,堆在C++中是优先级队列
 * 时间复杂度O(NlogN),空间复杂度O(1)
 * 堆实质上是一棵完全二叉树,可以把一个数组理解为一个完全二叉树，节点i的左孩子2*i+1,
 * 右孩子2*i+2,节点i的父节点为(i-1)/2
 * 大根堆：任何一个子树的最大值都是该子树的头节点
 * 小根堆：任何一个子树的最小值都是该子树的头节点
*/

/**
 * 建立大根堆的过程：来到i位置，0-i-1已经是大根堆了，把i位置插入大根堆(自底向上)
 * 时间复杂度O(N)=log1+log2+log3+...+longN
*/
void heapInert(vector<int>& nums,int index){
    //如果当前节点大于父节点，来到父节点，继续与父节点比较
    while(nums[index]>nums[(index-1)/2]){    
        swap(nums[index],nums[(index-1)/2]);
        index=(index-1)/2;
    }
}

/**
 * 假设数组中有一个值发生变小，重新调整原来的大根堆为大根堆（自顶向下）
 * 发生变化的值与子节点中较大的值交换位置
 * 0-heapsize-1上已经形成堆，index上值发生变化，导致index上值应该下沉
*/
void heapify(vector<int>& nums,int index,int heapsize){
    int left=index*2+1;
    while(left<heapsize){
        int largest=left+1<heapsize&&nums[left+1]>nums[left]?left+1:left;
        largest=nums[largest]>nums[index]?largest:index;
        if(largest==index) break;   //index上的值比子节点大，结束循环
        swap(nums[largest],nums[index]);
        index=largest;
        left=index*2+1;
    }
}
void heapSort(vector<int>& nums){
    if(nums.size()<2) return;
    //建立大根堆
    for(int i=0;i<nums.size();++i){
        heapInert(nums,i);
    }
    //排序
    int heapsize=nums.size();
    swap(nums[0],nums[--heapsize]);
    while(heapsize>0){
        heapify(nums,0,heapsize);
        swap(nums[0],nums[--heapsize]);
    }
}


int main(){
    vector<int> nums={1,4,6,4,5,3,2,5,4,9};
    // int num;
    // while(cin>>num){
    //     nums.push_back(num);
    //     if(getchar()=='\n') break;
    // }
    heapSort(nums);
    for(auto ch:nums){
        cout<<ch<<"  ";
    }
    cout<<endl;
    return 0;
}