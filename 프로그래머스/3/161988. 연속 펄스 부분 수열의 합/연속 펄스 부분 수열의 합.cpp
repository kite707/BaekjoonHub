#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    if(sequence.size()==1){return abs(sequence[0]);}
    long long arr1[sequence.size()];
    long long arr2[sequence.size()];
    int tmp = 1;
    for(int i=0;i<sequence.size();i++){
        arr1[i]=sequence[i]*tmp;
        arr2[i]=sequence[i]*tmp*(-1);
        tmp*=-1;
    }
    long long dp1[sequence.size()];
    long long dp2[sequence.size()];
    dp1[0]=arr1[0];
    dp2[0]=arr2[0];
    answer=max(dp1[0],dp2[0]);
    for(int i=1;i<sequence.size();i++){
        dp1[i]=max(dp1[i-1]+arr1[i],arr1[i]);
        answer=max(dp1[i],answer);
        dp2[i]=max(dp2[i-1]+arr2[i],arr2[i]);
         answer=max(dp2[i],answer);
    }
    return answer;
}