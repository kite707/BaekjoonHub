#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int getNum(long long begin){
    if(begin==1){return 0;}
    int num=0;
    for(int i=2;i*i<=begin;i++){
        if(begin%i==0){
            if(begin/i>10000000){
                num=i;
                continue;
            }else{
                num=(begin/i);
                break;
            }
        }
    }
    if(begin!=1&&!num)return 1;
    return num;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(long long i=begin;i<=end;i++){
        answer.push_back(getNum(i));
    }
    
    return answer;
}