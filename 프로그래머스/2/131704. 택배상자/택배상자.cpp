#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int yIdx = 1;
    int orderIdx =0;
    stack<int> sub;
    while(answer!=order.size()||yIdx<=order.size()){
        if(yIdx == order[answer]){
            answer++;
            yIdx++;
            continue;
        }
        if(!sub.empty()&&sub.top()==order[answer]){
            answer++;
            sub.pop();
            continue;
        }
        bool isContinue = false;
        while(yIdx<=order.size()){
            if(yIdx==order[answer]){
                answer++;
                yIdx++;
                break;
            }else{
                sub.push(yIdx);
                yIdx++;
            }
        }
        if(yIdx>order.size()&&yIdx!=order[answer]&&(!sub.empty()&&sub.top()!=order[answer])){
            break;
        }
    }
    return answer;
}