#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int board[101][101][101];
int dist[101][101][101];
int dx[6]={1,0,-1,0,0,0};
int dy[6] = {0,-1,0,1,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<tuple<int,int,int>> Q;
int M,N,H;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>M>>N>>H;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                int tmp;
                cin>>tmp;
                board[j][k][i] = tmp;
                if(tmp==1)Q.push({j,k,i});
                if(tmp==0)dist[j][k][i]=-1;
            }
        }
    }
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curY, curX, curZ) = cur;
        for(int i=0;i<6;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            int nz = curZ+dz[i];
            if(nx<1||ny<1||nx>M||ny>N||nz<1||nz>H)continue;
            if(dist[ny][nx][nz]>=0)continue;
            dist[ny][nx][nz] = dist[curY][curX][curZ]+1;
            Q.push({ny,nx,nz});
        }
    }
    int ans = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                if(dist[j][k][i]==-1){
                    cout<<-1<<"\n";
                    return 0;
                }
                ans = max(ans,dist[j][k][i]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;


}