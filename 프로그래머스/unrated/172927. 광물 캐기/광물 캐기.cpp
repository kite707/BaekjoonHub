#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string mine[3]={"diamond","iron","stone"};
int costPlan[3][3]={{1,1,1},{5,1,1},{25,5,1}};

int mintToCost(string mine){
    if(mine=="diamond")return 0;
    if(mine=="iron") return 1;
    return 2;
}

int solution(vector<int> picks, vector<string> minerals) {
    queue<string> tools;
    int toolSum=0;
    
    for(int i=0;i<=2;i++){
        int size=picks[i];
        toolSum+=size;
        for(int j=0;j<size;j++){
         tools.push(mine[i]);   
        }
    }
    
    int answer = 0;
    int divide=minerals.size()/5;
    int remain=minerals.size()%5;
    
    //초과한 값 지우기
    int over=divide;
    if(remain!=0){
        over++;
    }
    if(over>toolSum){
        minerals.erase(minerals.begin()+toolSum*5,minerals.end());
         divide=minerals.size()/5;
        remain=minerals.size()%5;
    }
    
    priority_queue<pair<int,int>> saveSum;
    
    for(int i=0;i<divide;i++){
        int startIdx=i*5;
        int sum=0;
        for(int j=0;j<=4;j++){
            string curMineral=minerals[startIdx+j];
            int cost=0;
            if(curMineral=="diamond")cost=25;
            else if(curMineral=="iron")cost=5;
            else cost=1;
            sum+=cost;
        }
        saveSum.push(make_pair(sum,startIdx));   
    }
    int sum=0;
    for(int i=0;i<remain;i++){
        int curIdx=divide*5+i;
        int cost=0;
        
        string curMineral=minerals[curIdx];

            if(curMineral=="diamond")cost=25;
            else if(curMineral=="iron")cost=5;
            else cost=1;
        sum+=cost;
    }
    saveSum.push(make_pair(sum,divide*5));
    
    while(!saveSum.empty()&&!tools.empty()){
        int startIdx=saveSum.top().second;
        string curTool=tools.front();
        
        int toolIdx=mintToCost(curTool);
        if(startIdx==divide*5){
             for(int i=0;i<remain;i++){
        int curIdx=startIdx+i;
        
        string curMinerals=minerals[curIdx];
        int mineralIdx=mintToCost(curMinerals);
        answer+=costPlan[toolIdx][mineralIdx];
    }
        }else{
          for(int i=0;i<5;i++){
            int curIdx=startIdx+i;
            string curMinerals=minerals[curIdx];
            int mineralIdx=mintToCost(curMinerals);

            answer+=costPlan[toolIdx][mineralIdx];
        }  
        }
        tools.pop();
        saveSum.pop();
    }
    return answer;
}