#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
        int answer = 0;
    vector<vector<int>> sorted_targets=targets;
    sort(sorted_targets.begin(),sorted_targets.end(),compare);
    
    vector<int> saver;
    
    int start = sorted_targets[0][0];
    int end=sorted_targets[0][1]-1;
    for(int i=1;i<sorted_targets.size();i++){
        int cur_start=sorted_targets[i][0];
        int cur_end=sorted_targets[i][1]-1;

        if(end<cur_start){
            start=cur_start;
            end=cur_end;
            answer++;
        }else{
            start=max(start,cur_start);
            end=min(end,cur_end);
        }
    }
    return answer+1;
}