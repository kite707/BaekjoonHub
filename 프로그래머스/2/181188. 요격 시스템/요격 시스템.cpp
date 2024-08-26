#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[1]!=b[1])return a[1]>b[1];
    return a[0]<b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),cmp);
    int curMin=targets[0][0];
    
    for(int i=0;i<targets.size();i++){
        
        if(curMin>=targets[i][1]){
            answer++;
            curMin=targets[i][0];
            //cout<<"curMin is "<<curMin<<endl;
        }
        curMin=max(targets[i][0],curMin);
        //cout<<targets[i][0]<<" "<<targets[i][1]<<endl;
        
        
    }
    
    return ++answer;
}