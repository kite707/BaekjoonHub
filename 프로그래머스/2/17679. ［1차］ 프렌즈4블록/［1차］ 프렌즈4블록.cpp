#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[3]={0,1,1};
int dy[3]={1,1,0};

void fall(vector<string> &board){
    for(int i=board.size()-1;i>=0;i--){
        string garo=board[i];
        for(int j=0;j<garo.size();j++){
            if(board[i][j]=='1'){
                for(int curY=i;curY>=0;curY--){
                    if(board[curY][j]!='1'){
                        board[i][j]=board[curY][j];
                        board[curY][j]='1';
                        break;
                    }
                }
            }
        }
    }
}

int boom(vector<pair<int,int>> &vec, vector<string> &board){
    int cnt=0;
    for(int i=0;i<vec.size();i++){
        int y=vec[i].first;
        int x=vec[i].second;
        
        if(board[y][x]!='1'){
            board[y][x]='1';
            cnt++;
        }
        for(int j=0;j<3;j++){
            int nxtY=y+dy[j];
            int nxtX=x+dx[j];
            if(board[nxtY][nxtX]!='1'){
                board[nxtY][nxtX]='1';
                cnt++;
            }
        }
    }
    fall(board);
    return cnt;
}

bool checker(int y,int x, vector<string> &board){
    char curVal=board[y][x];
    for(int i=0;i<3;i++){
        int nxtY=y+dy[i];
        int nxtX=x+dx[i];
        if(curVal!=board[nxtY][nxtX])return false;
    }
    return true;
}

vector<pair<int,int>> getPoint(vector<string> &board){
    vector<pair<int,int>> vec;
    for(int i=0;i<board.size()-1;i++){
        for(int j=0;j<board[0].size()-1;j++){
            if(board[i][j]!='1'&&checker(i,j,board))vec.push_back({i,j});
        }
    }
    return vec;

}

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    vector<pair<int,int>> point;

    do{
        point=getPoint(board);
        if(point.empty())continue;
        answer+=boom(point,board);
    }while(!point.empty());

    return answer;
}