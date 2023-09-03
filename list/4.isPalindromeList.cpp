#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 判断一个链表是否为回文结构
 * 【 题目】 给定一个链表的头节点head， 请判断该链表是否为回文结构。 例如： 1->2->1
 *  返回true。 1->2->2->1， 返回true。15->6->15， 返回true。 1->2->3， 返回false。
 * 进阶： 如果链表长度为N， 时间复杂度达到O(N)， 额外空间复杂度达到O(1)。
*/

//链表节点
struct Node
{
   int value;
   Node* next;
   Node(int val):value(val){}
   Node(int val,Node* nt):value(val),next(nt){}
};

//使用栈结构逆序，然后一个一个对比（正着念和翻着念一样是回文
bool isPalindrome(Node* head){
    stack<Node*> stk;
    Node* cur=head;
    while(cur){
        stk.push(cur);
        cur=cur->next;
    }
    while(head){
        if(head->value!=stk.top()->value){
            return false;
        }else{
            stk.pop();
            head=head->next;
        }
    }
    return true;
}

//快慢指针，快指针走到头的时候，慢指针来到中点，把中点及以后的数据放进栈里对比
bool isPalindrome2(Node* head){
    if(head==nullptr||head->next==nullptr) return true;
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    stack<Node*> stk;
    slow=slow->next;
    while(slow!=nullptr){
        stk.push(slow);
        slow=slow->next;
    }
    while(!stk.empty()){
        if(stk.top()->value!=head->value){
            return false;
        }
        head=head->next;
        stk.pop();
    }
    return true;
}


//彻底不用辅助空间，快指针走到头的时候，慢指针来到中点，把中点以后的指针指向前一个节点
//然后判断。最后把数据恢复到原来的样子
bool isPalindrome3(Node* head){
    if(head==nullptr||head->next==nullptr) return true;

    Node* slow=head,*fast=head->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    fast=slow->next;    //右边部分的第一个节点
    slow->next=nullptr;
    while(fast){        //右边部分逆序
        Node* next=fast->next;
        fast->next=slow;
        slow=fast;
        fast=next;
    }
    fast=head;
    bool result=true;
    Node* n3=slow;  //记录最后一个节点
    while(slow!=nullptr&&fast!=nullptr){
        if(slow->value!=fast->value){
            result=false;
            break;
        }
        slow=slow->next;
        fast=fast->next;
    }
    slow=n3->next;
    n3->next=nullptr;
    while(slow!=nullptr){
         fast=slow->next;
         slow->next=n3;
         n3=slow;
         slow=fast;
    }
    return result;
}

//使用数组构造链表
Node* createList(vector<int>& nums){
    Node* dummy=new Node(0);
    Node* cur=dummy;
    for(int num:nums){
        cur->next=new Node(num);
        cur=cur->next;
    }
    cur->next=nullptr;
    return dummy->next;
}

void disp(Node* node){
    if(node==nullptr) return;
    while(node!=nullptr){
        cout<<node->value;
        if(node->next) cout<<"->";
        node=node->next;
    }
    cout<<endl;
}

int main(){
    vector<int> nums={1,2,5,6,2,1};
    Node* node=createList(nums);
    disp(node);
    cout<<isPalindrome3(node)<<endl;
    disp(node);
    return 0;
}