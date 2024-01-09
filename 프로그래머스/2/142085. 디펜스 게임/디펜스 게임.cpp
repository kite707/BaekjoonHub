#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> q;
    for(int i = 1; i<=enemy.size();i++){
        int curCost=enemy[i-1];
        if(n>=curCost){
            n-=curCost;
            q.push(curCost);
            answer = i;
        }else if(k>0){
            if(!q.empty()&&q.top()>curCost){
                int maxCost = q.top();
                q.pop();
                k--;
                n+=maxCost;
                n-=curCost;
                q.push(curCost);
                answer = i;
            }else{
                k--;
                answer=i;
                continue;
            }
        }
        else{
            answer = i-1;
            break;
        }
    }
    return answer;
}