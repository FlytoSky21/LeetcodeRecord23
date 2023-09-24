#include<iostream>
using namespace std;

int add(int a,int b){
    while(b!=0){
        unsigned int carry=(unsigned int)(a&b)<<1;    //进位部分
        a=a^b;    //异或计算未进位的部分
        b=carry;      //保存进位部分，再次计算
    }
    return a;
}
int main(){
    // int a=3,b=5;
    // cout<<add(a,b)<<endl;
    char str[]
    return 0;
}