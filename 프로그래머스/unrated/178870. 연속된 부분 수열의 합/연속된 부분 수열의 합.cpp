#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int sum=0;
    int startIdx=0;
    int length=0;
    queue<int> q;
    
    vector<pair<int,int>> answers;
    for(int i=0;i<sequence.size();i++){
        sum+=sequence[i];
        q.push(sequence[i]); 
       while(sum>k){
           int firstNum=q.front();
           q.pop();
           sum-=firstNum;
       }
        if(sum==k){
            length=q.size();
            startIdx=i-length+1;
            //cout<<"i is: "<<i<<" length is: "<<length<<" startIdx is: "<<startIdx<<endl;
            answers.push_back(make_pair(length,startIdx));
        }
    }
    sort(answers.begin(),answers.end());
    vector<int> answer;
    answer.push_back(answers[0].second);
    answer.push_back(answers[0].second+answers[0].first-1);
    
    
    return answer;
}