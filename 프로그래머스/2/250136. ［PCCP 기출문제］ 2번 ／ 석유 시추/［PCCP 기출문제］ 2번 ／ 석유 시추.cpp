#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int fosil[501];

int bfs(int y, int x,vector<vector<int>> &land){
    int maxX=x;
    int minX=x;
    land[y][x]=0;
    int cnt=1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int curX=q.front().second;
        int curY=q.front().first;
        maxX=max(maxX,curX);
        minX=min(minX,curX);
        q.pop();
        for(int i=0;i<4;i++){
            int nxtX=curX+dx[i];
            int nxtY=curY+dy[i];
            if(nxtX<0||nxtY<0||nxtX>=land[0].size()||nxtY>=land.size())continue;
            if(land[nxtY][nxtX]==1){
                q.push({nxtY,nxtX});
                land[nxtY][nxtX]=0;
                cnt++;
            }
        }
    }
    //cout<<"min max의 값: "<<minX<<" "<<maxX<<endl;
    for(int i=minX;i<=maxX;i++){
        fosil[i]+=cnt;
    }
    return cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int width=land[0].size();
    priority_queue<int> q;
    q.push(0);
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land[0].size();j++){
            if(land[i][j]==1){
                bfs(i,j,land);
            }
        }
    }
    // cout<<endl;
    // for(int i=0;i<land[0].size();i++){
    //     cout<<fosil[i]<<" ";
    // }
    
    return *max_element(&fosil[0],&fosil[0]+land[0].size());
}