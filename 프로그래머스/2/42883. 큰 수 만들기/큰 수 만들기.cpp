#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(auto tmp: number){
        int num=tmp-'0';
        while(answer.size()!=0&&answer[answer.size()-1]-'0'<num&&k!=0){
            answer.erase(answer.begin()+answer.size()-1);
            k--;
        }
        answer+=to_string(num);
    }
    answer=answer.substr(0,answer.size()-k);
    return answer;
}