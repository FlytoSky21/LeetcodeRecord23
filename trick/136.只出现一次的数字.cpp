#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//哈希映射
int singleNumber(vector<int>& nums){
    unordered_map<int,int> hashmap; 
    for(auto num:nums){
        hashmap[num]++;
    }
    for(auto it:hashmap){
        if(it.second==1) return it.first;
    }
    return 0;
}

//异或 异或有交换律定理，相当于将相同的数字先异或，这样两两异或就只剩0了，
//然后0再和最后的一个数字异或得到最终值
int singleNumber1(vector<int>& nums){
    int ret=0;
    for(auto num:nums){
        ret^=num;
    }
    return ret;
}
int main(){
    vector<int> nums;
    int num;
    while(cin>>num){
        nums.push_back(num);
        if(getchar()=='\n') break;
    }
    cout<<singleNumber1(nums)<<endl;
    return 0;
}