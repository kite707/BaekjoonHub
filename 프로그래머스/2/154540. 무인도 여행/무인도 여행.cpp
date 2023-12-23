#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool checker[101][101];
int width,height;

bool isValid(int x, int y){
    return(x>0&&x<=width&&y>0&&y<=height);
}

int bfs(int x,int y,vector<string> maps){
    int totalCost = maps[y-1][x-1]-'0';
    checker[y][x]=1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        //cout<<"curX curY is "<<curX<<" "<<curY<<endl;
        
        for(int i = 0; i < 4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(isValid(nextX,nextY)&&checker[nextY][nextX]==0&&maps[nextY-1][nextX-1]!='X'){
                totalCost+=maps[nextY-1][nextX-1]-'0';
                checker[nextY][nextX]=1;
                q.push({nextX,nextY});
            }
        }
        
    }
    return totalCost;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    width = maps[0].length();
    height = maps.size();
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(maps[i][j]!='X'&&checker[i+1][j+1]==0){
                int cost = bfs(j+1,i+1,maps);
                answer.push_back(cost);
                
            }
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}