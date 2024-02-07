#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,L,a;
    int minNum = 10000000000;
    cin>>N>>L;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
    for(int i=1;i<=N;i++){
        cin>>a;
        minNum=min(a,minNum);
        q.push(make_pair(a,i));
        if(i<=L)cout<<minNum<<" ";
        else{
            while(q.top().second<=i-L)q.pop();
            cout<<q.top().first<<" ";
        }
    }
}