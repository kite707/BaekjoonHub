#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(),tangerine.end());
    int tmp = tangerine[0];
    int size = 0;
    priority_queue<int> q;
    for(int i=0;i<tangerine.size();i++){
        if(tmp!=tangerine[i]){
            q.push(size);
            tmp=tangerine[i];
            size=0;
        }
        size++;
        if(i==tangerine.size()-1){
            q.push(size);
        }
    }
    while(!q.empty()&&k>0){
        k-=q.top();
        q.pop();
        answer++;
    }
    
    return answer;
}