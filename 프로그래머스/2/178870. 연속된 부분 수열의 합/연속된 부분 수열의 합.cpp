#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int curSum=0;
    queue<int> q;
    
    int st=0;
    int en=10000005;
    
    for(int i=sequence.size()-1;i>=0;i--){
        int curNum=sequence[i];
        q.push(i);
        curSum+=curNum;
        
        while(curSum>k){
            curSum-=sequence[q.front()];
            q.pop();
        }
        
        if(curSum==k&&(q.front()-i)<=(en-st)){
            st=i;
            en=q.front();
        }
        
    }
    answer.push_back(st);
    answer.push_back(en);
    
    return answer;
}