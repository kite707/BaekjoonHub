#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int size=queue1.size();
    queue<int> q1;
    queue<int> q2;
    long long sumA=0;
    long long sumB=0;
    for(int i=0;i<queue1.size();i++){
        sumA+=queue1[i];
        q1.push(queue1[i]);
    }
    for(int i=0;i<queue2.size();i++){
        sumB+=queue2[i];
        q2.push(queue2[i]);
    }
    while(sumA!=sumB){
        if(answer==size*3)return -1;
        if((sumA+sumB)%2!=0)return -1;
        if(sumA>sumB){
            int num=q1.front();
            q1.pop();
            sumA-=num;
            sumB+=num;
            q2.push(num);
        }
        else if(sumA<sumB){
           int num=q2.front();
            q2.pop();
            sumA+=num;
            sumB-=num;
            q1.push(num); 
        }
        answer++;
    }
    
    
    return answer;
}