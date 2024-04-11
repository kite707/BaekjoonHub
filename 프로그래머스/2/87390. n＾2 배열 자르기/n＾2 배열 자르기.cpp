#include <string>
#include <vector>
#include <iostream>
using namespace std;

pair<long long,long long> getArrayIdx(long long idx,int n){
    long long y=idx/n;
    long long x= idx%n;
    return{y,x};
}

int getNum(long long y, long long x){
    if(x<=y)return y+1;
    return x+1;
}


vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long lef=left;lef<=right;lef++){
        auto iter=getArrayIdx(lef,n);
        long long y=iter.first;
        long long x= iter.second;
        
        int ans = getNum(y,x);
        answer.push_back(ans);
    }
    return answer;
}