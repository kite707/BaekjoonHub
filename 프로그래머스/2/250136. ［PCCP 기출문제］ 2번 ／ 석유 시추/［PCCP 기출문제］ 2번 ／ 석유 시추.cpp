#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int arr[500];

void bfs(vector<vector<int>> &land, int y, int x){
    int total=1;
    land[y][x]=0;
    queue<pair<int,int>> q;

    int minX=x;
    int maxX=x;

    q.push({y,x});
    while(!q.empty()){
        int curY=q.front().first;
        int curX=q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
        int nxtY=curY+dy[i];
        int nxtX=curX+dx[i];

        if(nxtY<0||nxtX<0||nxtY>=land.size()||nxtX>=land[i].size()) continue;
        if(land[nxtY][nxtX]==0) continue;
        land[nxtY][nxtX]=0;
        total++;
        q.push({nxtY,nxtX});
        minX=min(nxtX,minX);
        maxX=max(nxtX,maxX);
        }
    }
    for(int i=minX;i<=maxX;i++){
        arr[i]+=total;
    }
}


int solution(vector<vector<int>> land) {
    int answer = 0;
    priority_queue<int> q;
   
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land[0].size();j++){
            if(land[i][j]==1){
                bfs(land,i,j);
            }
        }
    }
    return *max_element(&arr[0],&arr[0]+500);
}