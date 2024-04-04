#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool isChecked[8];
int dungeonSize=0;
priority_queue<int> ans;

void backTracking(int curK,int curdepth,vector<vector<int>> &dungeon){
    //cout<<curK<<"  "<<curdepth<<"  "<<endl;
    if(curdepth==dungeonSize){
        ans.push(dungeonSize);
        return;
    }
    for(int i=0;i<dungeonSize;i++){
        if(isChecked[i]==false&&dungeon[i][0]<=curK){
            isChecked[i]=true;
            backTracking(curK-dungeon[i][1],curdepth+1,dungeon);
            isChecked[i]=false;
        }
    }
    ans.push(curdepth);
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    ans.push(0);
    dungeonSize=dungeons.size();
    backTracking(k,0,dungeons);
    return ans.top();
}