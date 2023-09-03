/**
 * 复制含有随机指针节点的链表
 * 【 题目】 一种特殊的链表节点类描述如下：
 * public class Node { public int value; public Node next; public Node rand;
 * public Node(int data) { this.value = data; }}
 *  Node类中的value是节点值， next指针和正常单链表中next指针的意义一 样， 都指向下一个节点，
 *  rand指针是Node类中新增的指针， 这个指针可能指向链表中的任意一个节点， 也可能指向null。 
 * 给定一个由Node节点类型组成的无环单链表的头节点head， 请实现一个 函数完成这个链表中所有结构
 * 的复制， 并返回复制的新链表的头节点。 
 * 进阶：不使用额外的数据结构， 只用有限几个变量， 且在时间复杂度为 O(N)内完成原问题要实现的
 * 函数。
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* random;
    Node(int data):val(data){}
};


//使用哈希表
Node* copyListWithRand(Node* head){
    unordered_map<Node*,Node*> hashmap;
    Node* cur=head;
    while(cur!=nullptr){
        hashmap[cur]=new Node(cur->val);
        cur=cur->next;
    }
    cur=head;
    while(cur){
        hashmap[cur]->next=hashmap[cur->next];
        hashmap[cur]->random=hashmap[cur->random];
        cur=cur->next;
    }
    return hashmap[head];
}


Node* copyListWithRand2(Node* head){
    if(head==nullptr) return nullptr;
    Node* cur=head;
    Node* next=nullptr;
    //拷贝每个节点，让每个节点的下一节点指向当前节点的拷贝节点
    while(cur!=nullptr){
        next=cur->next;
        cur->next=new Node(cur->val);
        cur->next->next=next;
        cur=next;
    }
    cur=head;
    Node* curCopy=nullptr;
    //设置拷贝随机节点
    while(cur){
        next=cur->next->next;
        curCopy=cur->next;
        curCopy->random=cur->random?cur->random->next:nullptr;
        cur=next;
    }
    Node* res=head->next;
    cur=head;
    //分离
    while(cur){
        next=cur->next->next;
        curCopy=cur->next;
        cur->next=next;
        curCopy->next=next?next->next:nullptr;
        cur=next;
    }
    return res;
}


