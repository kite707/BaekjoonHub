#include <stack>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n;
    int answer = 0;
    while(n--){
        cin>>s;
        stack<char> st;
        for(char k :s ){
            if(!st.empty()&&st.top()==k)st.pop();
            else st.push(k);
        }
        if(st.empty()){
            answer++;
        }
    }
    cout<<answer;
}