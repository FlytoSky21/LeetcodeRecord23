#include<string>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

string decodeString(string s){
    stack<char> stk_num;
    stack<string> stk_str;
    int num=0;
    string str="";
    for(char ch:s){
        if(isdigit(ch)){
            num=10*num+int(ch-'0');
        }else if(ch=='['){
            stk_num.push(num);
            num=0;
            stk_str.push(str);
            str="";
        }else if(isalpha(ch)){
            str+=ch;
        }else if(ch==']'){
            int k=stk_num.top();stk_num.pop();
            string temp="";
            while(k--){
                temp+=str;
            }
            str=stk_str.top(); stk_str.pop();
            str+=temp;
        }
    }
    return str;
}

int main(){
    string s = "2[abc]3[cd]ef";
    cout<<decodeString(s)<<endl;
    return 0;
}