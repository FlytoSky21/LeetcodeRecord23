/**
 * 打印两个有序链表的公共部分
 * 【 题目】 给定两个有序链表的头指针head1和head2， 打印两个链表的公共部分
*/

//类似外排的解法
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int val):value(val),next(nullptr){}
    Node(int val,Node* _next):value(val),next(_next){}
};

Node* createNodeList(vector<int>& nums){
    if(nums.size()==0) return nullptr;
    Node* dummy=new Node(nums[0]);
    Node* cur=dummy;
    for(int i=1;i<nums.size();++i){
        cur->next=new Node(nums[i]);
        cur=cur->next;
    }
    cur->next=nullptr;
    return dummy;
}

void printCommonPart(Node* head1,Node* head2){
    while(head1!=nullptr&&head2!=nullptr){
        if(head1->value<head2->value){
            head1=head1->next;
        }else if(head1->value>head2->value){
            head2=head2->next;
        }else{
            cout<<head1->value<<"  ";
            head1=head1->next;
            head2=head2->next;
        }
    }
    cout<<endl;
}

void disp(Node* head){
    while(head){
        cout<<head->value;
        if(head->next) cout<<"->";
        head=head->next;
    }
    cout<<endl;
}


int main(){
    vector<int> nums1={2,3,5,6};
    vector<int> nums2={1,2,5,7,8};
    Node* head1=createNodeList(nums1);
    Node* head2=createNodeList(nums2);
    disp(head1);
    disp(head2);
    printCommonPart(head1,head2);
    return 0;
}
