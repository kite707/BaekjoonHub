#include <stack>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int answer = 0;
    stack <char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('&&s[i+1]==')'){answer+=st.size();i++;}
        else if(s[i]==')'){answer+=1;st.pop();}
        else st.push('(');
    }
    cout<<answer;
}