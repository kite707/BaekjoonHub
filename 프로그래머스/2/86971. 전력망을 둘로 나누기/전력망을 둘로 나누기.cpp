#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[105];
int wireN;
bool isVisited[105];

void clearVisited(){
    for(int i=1;i<=wireN;i++){
        isVisited[i]=false;
    }
}

int bfs(int start,int a,int b){
    int cnt=1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        isVisited[cur]=true;
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int nxt=v[cur][i];
            if(cur==a&&nxt==b)continue;
            if(cur==b&&nxt==a)continue;
            if(isVisited[nxt])continue;
            q.push(nxt);
            cnt++;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    priority_queue<int,vector<int>,greater<int>> q;
    wireN=n;
    for(int i=0;i<wires.size();i++){
        int a= wires[i][0];
        int b=wires[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<wires.size();i++){
        priority_queue<int> bfsResult;
        clearVisited();
        int a= wires[i][0];
        int b=wires[i][1];
        for(int i=1;i<=n;i++){
            if(isVisited[i])continue;
            int n=bfs(i,a,b);
            bfsResult.push(n);
        }
        int big=bfsResult.top();
        bfsResult.pop();
        int small=bfsResult.top();
        q.push(big-small);
    }
    return q.top();;
}