#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long long getTime(vector<int> diffs, vector<int> times, int level){
    long long time=0;
    long long prevTime=0;
    for(int i=0;i<diffs.size();i++){
        if(i!=0){
            prevTime=times[i]+times[i-1];
        }
        int curDiff=diffs[i];
        int curTime=times[i];
        
        time+=curTime;
        if(curDiff>level){
            time+=(prevTime*(curDiff-level));
        }
        
        
    }
    return time;
}


int solution(vector<int> diffs, vector<int> times, long long limit) {
    map<int, long long> mp;
    
    int answer = 0;
    int min=*min_element(diffs.begin(),diffs.end());
    int max=*max_element(diffs.begin(),diffs.end());
    
    
    while(min<max){
        long long mid=(long long)(min+max)/2;
        
        long long res=getTime(diffs,times,mid);
        
        if(res<=limit){
            max=mid;
        }else{
            min=mid+1;
        }
        
        mp.insert({mid,res});
    }
    if(mp.empty())return min;
    for(auto k: mp){
        if(k.second<=limit){
            return k.first;
        }
    } 
}