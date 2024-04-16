#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=0;i<=citations[citations.size()-1];i++){
        int idx=lower_bound(citations.begin(),citations.end(),i)-citations.begin();
        int over=citations.size()-idx;
        if(i<=over)answer=i;
    }
    return answer;
}