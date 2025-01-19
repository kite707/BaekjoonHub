#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int village[51][51];
vector<pair<int,int>> graph[51];
void bfs(int start){
    queue<pair<int,int>> q;
    q.push({start,0});
    while(!q.empty()){
        int cur = q.front().first;
        int curCost=q.front().second;
        q.pop();
        
        for(int i=0;i<graph[cur].size();i++){
            int nxt=graph[cur][i].first;
            int nxtCost=graph[cur][i].second+curCost;
            if(village[start][nxt]<=nxtCost)continue;
            village[start][nxt]=nxtCost;
            q.push({nxt,nxtCost});
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    int max=INT_MAX;
    for(int i=0;i<=N;i++){
        fill(&village[i][0],&village[i][0]+51,max);
    }
    for(auto k: road){
        int e1=k[0];
        int e2=k[1];
        int cost=k[2];
        graph[e1].push_back({e2,cost});
        graph[e2].push_back({e1,cost});
    }
    bfs(1);
    village[1][1]=0;
    for(int i=1;i<=N;i++){
        if(village[1][i]<=K)answer++;
    }


    return answer;
}