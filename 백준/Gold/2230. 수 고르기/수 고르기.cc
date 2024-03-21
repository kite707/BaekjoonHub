#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//투포인터 풀이
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int,vector<int>,greater<int>> q;
    int n,m,t;
    cin>>n>>m;
    while(n--){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    int st=0;
    int en=0;
    while(en<v.size()){
        if(v[en]-v[st]==m){
            cout<<m;
            return 0;
        }
        else if(v[en]-v[st]<m){
            en++;
        }
        else{
            q.push(v[en]-v[st]);
            st++;
        }
    }
    cout<<q.top();

}