#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int st=0; int end=people.size()-1;
    int curWeight=0;
    while(st<=end){
        curWeight=people[end];
        end--;
        if(curWeight+people[st]<=limit){
            curWeight+=people[st];
            st++;
        }
        answer++;
    }
    return answer;
}