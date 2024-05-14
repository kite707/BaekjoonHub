#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(vector<int> a, vector<int> b){
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]==b[i])continue;
        return a[i]>b[i];
    }return true;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<vector<int>> multiAns;
    
    for(int z=0;z<1024;z++){
        vector<int> tmp(11,0);
        int arrow=n;
        int score=0;
        for(int i=0;i<10;i++){
            if(z&(1<<i)){
                //cout<<10-i<<" ";
                score+=(10-i);
                arrow-=(info[i]+1);
                tmp[i]+=(info[i]+1);
            }else{
                if(info[i]!=0){
                    score-=(10-i);
                }
            }
        }
        if(score<=0||arrow<0){
            continue;
        }
        if(arrow>0)tmp[10]+=arrow;
        tmp.push_back(score);
        multiAns.push_back(tmp);
        sort(multiAns.begin(),multiAns.end(),comp);
    }
    if(multiAns.empty()){
        answer.push_back(-1);
        return answer;
    }
    answer=multiAns[0];
    answer.pop_back();
    
    return answer;
}