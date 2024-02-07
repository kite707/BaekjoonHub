#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(true){
        getline(cin,s);
        if(s==".") break;
        bool isBalance = true;
        stack <char> st;
        for(auto k : s){
            if(k=='['||k=='(')st.push(k);
            else if(k==')'){
                if(st.empty()||st.top()!='('){isBalance=false; break;}
                else st.pop();
            }else if (k==']'){
                if(st.empty()||st.top()!='['){isBalance=false; break;}
                else st.pop();
            }
        }
        if(!st.empty()) isBalance =false;
        if(isBalance)cout<<"yes\n";
        else cout<<"no\n";
    }


}