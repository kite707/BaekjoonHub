#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;


//m n =6 4
//picture [[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int bfs(int y, int x, vector<vector<int>> &pic){
    queue<pair<int, int>> q;
    int width=pic[0].size();
    int height=pic.size();
    int color=pic[y][x];
    pic[y][x]=0;
    int answer=1;
    q.push({y,x});
    while(!q.empty()){
        int curY=q.front().first;
        int curX=q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
            int nxtY=curY+dy[i];
            int nxtX=curX+dx[i];
            if(nxtY>=height||nxtY<0||nxtX>=width||nxtX<0)continue;
            if(pic[nxtY][nxtX]!=color||pic[nxtY][nxtX]==0)continue;
            pic[nxtY][nxtX]=0;
            answer++;
            q.push({nxtY,nxtX});

        }
    }
    return answer;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0;i<picture.size();i++){
        for(int j=0;j<picture[0].size();j++){
            if(picture[i][j]!=0){
                int num=bfs(i,j,picture);
                max_size_of_one_area=max(max_size_of_one_area,num);
                number_of_area++;
            }
        }
    }

    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}