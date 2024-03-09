#include <iostream>
#include <queue>
#define wall 5000
using namespace std;

int R,C;
string board[1001];
int jiMaze[1001][1001];
int fireMaze[1001][1001];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C;
    //y, x로 저장
    queue<pair<int,int>> qjihun;
    queue<pair<int,int>> qfire;
    for(int i=1;i<=R;i++){
        string s;
        cin>>s;
        board[i]=s;
        for(int j=0;j<C;j++){
            if(s[j]=='J'){
                qjihun.push({i,j+1});
                jiMaze[i][j+1]=1;
            }if(s[j]=='F'){
                qfire.push({i,j+1});
                fireMaze[i][j+1]=1;
            }
        }
    }

    //불 bfs
    while(!qfire.empty()){
        int curY=qfire.front().first;
        int curX=qfire.front().second;
        qfire.pop();
        for(int i=0;i<4;i++){
            int nextY=curY+dy[i];
            int nextX=curX+dx[i];
            if(nextY<1||nextX<1||nextY>R||nextX>C)continue;
            if(board[nextY][nextX-1]=='#'||fireMaze[nextY][nextX]>0)continue;
            fireMaze[nextY][nextX]=fireMaze[curY][curX]+1;
            qfire.push({nextY,nextX});
        }
    }

    //지훈 bfs
    while(!qjihun.empty()){
        int curY = qjihun.front().first;
        int curX = qjihun.front().second;
        qjihun.pop();
        for(int i=0;i<4;i++){
            int nextY=curY+dy[i];
            int nextX=curX+dx[i];
            if(nextY<1||nextX<1||nextY>R||nextX>C){
                cout<<jiMaze[curY][curX];
                return 0;
            }
            if(board[nextY][nextX-1]=='#'||jiMaze[nextY][nextX]>0)continue;
            if(fireMaze[nextY][nextX]!=0&&fireMaze[nextY][nextX]<=jiMaze[curY][curX]+1)continue;
            jiMaze[nextY][nextX]=jiMaze[curY][curX]+1;
            qjihun.push({nextY,nextX});
        }
    }
    cout<<"IMPOSSIBLE";


}

