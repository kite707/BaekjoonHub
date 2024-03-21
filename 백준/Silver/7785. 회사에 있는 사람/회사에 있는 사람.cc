#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    unordered_set<string> st;
    string s,l;
    while(n--){
     cin>>s>>l;
     if(l=="enter")st.insert(s);
     else st.erase(s);
    }
    vector<string> ans(st.begin(),st.end());
    sort(ans.begin(),ans.end(),cmp);
    for(auto k:ans){
     cout<<k<<"\n";
    }
}