#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int fosil[501];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(int y, int x, vector<vector<int>> &land){
    land[y][x]=0;
    int ans=1;
    queue<pair<int,int>> q;
    q.push({y,x});
    int maxX=x;
    int minX=x;
    while(!q.empty()){
        int curX=q.front().second;
        int curY=q.front().first;
        q.pop();
        maxX=max(maxX,curX);
        minX=min(minX,curX);
        for(int i=0;i<4;i++){
            int nxtX=curX+dx[i];
            int nxtY=curY+dy[i];
            if(nxtX<0||nxtY<0||nxtX>=land[0].size()||nxtY>=land.size())continue;
            if(land[nxtY][nxtX]==0)continue;
            ans++;
            land[nxtY][nxtX]=0;
            q.push({nxtY,nxtX});
        }
    }
    for(int i=minX;i<=maxX;i++){
        fosil[i]+=ans;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land[0].size();j++){
            if(land[i][j]==1){
                bfs(i,j,land);
            }
        }
    }
    return *max_element(&fosil[0],&fosil[0]+land[0].size());
}