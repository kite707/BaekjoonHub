#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }return a[0]>b[0];
}

bool cmp2(int a, int b){
    return a>b;
}
int solution(vector<vector<int>> scores) {
    int answer = 0;
    int front=scores[0][0];
    int second=scores[0][1];
    int total=front+second;
    sort(scores.begin(),scores.end(),cmp);
    int maxV=scores[0][1];
    vector<int> v;
    
    for(int i=0;i<scores.size();i++){
        maxV=max(scores[i][1],maxV);
        if(maxV>scores[i][1]){
            if(scores[i][0]==front&&scores[i][1]==second){
                return -1;
            }
            continue;
        }
        v.push_back((scores[i][0]+scores[i][1])*(-1));
    }
    sort(v.begin(),v.end());
    int idx=lower_bound(v.begin(),v.end(),total*(-1))-v.begin()+1;
    return idx;
}