#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    int maxX=INT32_MIN;
    int maxY=INT32_MIN;
    int minX=INT32_MAX;
    int minY=INT32_MAX;
    vector<pair<int,int>> v; //x y 저장
    
    for(int i=0;i<line.size()-1;i++){
        for(int j=i+1;j<line.size();j++){
            //교점 구하기
            int down =line[i][0]*line[j][1]-line[i][1]*line[j][0];
            if(down!=0){
               long long x=(long long)line[i][1]*line[j][2]-(long long)line[i][2]*line[j][1];
            long long y=(long long)line[i][2]*line[j][0]-(long long)line[i][0]*line[j][2];
                //cout<<x<<"  "<<y<<endl;
            if(x%down==0&&y%down==0){
                v.push_back({x/down,y/down});
            } 
            }
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto xx:v){
        maxX=max(maxX,xx.first);
        maxY=max(maxY,xx.second);
        minX=min(minX,xx.first);
        minY=min(minY,xx.second);
    }
    int n=maxY-minY;
    int m=maxX-minX;
    for(int i=0;i<=n;i++){
        string tmp(m+1,'.');
        answer.push_back(tmp);
    }
    for(auto xx: v){
        answer[maxY-xx.second][xx.first-minX]='*';
    }
    
    return answer;
}