#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int checker[1000001];

void checkAndRenew(int next,int curCost){
    
}

int bfs(int start, int end,int n){
    checker[start]=1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curPoint = q.front();
        int curCost= checker[curPoint];
        q.pop();
        
        if(curPoint == end){
            return curCost-1;
        }
        
        int next1 = curPoint+n;
        int next2 = curPoint*2;
        int next3 = curPoint*3;
        if(checker[next1]==0&&next1>=1&&next1<=1000000){
            checker[next1] = curCost+1;
            q.push(next1);
        }
        if(checker[next2]==0&&next2>=1&&next2<=1000000){
            checker[next2] = curCost+1;
            q.push(next2);
        }
        if(checker[next3]==0&&next3>=1&&next3<=1000000){
            checker[next3] = curCost+1;
            q.push(next3);
        }
 
    }
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    if(x>y){
        return -1;
    }
    if(x==y){
        return 0;
    }
    answer = bfs(x,y,n);
    return answer;
    
}