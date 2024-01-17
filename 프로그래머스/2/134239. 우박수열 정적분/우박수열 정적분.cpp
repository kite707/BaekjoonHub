#include <string>
#include <vector>
#include <iostream>
using namespace std;

double width(vector<int> collatz, int start, int end){
    double sum = 0;
    if(start>end){
        return -1;
    }
    for(int i=start; i<end;i++){
        int fir = collatz[i];
        int sec = collatz[i+1];
        double ans = (double)(fir+sec)/2;
        sum+=ans;
    }
    return sum;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> collatz;
    collatz.push_back(k);
    while(k!=1){
        if(k%2==0){
            k/=2;
            collatz.push_back(k);
        }else if(k%2==1){
            k*=3;
            k++;
            collatz.push_back(k);
        }
    }
    int n = collatz.size()-1;
    for(int i=0;i<ranges.size();i++){
        int start = ranges[i][0];
        int end = n + ranges[i][1];
        answer.push_back(width(collatz,start,end));
    }
    
    return answer;
}