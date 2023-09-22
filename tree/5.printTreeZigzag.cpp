#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode* constructTree(vector<int> nums,int start){
    if(nums.size()==0||nums[start]=='#') return nullptr;
    TreeNode* root=new TreeNode(nums[start]);
    root->left=nullptr;
    root->right=nullptr;
    int lpos=2*start+1,rpos=2*start+2;
    if(lpos<nums.size()) root->left=constructTree(nums,lpos);
    if(rpos<nums.size()) root->right=constructTree(nums,rpos);
    return root;
}
vector<vector<int>> Print(TreeNode* pRoot){
    vector<vector<int>> ans;
    if(pRoot==nullptr) return ans;
    bool flag=true;

    queue<TreeNode*> que;
    que.push(pRoot);
    while(!que.empty()){
        int sz=que.size();
        vector<int> temp;
        while(sz--){
            auto cur=que.front(); que.pop();
            temp.push_back(cur->val);
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        if(!flag) reverse(temp.begin(),temp.end());
        ans.push_back(temp);
        flag=!flag;
    }
    return ans;
}

int main(){
    vector<int> nums={8,6,10,5,7,9,11};
    TreeNode* root=constructTree(nums,0);
    vector<vector<int>> ans=Print(root);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}