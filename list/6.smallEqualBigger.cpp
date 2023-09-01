/**
 * 将单向链表按某值划分成左边小、 中间相等、 右边大的形式
 * 【 题目】 给定一个单向链表的头节点head， 节点的值类型是整型， 再给定一个整 数pivot。 实现
 * 一个调整链表的函数， 将链表调整为左部分都是值小于 pivot的节点， 中间部分都是值等于pivot的
 * 节点， 右部分都是值大于 pivot的节点。除这个要求外， 对调整后的节点顺序没有更多的要求。 例如
 * ： 链表9->0->4->5->1， pivot=3。 调整后链表可以是1->0->4->9->5， 也可以是0->1->9->5->4。
 *  总之， 满足左部分都是小于3的节点， 中间部分都是等于3的节点（本例中这个部分为空） ， 右部分
 * 都是大于3的节点即可。 对某部分内部的节点顺序不做 要求。
*/


#include<vector>
#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
    Node(int _val):value(_val),next(nullptr){}
    Node(int _val,Node* _next):value(_val),next(_next){}
};

Node* createList(vector<int>& nums){
    if(nums.size()<1) return nullptr;
    Node* dummy=new Node(nums[0]);
    Node* cur=dummy;
    for(int i=1;i<nums.size();++i){
        cur->next=new Node(nums[i]);
        cur=cur->next;
    }
    cur->next=nullptr;
    return dummy;
}

void partition(vector<int>& nums,int pivot){
    int less=-1,more=nums.size();
    int i=0;
    while(i<more){
        if(nums[i]<pivot){
            swap(nums[i++],nums[++less]);
        }else if(nums[i]>pivot){
            swap(nums[i],nums[--more]);
        }else{
            i++;
        }
    }
}

//最快的做法：遍历链表，把值存在一个数组中，然后对数组进行荷兰国旗问题，最后再调整原来链表的值
Node* listPartition(Node* head,int pivot){
    if(head==nullptr||head->next==nullptr) return head;
    vector<int> nums;
    Node* cur=head;
    while(cur){
        nums.push_back(cur->value);
        cur=cur->next;
    }
    partition(nums,pivot);
    cur=head;
    for(int i=0;i<nums.size();++i){
        cur->value=nums[i];
        cur=cur->next;
    }
    return head;
}

//或者直接数组中存储节点
void NodePartition(vector<Node*>& vec,int pivot){
    int less=-1,more=vec.size();
    int i=0;
    while(i<more){
        if(vec[i]->value<pivot){
            swap(vec[i++],vec[++less]);
        }else if(vec[i]->value>pivot){
            swap(vec[i],vec[--more]);
        }else{
            i++;
        }
    }
}
Node* listPartition1(Node* head,int pivot){
    if(head==nullptr||head->next==nullptr) return head;
    vector<Node*> vec;
    Node* cur=head;
    while(cur){
        vec.push_back(cur);
        cur=cur->next;
    }
    NodePartition(vec,pivot);
    for(int i=0;i<vec.size()-1;++i){
        vec[i]->next=vec[i+1];
    }
    vec[vec.size()-1]->next=nullptr;
    return vec[0];
}

void disp(Node* head){
    while(head){
        cout<<head->value;
        if(head->next) cout<<"->";
        head=head->next; 
    }
    cout<<endl;
}

/**
 * 进阶： 在原问题的要求之上再增加如下两个要求。在左、 中、 右三个部分的内部也做顺序要求， 要求
 * 每部分里的节点从左到右的顺序与原链表中节点的先后次序一致。 例如： 链表9->0->4->5->1， 
 * pivot=3。调整后的链表是0->1->9->4->5。 在满足原问题要求的同时， 左部分节点从左到右为0、 1。
 * 在原链表中也 是先出现0，后出现1；中间部分在本例中为空， 不再讨论； 右部分节点 从左到右为
 * 9、 4、 5。 在原链表中也是先出现9， 然后出现4，最后出现5。如果链表长度为N， 时间复杂度请达
 * 到O(N)， 额外空间复杂度请达到O(1)
*/
Node* listPartition2(Node* head,int k){
    Node* small_head=nullptr;
    Node* small_tail=nullptr;
    Node* equal_head=nullptr;
    Node* equal_tail=nullptr;
    Node* big_head=nullptr;
    Node* big_tail=nullptr;
    Node* next=nullptr;  //保存下个节点
    
    while(head){
        next=head->next;
        head->next=nullptr;
        if(head->value<k){
            if(small_head==nullptr){
                small_head=head;
                small_tail=head;
            }else{
                small_tail->next=head;
                small_tail=small_tail->next;
            }
        }else if(head->value==k){
            if(equal_head==nullptr){
                equal_head=head;
                equal_tail=head;
            }else{
                equal_tail->next=head;
                equal_tail=equal_tail->next;
            }
        }else{
            if(big_head==nullptr){
                big_head=head;
                big_tail=head;
            }else{
                big_tail->next=head;
                big_tail=big_tail->next;
            }
        }
        head=next;
    }

    //less and more reconnect
    if(small_tail!=nullptr){
        small_tail->next=equal_head;
        equal_tail=equal_tail==nullptr?small_tail:equal_tail;
    }
    if(equal_tail!=nullptr){
        equal_tail->next=big_head;
    }
    return small_head!=nullptr?small_head:equal_head!=nullptr?equal_head:big_head;
}


int main(){
    vector<int> nums={9,0,4,5,1,10,13};
    int k=5;
    Node* head=createList(nums);
    disp(head);
    head=listPartition2(head,k);
    disp(head);
    return 0;
}

