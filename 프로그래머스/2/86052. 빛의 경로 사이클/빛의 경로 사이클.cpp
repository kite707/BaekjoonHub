#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[501][501][4]; //상 우 하 좌

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int setDirection(int curDirection, char dir){
    if(dir=='S')return curDirection;
    if(dir=='R')return (curDirection+1)%4;
    return curDirection-1<0?3:curDirection-1;
}



int light(int y, int x,int curDirection, vector<string> grid){
    int len = 0;
    
    int dir=curDirection;
    int curX=x;
    int curY=y;
    while(true){
        if(arr[curY][curX][dir]){
            //cout<<curY<<" "<<curX<<" "<<dir<<"에서 break\n";
            break;
        }
        //cout<<"curY curX direction is "<<curY<<" "<<curX<<" "<<dir<<endl;
        arr[curY][curX][dir]=true;
        len++;
        
        int nxtY=curY+dy[dir];
        int nxtX=curX+dx[dir];
        //cout<<"[bf]nxtY nxtX is "<<nxtY<<" "<<nxtX<<endl;
        
        if(nxtY<0)nxtY=grid.size()-1;
        if(nxtY>=grid.size())nxtY=0;
        if(nxtX<0)nxtX=grid[0].size()-1;
        if(nxtX>=grid[0].size())nxtX=0;
        //cout<<"[aft]nxtY nxtX dir is "<<nxtY<<" "<<nxtX<<" "<<dir<<endl;

        curX=nxtX;
        curY=nxtY;
        char curChar=grid[curY][curX];
        dir=setDirection(dir,curChar);
    }
    return len;
    
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int width=grid[0].size();
    int length=grid.size();
    //cout<<"width length: "<<width<<" "<<length<<endl;
    
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            for(int k=0;k<4;k++){
                if(!arr[i][j][k]){
                    //순회하고 길이 answer에 넣기
                    answer.push_back(light(i,j,k,grid));
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}