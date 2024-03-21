#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,m,v,c;
    cin>>n>>k;
    multimap<int,int,greater<int>> mp;
    multiset<int> bag;
    for(int i=0;i<n;i++){
        cin>>m>>v;
        mp.insert({v,m});
    }
    while(k--){
        cin>>c;
        bag.insert(c);
    }
    long long ans=0;
    for(auto k:mp){
        int weight = k.second;
        auto it= bag.lower_bound(weight);
        if(it==bag.end())continue;
        bag.erase(it);
        ans+=k.first;
    }
    cout<<ans;

}