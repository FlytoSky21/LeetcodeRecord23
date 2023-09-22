#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>
using namespace std;


string ReverseSentence(string str) {
    reverse(str.begin(),str.end());
    int start=0;
    string ans="";
    for(int i=0;i<str.size();++i){
        if(str[i]==' '){
            reverse(str.begin()+start,str.begin()+i);
            start=i+1;
        }
    }
    reverse(str.begin()+start,str.end());
    return str;
}


int main(){
    string s="nowcoder. a am I";
    string str=ReverseSentence(s);
    cout<<str<<endl;
    return 0;
}