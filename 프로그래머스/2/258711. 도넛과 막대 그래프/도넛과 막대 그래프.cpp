#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

bool isExist[1000005];
int indegrees[1000005];
int outdegrees[1000005];
vector<int> vec[1000005];

bool visited[1000005];

int doughnut,stick,eight;

void bfs(int start){
    queue<int> q;
    visited[start]=true;
    
    q.push(start);
    bool flag=true;
    while(!q.empty()&&flag){
        int curVertex=q.front();
        q.pop();

        if(outdegrees[curVertex]==0){
            stick++;
            return;
        }
        if(outdegrees[curVertex]==2){
            eight++;
            return;
        }
        
        for(int i=0;i<vec[curVertex].size();i++){
            int nxtVertex=vec[curVertex][i];
            if(visited[nxtVertex]){
                flag=false;
                break;
            }
            visited[nxtVertex]=true;
            q.push(nxtVertex);
        }
    }
    doughnut++;
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    for(auto k:edges){
        isExist[k[0]]=true;
        isExist[k[1]]=true;
        
        outdegrees[k[0]]++;
        indegrees[k[1]]++;
        vec[k[0]].push_back(k[1]);
    }
    
    //정점 찾기(들어오는거 없고 나가는거 많은)
    priority_queue <pair<int,int>> cand;
    for(int i=1;i<1000005;i++){
        if(!isExist[i])continue;
        if(indegrees[i]==0)cand.push({outdegrees[i],i}); // 나가는 개수, 정점번호
    }
    
    int mainVertex = cand.top().second;
    for(int i=0;i<vec[mainVertex].size();i++){
        int tmpVertex=vec[mainVertex][i];
        bfs(tmpVertex);
    }
    
    answer.push_back(mainVertex);
    answer.push_back(doughnut);
    answer.push_back(stick);
    answer.push_back(eight);
    
    return answer;
}