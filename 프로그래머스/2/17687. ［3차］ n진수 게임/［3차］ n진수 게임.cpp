#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string oper(int n, int num){
    string tmp="";
    stack<string> st;
    while(num!=0){
        int remain=num%n;
        string s="";
        if(remain>=10){
            char a=remain+55;
            s=a;
        }else{
            s=to_string(remain);
        }
        st.push(s);
        num/=n;
    }
    while(!st.empty()){
        tmp+=st.top();
        st.pop();
    }
    return tmp;
}

//n진법 길이 len
string makeString(int n, int len){
    string tmp="00";
    int num=0;
    while(tmp.size()<=len){
        tmp+=oper(n,num);
        num++;
    }
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int totalSize=t*(m+1);
    string s= makeString(n,totalSize);
    while(answer.size()!=t){
        answer+=s[p];
        p+=m;
    }
    return answer;
}