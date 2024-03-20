#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v;
vector<int> ori;
set<int> st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int t;
    while(n--){
        cin>>t;
        v.push_back(t);
        ori.push_back(t);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<ori.size();i++){
        cout<<lower_bound(v.begin(),v.end(),ori[i])-v.begin()<<" ";
    }
}