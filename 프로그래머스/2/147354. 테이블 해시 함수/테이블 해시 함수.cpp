#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

int compareIdx = 0;

bool compare(vector<int> a, vector<int> b){
    if(a[compareIdx]==b[compareIdx]){
        return a[0]>b[0];
    }
    return a[compareIdx]<b[compareIdx];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    compareIdx = col-1;
    sort(data.begin(), data.end(),compare);
    queue<int> vec;
    for(int i= row_begin-1; i<row_end;i++){
        int tmp = 0;
        for(int j=0; j<data[i].size();j++){
            tmp+=data[i][j]%(i+1);
        }
        vec.push(tmp);
    }
    answer = vec.front();
    vec.pop();
    while(!vec.empty()){
        int num = vec.front();
        vec.pop();
        answer = (int)bitset<25>(answer^num).to_ulong();
    }
    return answer;
}