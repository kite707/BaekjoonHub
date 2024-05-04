#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int getSlice(string p){
    int cnt=0;
    for(int i=0;i<p.length();i++){
        if(p[i]=='(')cnt++;
        else cnt--;
        if(cnt==0){
            return i;
        }
    }
    return p.length();
}

bool isBalance(string s){
    stack<char> st;
    for(auto k:s){
        if(k=='(')st.push('(');
        else{
            if(st.empty())return false;
            st.pop();
        }
    }
    return st.empty();
}


string solution(string p) {
    if(p=="")return "";
    int cnt=0;
    string a,b;
    int idx=getSlice(p);
    a=p.substr(0,idx+1);
    b=p.substr(idx+1,p.length());
    
    if(isBalance(a)){
        string ans=a+solution(b);
        return ans;
    }
    string ans="(";
    ans+=solution(b);
    ans+=")";
    string tmp;
    for(int i=1;i<a.length()-1;i++){
        tmp+=a[i];
    }
    a=tmp;
    for(int i=0;i<a.length();i++){
        if(a[i]=='('){
            ans+=")";
        }else{
            ans+="(";
        }
    }
    return ans;
    
    // cout<<a<<endl;
    // cout<<b<<endl;
    // string answer = "";
    // return answer;
}