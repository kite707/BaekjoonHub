#include <iostream>
#include <queue>
using namespace std;
char arr[8][8];
int watched[8][8];

int height, width;
int cctv;
priority_queue<int,vector<int>,greater<int>> q;
queue<pair<int,int>> cctv_location;
int cctv_x[8];
int cctv_y[8];
void printer(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<watched[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//상,하,좌,우 수행 함수
void right(int x, int y){
    for(int i=x;i<width;i++){
        if(arr[y][i]=='6')break;
        if(arr[y][i]!='0')continue;
        watched[y][i]++;
    }
}

void left(int x, int y){
    for(int i=x;i>=0;i--){
        if(arr[y][i]=='6')break;
        if(arr[y][i]!='0')continue;
        watched[y][i]++;
    }
}

void up(int x,int y){
    for(int i=y;i<height;i++){
        if(arr[i][x]=='6')break;
        if(arr[i][x]!='0')continue;
        watched[i][x]++;
    }
}

void down(int x,int y){
    for(int i=y;i>=0;i--){
        if(arr[i][x]=='6')break;
        if(arr[i][x]!='0')continue;
        watched[i][x]++;
    }
}

//상,하,좌,우 복구 함수
void back_right(int x, int y){
    for(int i=x;i<width;i++){
        if(arr[y][i]=='6')break;
        if(watched[y][i]==0)continue;
        watched[y][i]--;
    }
}

void back_left(int x, int y){
    for(int i=x;i>=0;i--){
        if(arr[y][i]=='6')break;
        if(watched[y][i]==0)continue;
        watched[y][i]--;
    }
}

void back_up(int x,int y){
    for(int i=y;i<height;i++){
        if(arr[i][x]=='6')break;
        if(watched[i][x]==0)continue;
        watched[i][x]--;
    }
}

void back_down(int x,int y){
    for(int i=y;i>=0;i--){
        if(arr[i][x]=='6')break;
        if(watched[i][x]==0)continue;
        watched[i][x]--;
    }
}

void count(){
//    printer();
//    cout<<"\n";
    int sum = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(arr[i][j]!='0') continue;
            if(watched[i][j]==0)sum++;
        }
    }
    q.push(sum);
}

void solution(int depth){
    if(depth==cctv){count();return;}
    int x=cctv_x[depth];
    int y=cctv_y[depth];
    if(arr[y][x]=='1'){
        right(x,y);
        solution(depth+1);
        back_right(x,y);
        left(x,y);
        solution(depth+1);
        back_left(x,y);
        up(x,y);
        solution(depth+1);
        back_up(x,y);
        down(x,y);
        solution(depth+1);
        back_down(x,y);
    }
    else if(arr[y][x]=='2'){
        right(x,y);
        left(x,y);
        solution(depth+1);
        back_right(x,y);
        back_left(x,y);
        up(x,y);
        down(x,y);
        solution(depth+1);
        back_up(x,y);
        back_down(x,y);
    }
    else if(arr[y][x]=='3'){
        right(x,y);
        up(x,y);
        solution(depth+1);
        back_up(x,y);

        down(x,y);
        solution(depth+1);
        back_right(x,y);

        left(x,y);
        solution(depth+1);
        back_down(x,y);

        up(x,y);
        solution(depth+1);
        back_left(x,y);
        back_up(x,y);
    }
    else if(arr[y][x]=='4'){
        up(x,y);
        right(x,y);
        left(x,y);
        solution(depth+1);
        back_left(x,y);

        down(x,y);
        solution(depth+1);
        back_up(x,y);

        left(x,y);
        solution(depth+1);

        back_right(x,y);
        up(x,y);
        solution(depth+1);
        back_up(x,y);
        back_left(x,y);
        back_down(x,y);
    }
    else if(arr[y][x]=='5'){
        up(x,y);
        down(x,y);
        right(x,y);
        left(x,y);
        solution(depth+1);
        back_up(x,y);
        back_left(x,y);
        back_down(x,y);
        back_right(x,y);
    }

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>height>>width;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>arr[i][j];
            if(arr[i][j]!='0'&&arr[i][j]!='6'){
                cctv_x[cctv]=j;
                cctv_y[cctv]=i;
                cctv++;
            }
        }
    }
    solution(0);
    cout<<q.top();

}