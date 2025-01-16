#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int doDeliver(int cap, vector<int> &deliveries, vector<int> &pickups){
    int bring=0;
    int delLength=deliveries.size();
    int pickLength=pickups.size();

    while(!deliveries.empty()&&bring<=cap){
        int farestWeight = deliveries[deliveries.size()-1];
        
        if(bring+farestWeight>cap){
            int newWeight=farestWeight-(cap-bring);
            bring=cap;
            deliveries[deliveries.size()-1]=newWeight;
            break;
        }
        bring+=farestWeight;
        deliveries.erase(--deliveries.end());
    }
    
    bring = 0;
     while(!pickups.empty()&&bring<=cap){
        int farestWeight = pickups[pickups.size()-1];
        
        if(bring+farestWeight>cap){
            int newWeight=farestWeight-(cap-bring);
            bring=cap;
            pickups[pickups.size()-1]=newWeight;
            break;
        }
        bring+=farestWeight;
        pickups.erase(--pickups.end());
    }
    return max(delLength,pickLength)*2;
    
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    while(!deliveries.empty()&&deliveries[deliveries.size()-1]==0)deliveries.erase(--deliveries.end());
    while(!pickups.empty()&&pickups[pickups.size()-1]==0)pickups.erase(--pickups.end());

    
    while(!deliveries.empty()||!pickups.empty()){
        answer+=doDeliver(cap,deliveries,pickups);
    }    
    return answer;
}