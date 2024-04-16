#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    long long big=max(a,b);
    long long sma=min(a,b);
    while(big-sma!=1||max(big,sma)%2!=0){
        big=(big+1)/2;
        sma=(sma+1)/2;
        answer++;
    }
    return answer;
    //4 7->2 4->1 2
}