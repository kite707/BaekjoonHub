#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

pair<string,int> removeZero(string s){
    int originalLength=s.size();
    string ans="";
    for(int i=0;i<originalLength;i++){
        if(s[i]=='0')continue;
        ans+=s[i];
    }
    return {ans,originalLength-ans.length()};
}

string lengthToBinary(int length){
    stack<int> st;
    string s="";
    while(length!=0){
        st.push(length%2);
        length/=2;
    }
    while(!st.empty()){
        s+=to_string(st.top());
        st.pop();
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0;
    int ans=0;
    while(s!="1"){
        cnt++;
        pair<string,int> res= removeZero(s);
        ans+=res.second;
        s=lengthToBinary(res.first.size());
    }
    answer.push_back(cnt);
    answer.push_back(ans);
    return answer;
}