#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long getTime(vector<int> diffs, vector<int> times, long long tmpLimit){
    long long totalTime=0;
    int timeBefore=0;
    for(int i=0;i<diffs.size();i++){
        if(diffs[i]>tmpLimit){
            (i==0)?timeBefore=0:timeBefore=times[i-1];
            totalTime+=(diffs[i]-tmpLimit)*(times[i]+timeBefore);
        }
        totalTime+=times[i];
    }
    return totalTime;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    long long min=*min_element(diffs.begin(),diffs.end());
    long long max=*max_element(diffs.begin(),diffs.end());
    long long mid=(min+max)/2;

    while(min!=max){
        if(getTime(diffs,times,mid)<=limit){
            max=mid;
        }else{
            min=mid+1;
        }
        mid=(max+min)/2;
    }
    
    return min;
}