#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int arr[1450];

int string_to_time(string time){
    int hour = (time[0]-'0')*10+time[1]-'0';
    int minute = (time[3]-'0')*10+time[4]-'0';
    return hour*60+minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> time;
    for(int i=0;i<book_time.size();i++){
        int start =string_to_time(book_time[i][0]);
        int end =string_to_time(book_time[i][1])+10;
        for(int j=start;j<end;j++){
            arr[j]+=1;
        }
    }
    answer =*max_element(&arr[0],&arr[0]+1045);
    return answer;
}