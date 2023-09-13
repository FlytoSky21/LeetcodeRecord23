#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

bool isNumber(string& s){
    return s!="+"&&s!="-"&&s!="*"&&s!="/";
}

int evalRPN(vector<string>& tokens){
    stack<int> stk;
    for(string token:tokens){
        if(isNumber(token)){
            stk.push(stoi(token));
        }else{
            int num2=stk.top();stk.pop();
            int num1=stk.top();stk.pop();
            int result=0;
            switch(token[0]){
                case '+':{
                    result=num1+num2;
                    break;
                }
                case '-':
                    result=num1-num2;
                    break;
                case '*':
                    result=num1*num2;
                    break;
                case '/':
                    result=num1/num2;
                    break;
            }
            stk.push(result);
        }
    }
    int  ans=stk.top(); stk.pop();
    return ans;
}

int main(){
    vector<string> token={"2","1","+","3","*"};
    int ans=evalRPN(token);
    cout<<ans<<endl;
    return 0;
}