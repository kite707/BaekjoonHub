#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;


long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(long long y=1;y<=r2;y++){
        long long rr1=(long long)r1*r1;
        long long rr2=(long long)r2*r2;
        //작은 원의 x 시작점
        long long startX=ceil(sqrt(rr1-y*y));
        //큰 원의 x 끝점
        long long endX=floor(sqrt(rr2-y*y));
        answer+=endX-startX+1;
    }

   return answer*4;
}

