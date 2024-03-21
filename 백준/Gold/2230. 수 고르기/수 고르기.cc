#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//이분탐색 풀이
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
    for(int i=0;i<v.size();i++){
        int curNum = v[i];
        int toFind=v[i]-m;
        //cout<<"toFind is "<<toFind<<endl;
        if(binary_search(v.begin(),v.end(),toFind)){
            cout<<m;
            return 0;
        }
        int idx= lower_bound(v.begin(),v.end(),toFind)-v.begin()-1;
        if(idx<0)continue;
        if(curNum-v[idx]>=m){
            q.push(curNum-v[idx]);
        }
    }
    cout<<q.top();
}