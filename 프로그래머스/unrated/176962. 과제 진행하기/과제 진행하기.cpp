#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
vector<string> solution(vector<vector<string>> plans) {
    
    vector<pair<int,int>> sortedPlans;
    
    for(int i=0;i<plans.size();i++){
        string curSubject=plans[i][0];
        string startTime=plans[i][1];
        string duration=plans[i][2];
        
        
        //시간 가공
        int time=(startTime[0]-'0')*10+startTime[1]-'0';
        int minuts=(startTime[3]-'0')*10+startTime[4]-'0';
        
        int timeNumber=time*60+minuts;
        sortedPlans.push_back(make_pair(timeNumber,i));
        
    }
    sort(sortedPlans.begin(),sortedPlans.end());
    stack<pair<string,int>> st;
    vector<string> answer;
    for(int i=0;i<sortedPlans.size()-1;i++){
        int curStartTime=sortedPlans[i].first;
        int curIdx=sortedPlans[i].second;
        int curDuration=stoi(plans[curIdx][2]);

        int nextStartTime=sortedPlans[i+1].first;
        int nextIdx=sortedPlans[i+1].second;
        
        int canUseTime=nextStartTime-curStartTime;
       // cout<<"i is"<<i<<" canUseTime is"<<canUseTime<<endl;
        bool flag=true;
        while(canUseTime>0&&flag){
            if(canUseTime>=curDuration){
            canUseTime-=curDuration;
                answer.push_back(plans[curIdx][0]);
                if(canUseTime==0) break;
        }else{
                curDuration-=canUseTime;
                st.push(make_pair(plans[curIdx][0],curDuration));
                plans[curIdx][2]=to_string(curDuration);
                canUseTime=0;break;
            }
            while(!st.empty()){
                string subjectName=st.top().first;
                int leftTime=st.top().second;
                st.pop();
                
                if(leftTime>canUseTime){
                    leftTime-=canUseTime;
                    st.push(make_pair(subjectName,leftTime));
                    canUseTime=0;
                    break;
                }else{
                    canUseTime-=leftTime;
                    answer.push_back(subjectName);
                }
            }
            flag=!st.empty();
        }
        
    }
    answer.push_back(plans[sortedPlans[sortedPlans.size()-1].second][0]);
    while(!st.empty()){
        answer.push_back(st.top().first);
        st.pop();
    }
    
    
    return answer;
}