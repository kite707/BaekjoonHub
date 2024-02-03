#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    K--;
    cout<<"<";
    while(q.size()!=1){
        for(int i=0;i<K;i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
        cout<<q.front()<<", ";
        q.pop();
    }
    cout<<q.front()<<">";
}