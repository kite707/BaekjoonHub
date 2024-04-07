#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <iostream>
using namespace std;
deque<char> q;

bool checker(){
    stack<char> st;
    st.push('0');
    for(int i=0;i<q.size();i++){
        char cur = q[i];
        if(cur==')'){
            if(st.top()!='(')return false;
            st.pop();
            continue;
        }
        if(cur==']'){
            if(st.top()!='[')return false;
            st.pop();
            continue;
        }
        if(cur=='}'){
            if(st.top()!='{')return false;
            st.pop();
            continue;
        }
        st.push(cur);
    }
    if(st.size()==1)return true;
    return false;
}
int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.size();i++){
        q.push_back(s[i]);
    }  
    
    
    for(int i=0;i<s.size();i++){
        if(checker())answer++;
        int cur=q.front();
        q.pop_front();
        q.push_back(cur);
    }
    return answer;
}