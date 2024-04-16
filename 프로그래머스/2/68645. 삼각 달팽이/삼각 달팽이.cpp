#include <string>
#include <vector>
#include <iostream>
using namespace std;


int arr[1001][1001];
int width;
int nxtY=1;
int nxtX=1;
int nxtNum=1;
void down(int curY,int curX, int curNum){
   while(arr[curY][curX]==0&&curY<=width){
       arr[curY][curX]=curNum;
       curNum++;
       curY++;
   }
    nxtY=curY-1;
    nxtX=curX+1;
    nxtNum=curNum;
}

void right(int curY,int curX,int curNum){
    while(arr[curY][curX]==0&&curX<=width){
       arr[curY][curX]=curNum;
       curNum++;
       curX++;
   }
    nxtY=curY-1;
    nxtX=curX-2;
    nxtNum=curNum;
}
void up(int curY,int curX,int curNum){
    while(arr[curY][curX]==0){
        arr[curY][curX]=curNum;
        curNum++;
        curX--;
        curY--;
    }
    nxtY=curY+2;
    nxtX=curX+1;
    nxtNum=curNum;
}

vector<int> solution(int n) {
    vector<int> answer;
    width=n;
    int curNum=1;
    int nNum=0;
    while(arr[nxtY][nxtX]==0){
        down(nxtY,nxtX,nxtNum);
        if(arr[nxtY][nxtX]!=0)break;
        right(nxtY,nxtX,nxtNum);
        if(arr[nxtY][nxtX]!=0)break;
        up(nxtY,nxtX,nxtNum);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)answer.push_back(arr[i][j]);
    }
    return answer;
}