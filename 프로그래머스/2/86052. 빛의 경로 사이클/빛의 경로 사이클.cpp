#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//오 아 왼 위
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int visited[501][501][4]; //방문여부

int changeRight(int dir){
    return (dir+1)%4;
}
int changeLeft(int dir){
    return (dir==0)?3:dir-1;
}

int getCycle(int y,int x, int dir,vector<string> grid){
    int cnt=0;
    //cout<<"y x dir is : "<<y<<" "<<x<<" "<<dir<<endl;
    
    int curY=y;
    int curX=x;
    int curDir=dir;
    int num=grid[0].size()-1;
    while(!visited[curY][curX][curDir]){
        cnt++;
        visited[curY][curX][curDir]=true;
        //cout<<"curdir dy dx is "<<curDir<<" "<<dy[curDir]<<" "<<dx[curDir]<<endl;
        int nxtY=curY+dy[curDir];
        int nxtX=curX+dx[curDir];
        //cout<<"원래 nxt좌표들 "<<nxtY<<"  "<<nxtX<<endl;
        //cout<<grid[0].size()<<endl;
        
        if(nxtY<0)nxtY=grid.size()-1;
        if(nxtY>grid.size()-1)nxtY=0;
        if(nxtX>num)nxtX=0;
        if(nxtX<0)nxtX=grid[0].size()-1;
        
        if(grid[nxtY][nxtX]=='R'){
            curDir=changeRight(curDir);
            //cout<<"오른쪽 회전"<<endl;
            }
        if(grid[nxtY][nxtX]=='L'){
            curDir=changeLeft(curDir);
            //cout<<"왼쪽 회전"<<endl;
        }
        
        curY=nxtY;
        curX=nxtX;
        //cout<<"new cur y x dir is : "<<curY<<"  "<<curX<<"  "<<curDir<<endl;
        
    }
    //cout<<"cnt is "<<cnt<<endl;
    return cnt;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            for(int dir=0;dir<4;dir++){
                if(!visited[i][j][dir])answer.push_back(getCycle(i,j,dir,grid));
            }     
        }
    }
    sort(answer.begin(),answer.end());        
    return answer;
}