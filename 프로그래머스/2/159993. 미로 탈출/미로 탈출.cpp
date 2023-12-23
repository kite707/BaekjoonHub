#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4]={1,0,-1,0};
int width, height;
int lx,ly,ex,ey,sx,sy;

bool isValid(int x, int y){
    return (x>0&&x<=width&&y>0&&y<=height);
}

int bfs(int x,int y,int endX, int endY,vector<string> maps){
    //cout<<"endX, endY "<<endX<<" "<<endY<<endl;
    int checker[101][101] = {-1,};
    for(int i=0;i<101;i++){
        fill(&checker[i][0],&checker[i][0]+101,-1);
    }
    checker[y][x]=0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        int curCost = checker[curY][curX];
        //cout<<"curX, curY, curCost is "<<curX<<" "<<curY<<" "<<curCost<<endl;
        q.pop();
        if(curX==endX&&curY==endY){
            return curCost;
        }
        
        for(int i=0;i<4;i++){
            int nextX = curX+dx[i];
            int nextY = curY+dy[i];
            //  cout<<"nextX nextY is "<<nextX<<" "<<nextY<<" "<<endl;
            // cout<<isValid(nextX,nextY)<<endl;
            // cout<<checker[nextY][nextX]<<endl;
            // //cout<<(maps[nextY-1][nextX-1]!='X')<<endl;
            if(isValid(nextX,nextY)&&checker[nextY][nextX]==-1&&maps[nextY-1][nextX-1]!='X'){
                q.push({nextX,nextY});
                checker[nextY][nextX] = curCost+1;
            }
        }
    }
    return -1;
    
}

int solution(vector<string> maps) {
   
    height = maps.size();
    width = maps[0].length();
    //cout<<height<<" "<<width<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(maps[i][j]=='L'){
                lx = j+1;
                ly = i+1;
            }
            if(maps[i][j]=='E'){
                ex=j+1;
                ey=i+1;
            }
            if(maps[i][j]=='S'){
                sx=j+1;
                sy=i+1;
            }
        }
    }
   int lCost= bfs(sx,sy,lx,ly,maps);
    if(lCost == -1){
        //cout<<"lCost is "<<lCost<<endl;
        return -1;
    }
    int sCost = bfs(lx,ly,ex,ey,maps);
    if(sCost == -1){
        //cout<<"sCost is "<<sCost<<endl;
        return -1;
    }
    return lCost + sCost;
}