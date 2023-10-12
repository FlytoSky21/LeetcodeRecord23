#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
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

string decodeString1(string s){
    stack<pair<string,int>> stk;
    int num=0;
    string str="";
    for(char ch:s){
        if(isdigit(ch)){
            num=num*10+int(ch-'0');
        }else if(ch=='['){
            stk.push({str,num});
            str="";
            num=0;
        }else if(isalpha(ch)){
            str+=ch;
        }else if(ch==']'){
            int times=stk.top().second;
            string pre=stk.top().first;
            stk.pop();
            // string temp="";
            // while(times--){
            //     temp+=str;
            // }
            // str=pre+temp;
            stringstream ss;
            while(times--)  ss<<str;
            str=pre+ss.str();
        }
    }
    return str;
}

int main(){
    string s = "2[abc]3[cd]ef";
    cout<<decodeString1(s)<<endl;
    return 0;
}