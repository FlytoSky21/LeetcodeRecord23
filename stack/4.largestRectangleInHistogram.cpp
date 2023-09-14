#include<vector>
#include<iostream>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights){
    heights.insert(heights.begin(),0);
    heights.push_back(0);

    stack<int> stk;
    stk.push(0);
    int ans=0;
    for(int i=1;i<heights.size();++i){
        if(heights[i]>=heights[i-1]){    //当前值大于前一个值，直接进栈
            stk.push(i);
        }else{      //当前值小于前一个值，以前一个值为高的最大面积确定
            while(!stk.empty()&&heights[i]<heights[stk.top()]){
                int mid=stk.top(); stk.pop();
                int left=stk.top();
                int area=(i-left-1)*heights[mid];
                ans=max(ans,area);
            }
            stk.push(i);
        }
    }
    return ans;
}

int main(){
    vector<int> heights={2,1,5,6,2,3};
    cout<<largestRectangleArea(heights)<<endl;
    return 0;
}