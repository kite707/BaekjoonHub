#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
int counter[11];
bool isAnswer(vector<int> number){
    for(int i=0;i<number.size();i++){
        if(number[i]!=counter[i]) return false;
    }
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0;i<10;i++){
        int wantIdx = find(want.begin(),want.end(),discount[i])-want.begin();
        counter[wantIdx]++;
    }
    if(isAnswer(number)){
            answer++;
        }
    for(int i=10;i<discount.size();i++){
        int addIdx = find(want.begin(),want.end(),discount[i])-want.begin();
        int subIdx = find(want.begin(),want.end(),discount[i-10])-want.begin();
        counter[addIdx]++;
        counter[subIdx]--;
        if(isAnswer(number)){
            answer++;
        }
    }
    return answer;
}