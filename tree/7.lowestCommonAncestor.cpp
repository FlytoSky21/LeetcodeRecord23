#include<vector>
#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


TreeNode* constructTree(const vector<int>& nums,int start){
    if(nums.size()==0||nums[start]=='#') return nullptr;
    TreeNode* root=new TreeNode(nums[start]);
    int lpos=start*2+1,rpos=start*2+2;
    if(0<=lpos&&lpos<nums.size()) root->left=constructTree(nums,lpos);
    if(0<=rpos&&rpos<nums.size()) root->right=constructTree(nums,rpos);
    return root;
}

int lowestCommonAncestor0(TreeNode* root, int o1, int o2){
    //该子树没找到，返回-1
    if(root==nullptr) return -1;
    //该节点是其中某一个节点
    if(root->val==o1||root->val==o2) return root->val;
    //左子树寻找公共祖先
    int left=lowestCommonAncestor0(root->left,o1,o2);
    int right=lowestCommonAncestor0(root->right,o1,o2);
    //左子树没找到，则在右子树中
    if(left==-1) return right;
    //右子树没找到，则在左子树中
    if(right==-1) return left;
    //否则是当前节点
    return root->val;
}

vector<int> getPath(TreeNode* root,int target){
    vector<int> path;
    while(root->val!=target){
        path.push_back(root->val);
        if(root->val>target){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    path.push_back(root->val);
    return path;
}

//二叉搜索数的最近公共节点,搜索路径比较
int lowestCommonAncestor(TreeNode* root, int p, int q) {
    vector<int> path_p=getPath(root,p);
    vector<int> path_q=getPath(root,q);
    int res=-1;
    for(int i=0;i<path_p.size()&&i<path_q.size();++i){
        if(path_q[i]==path_p[i]){
            res=path_p[i];
        }else{
            break;
        }
    }
    return res;
}

/**一次遍历
 * 1. 首先检查空节点，空树没有公共祖先
 * 2. 对于某个节点，比较与p、q的大小，若p和q在该节点的两边，说明这就是最近公共祖先
 * 3. 如果p和q都在该节点的左边，则递归进入左子树
 * 4. 如果P和q都在该节点的右边，则递归进入右子树
*/
int lowestCommonAncestor1(TreeNode* root, int p, int q){
    if(root==nullptr) return -1;
    if((p>=root->val&&q<=root->val)||(p<=root->val&&q>=root->val)){
        return root->val;
    }
    //p和q都在节点的左边
    else if(p<=root->val&&q<=root->val) 
        return lowestCommonAncestor1(root->left,p,q);
    else   //p和q都在节点右子树
        return lowestCommonAncestor1(root->right,p,q);
}

int lowestCommonAncestor2(TreeNode* root, int p, int q){
    int v=root->val;
    //p、q都小于root的值，他们都在root的左子树中，root不是最近公共祖先
    if(p<v&&q<v) return lowestCommonAncestor2(root->left,p,q);
    //p、q都大于root的值，他们都在root的右子树中，root不是最近公共祖先
    else if(p>v&&q>v) return lowestCommonAncestor2(root->right,p,q);
    //p和q在root两端，root就是公共祖先
    return v;
}

int main(){
    vector<int> nums={7,1,12,0,4,11,14,0,'#','#',3,5};
    TreeNode* root=constructTree(nums,0);
    int ans=lowestCommonAncestor0(root,11,12);
    cout<<ans<<endl;
    return 0;
}