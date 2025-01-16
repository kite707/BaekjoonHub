#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(),targets.end());
    int curMin=targets[0][0];
    int curMax=targets[0][1];
    for(auto k:targets){
        if(k[0]>=curMax){
            curMin=k[0];
            curMax=k[1];
            answer++;
            continue;
        }
        curMin=max(curMin,k[0]);
        curMax=min(curMax,k[1]);
    }
    
    return answer;
}