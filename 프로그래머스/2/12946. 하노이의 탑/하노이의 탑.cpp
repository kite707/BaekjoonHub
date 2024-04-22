#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> answer;
void mv(int start, int end, int cnt){
    //cout<<"args: "<<start<<" "<<end<<" "<<cnt<<endl;
    int left=6-start-end;
    if(cnt==1){
        vector<int> v={start,end};
        answer.push_back(v);
        return;
    }else{
        mv(start,left,cnt-1);
        mv(start,end,1);
        mv(left,end,cnt-1);
    }
}

vector<vector<int>> solution(int n) {
    mv(1,3,n);
    //mv(1,2,2);
    return answer;
}