#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i=0;i<=d;i=i+k){
        long long tmp = (long long)d*d-(long long)i*i;
        long long t = (long long)sqrt(tmp);
        answer+=t/k+1;
    }
    return answer;
}