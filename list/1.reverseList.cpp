/**
 * 反转单向链表
 * 【 题目】 分别实现反转单向链表函数。
 * 【 要求】 如果链表长度为N， 时间复杂度要求为O(N)， 额外空间复杂度要求为O(1)
*/
#include<vector>
#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int val):value(val){}
    Node(int val,Node* nt):value(val),next(nt){}
};

//通过数组单向构造链表
Node* createList(vector<int>& nums){
    Node* dummy=new Node(0);
    Node* cur=dummy;
    for(int num:nums){
        cur->next=new Node(num);
        cur=cur->next;
    }
    cur->next=nullptr;
    cur=dummy->next;
    delete dummy;
    return cur;
}

//打印单向链表
void disp(Node* head){
    if(head==nullptr) return;
    while(head){
        cout<<head->value;
        if(head->next) cout<<"->";
        head=head->next;
    }
    cout<<endl;
}

//反转单向链表
Node* reverseList(Node* head){
    if(head==nullptr||head->next==nullptr) return head;
    Node* pre=nullptr;
    Node* cur=head;
    while(cur){
        Node* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}

int main(){
    vector<int> nums={1,2,3,4,5,6};
    Node* head=createList(nums);
    disp(head);
    head=reverseList(head);
    disp(head);
    return 0;
}