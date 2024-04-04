#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer;
int queenSize;
bool ru[27];
bool ld[27];
bool horizon[13];


void depth(int curDepth){
    if(curDepth==queenSize){
        answer++;
        return;
    }
    for(int i=1;i<=queenSize;i++){
        if(!ru[i+curDepth]&&!ld[i-curDepth+queenSize]&&!horizon[i]){
            ru[i+curDepth]=true;
            ld[i-curDepth+queenSize]=true;
            horizon[i]=true;
            depth(curDepth+1);
            ru[i+curDepth]=false;
            ld[i-curDepth+queenSize]=false;
            horizon[i]=false;
            
        }
    }
}

int solution(int n) {
    queenSize=n;
    depth(0);
    return answer;
}