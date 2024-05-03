#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }return a[0]>b[0];
}
int solution(vector<vector<int>> scores) {
    int answer = 0;
    sort(scores.begin(),scores.end(),cmp);
    int maxV=scores[0][1];
    for(int i=0;i<scores.size();i++){
        maxV=max(scores[i][1],maxV);
        if(maxV>scores[i][1]){
            continue;
        }
        cout<<scores[i][0]<<" "<<scores[i][1]<<endl;
    }
    return answer;
}