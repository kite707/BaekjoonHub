#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int bBrother[10001];
int sBrother[10001];
int solution(vector<int> topping) {
    int answer = 0;
    
    // unordered_map<int,int> bBrother;
    // unordered_map<int,int> sBrother;
    int sTypeCnt=0;
    int bTypeCnt=0;
    for(int i=0;i<topping.size();i++){
        sBrother[topping[i]]++;
        if(sBrother[topping[i]]==1)sTypeCnt++;
    }
    cout<<sTypeCnt<<endl;
    for(int i=0;i<topping.size()-1;i++){
        bBrother[topping[i]]++;
        if(bBrother[topping[i]]==1)bTypeCnt++;
        sBrother[topping[i]]--;
        if(sBrother[topping[i]]==0)sTypeCnt--;
        if(bTypeCnt==sTypeCnt)answer++;
    }
    return answer;
}