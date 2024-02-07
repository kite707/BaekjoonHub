#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
char arr [101][101];
char arr2[101][101];

int dx[4] = {1,0,-1,0};
int dy [4] = {0,-1,0,1};

void bfs(int x, int y, char color){
    arr[y][x] = 'C';
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
     for(int i=0;i<4;i++){
         int nx = q.front().first+dx[i];
         int ny = q.front().second+dy[i];
         if(nx>n||nx<1||ny>n||ny<1)continue;
         if(arr[ny][nx]=='C') continue;
         if(arr[ny][nx]==color){
             arr[ny][nx]='C';
             q.push(make_pair(nx,ny));
         }
     }
     q.pop();
    }
}

void bfs2(int x, int y, char color){
    arr2[y][x] = 'C';
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        for(int i=0;i<4;i++){
            int nx = q.front().first+dx[i];
            int ny = q.front().second+dy[i];
            if(nx>n||nx<1||ny>n||ny<1)continue;
            if(arr2[ny][nx]=='C') continue;
            if(color=='B'&&arr2[ny][nx]=='B'){
                arr2[ny][nx] = 'C';
                q.push(make_pair(nx, ny));
            }
            if((color =='R'||color=='G')&&(arr2[ny][nx]=='R'||arr2[ny][nx]=='G')) {
                arr2[ny][nx] = 'C';
                q.push(make_pair(nx, ny));
            }
        }
        q.pop();
    }
}
int main(){
    cin>>n;
    string s;
    int ans1 = 0;
    int ans2 = 0;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=n;j++){
            arr[i][j]=s[j-1];
            arr2[i][j]=s[j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]!='C'){
                bfs(j,i,arr[i][j]);
                ans1++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr2[i][j]!='C'){
                bfs2(j,i,arr2[i][j]);
                ans2++;
            }
        }
    }
    cout<<ans1<<" "<<ans2;


}