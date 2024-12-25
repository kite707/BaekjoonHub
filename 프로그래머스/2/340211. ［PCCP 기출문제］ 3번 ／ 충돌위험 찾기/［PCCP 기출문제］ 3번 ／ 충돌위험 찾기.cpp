#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int board[101][101];

pair<int,int> curLoc[101]; //로봇들의 현재 좌표 

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int robotCnt=routes.size();    
    int time=0;
    
    while(robotCnt>0){
        //cout<<time<<"초 경과\n";
    // int k=6;
    // while(k--){
        for(int i=0;i<routes.size();i++){
            if(routes[i].empty())continue;
            int curDest=routes[i][0];
            int curDestR=points[curDest-1][0];
            int curDestC=points[curDest-1][1];
            //i번째 로봇이 아직 배치되지 않았으면 배치
            if(curLoc[i].first==0){
                curLoc[i].first=curDestR; //r (먼저 변함)
                curLoc[i].second=curDestC; //c
                routes[i].erase(routes[i].begin(),routes[i].begin()+1);
                
                board[curLoc[i].first][curLoc[i].second]++;
                if(board[curLoc[i].first][curLoc[i].second]==2){
                answer++; //충돌 발생
                //cout<<"충돌\n";
            }
                continue;
            }
            
            //i번째 로봇 이동
            if(curLoc[i].first!=curDestR){
                curDestR>curLoc[i].first?curLoc[i].first++:curLoc[i].first--;
            }else if(curLoc[i].second!=curDestC){
                curDestC>curLoc[i].second?curLoc[i].second++:curLoc[i].second--;
            }
            //cout<<"이동 후 좌표: "<<curLoc[i].first<<" "<<curLoc[i].second<<endl;
            board[curLoc[i].first][curLoc[i].second]++;
            if(board[curLoc[i].first][curLoc[i].second]==2){
                answer++; //충돌 발생
                //cout<<"충돌\n";
            }
            
            
            //목적지에 도착했다면 routes에서 제거
            if(curLoc[i].first==curDestR&&curLoc[i].second==curDestC){
                routes[i].erase(routes[i].begin(),routes[i].begin()+1);
                if(routes[i].size()==0){ //완전히 목적지 도착
                    robotCnt--;
                    // cout<<"목적지 도착 robot count is "<<robotCnt<<endl;
                    // cout<<"answer is "<<answer<<endl;
                    
                    // //debug
                    // cout<<"routes is\n";
                    // for(int i=0;i<routes.size();i++){
                    //     for(int j=0;j<routes[i].size();j++){
                    //         cout<<routes[i][j]<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                    // cout<<"route end\n";
                }   
            }
            
        }
        // for(int i=0;i<101;i++){
        //     for(int j=0;j<101;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        //board 초기화
        for(int i=0;i<101;i++){
            fill(&board[i][0],&board[i][0]+101,0);
        }
        time++;
    }
    return answer;
}