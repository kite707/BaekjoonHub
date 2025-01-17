#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long onLine=0;
    
    long long r12=(long long)r1*r1;
    long long r22=(long long)r2*r2;
    
    for(long long i=0;i<=r2;i++){
        long long maxY=floor(sqrt(r22-i*i));
        long long minY=ceil(sqrt(r12-i*i));
        if(i==0)onLine+=(maxY - minY + 1);
        answer += (maxY - minY + 1);
    }
    answer-=onLine;
    return answer*4;
}