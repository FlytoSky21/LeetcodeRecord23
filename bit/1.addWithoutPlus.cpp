#include<iostream>
using namespace std;


/**
 * 位运算中，两数进行异或运算可以提供两数加和之后二进制非进位信息
 * 两数进行与运算可以提供两数加和后的二进制进位信息
 * 将两数的与运算的结果循环左移一位，在下一轮循环中继续将进位结果和非进位结果求和，
 * 重复此过程，直到不再产生进位为止
*/
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