#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    vector<tuple<int,int,string>> newPlans;
    
    for(int i=0;i<plans.size();i++){
        string strTime=plans[i][1];
        istringstream ss(strTime);
        int hour, minute;
        char colon;
        ss>>hour>>colon>>minute;
        int time=60*hour+minute;
        tuple<int,int,string> tmp={time,stoi(plans[i][2]),plans[i][0]};

        newPlans.push_back(tmp);
    }

    sort(newPlans.begin(),newPlans.end());

    stack<pair<int,string>> leftHomework;
   
    for(int i=0;i<newPlans.size();i++){
        int curTime=get<0>(newPlans[i]);
        int nxtStartTime;
        (i!=newPlans.size()-1)?nxtStartTime=get<0>(newPlans[i+1]):nxtStartTime=100000000;

        int betweenTime=nxtStartTime-curTime;
        int curCost=get<1>(newPlans[i]);

        if(curCost<=betweenTime){
            answer.push_back(get<2>(newPlans[i]));
            curTime+=curCost;
            //만약 하다 남은과제있으면 진행
            while(!leftHomework.empty()&&curTime<nxtStartTime){
                int leftHomeworkTime=leftHomework.top().first;
                betweenTime=nxtStartTime-curTime;
                string subject=leftHomework.top().second;
                if(leftHomeworkTime<=betweenTime){
                    leftHomework.pop();
                    answer.push_back(subject);
                    curTime+=leftHomeworkTime;
                }else{
                    int newLeftTime=leftHomeworkTime-betweenTime;
                    leftHomework.pop();
                    leftHomework.push({newLeftTime,subject});
                    curTime=nxtStartTime;
                }
            }
            
        }
        else{
            int leftTime=curCost-betweenTime;
            leftHomework.push({leftTime,get<2>(newPlans[i])});
            curTime=nxtStartTime;
        }

    }
    while(!leftHomework.empty()){
        answer.push_back(leftHomework.top().second);
        leftHomework.pop();
    }

    return answer;
}