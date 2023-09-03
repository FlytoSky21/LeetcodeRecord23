/**
 * 两个单链表相交的一系列问题
 * 【 题目】 在本题中， 单链表可能有环， 也可能无环。 给定两个单链表的头节点 head1和head2，
 *  这两个链表可能相交， 也可能不相交。 请实现一个函数， 如果两个链表相交， 请返回相交的第
 * 一个节点； 如果不相交， 返回null 即可。 
 * 要求： 如果链表1的长度为N， 链表2的长度为M， 时间复杂度请达到 O(N+M)， 额外空间复杂度请
 * 达到O(1)。
*/
#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

//最简单的方法：把每一个节点放入到哈希表中，第一次发现某个节点在哈希表中出现，该节点即为入环
//节点


//快慢指针,如果有环，快慢指针一定会相遇
ListNode* getLoopNode(ListNode* head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }
    ListNode* fast=head->next,*slow=head;
    while(fast!=slow){
        if(fast==nullptr||fast->next==nullptr) return nullptr;
        fast=fast->next->next;
        slow=slow->next;
    }
    fast=head;
    slow=slow->next;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}

int main(){

    return 0;
}