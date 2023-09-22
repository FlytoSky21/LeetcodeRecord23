#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode* constructTree(vector<int>& nums,int start){
    if(nums[0]=='#') return nullptr;
    TreeNode* root=new TreeNode(nums[0]);
    root->left=nullptr;
    root->right=nullptr;
    int lpos=2*start+1,rpos=2*start+2;
    if(lpos<nums.size()) root->left=constructTree(nums,lpos);
    if(rpos<nums.size()) root->right=constructTree(nums,rpos);
    return root;
}

int TreeDepth(TreeNode* pRoot){
    if(pRoot==nullptr) return 0;
    return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
}

int main(){
    vector<int> nums={1,2,3,4,5,'#',6,'#','#',7};
    TreeNode* root=constructTree(nums,0);
    int ans=TreeDepth(root);
    cout<<ans<<endl;
    return 0;
}