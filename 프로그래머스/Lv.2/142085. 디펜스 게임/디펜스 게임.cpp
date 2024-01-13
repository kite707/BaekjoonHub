#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    if(k>=enemy.size()){
        return enemy.size();
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i =0;i<enemy.size();i++){
        q.push(enemy[i]);
        if(q.size()>k){
            int last = q.top();
            q.pop();
            if(last>n){
                return i;
            }
            n-=last;
        }
    }
    return enemy.size();
}