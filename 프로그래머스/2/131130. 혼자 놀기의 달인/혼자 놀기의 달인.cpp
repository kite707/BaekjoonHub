#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool cardChecker[101];
vector<int> graph[101];
int bfs(int start){
    int cnt = 1;
    cardChecker[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curNum = q.front();
        q.pop();
        for(int i=0;i<graph[curNum].size();i++){
            int next = graph[curNum][i];
            if(!cardChecker[next]){
                q.push(next);
                cnt++;
                cardChecker[next]=true;
            }
        }
    }
    return cnt;
}

int solution(vector<int> cards) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(int i=0;i<cards.size();i++){
        int curCard = cards[i];
        graph[curCard].push_back(cards[curCard-1]);
    }
    for(int i=0;i<cards.size();i++){
         int curCard = cards[i];
        if(!cardChecker[curCard]){
            pq.push(bfs(curCard));
        }
    }
    if(pq.size()==1){
        return 0;
    }else{
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        answer = num1*num2;
    }
    return answer;
}