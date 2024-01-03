#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    deque<int> dq;
    while(storey!=0){
        dq.push_back(storey%10);
        storey/=10;
    }
    int carry = 0;
    while(!dq.empty()){
        int curNumber = dq.front();
        curNumber+=carry;
        dq.pop_front();
        cout<<"cur is "<<curNumber<<endl;
        if(curNumber>5){
            answer+=(10-curNumber);
            carry = 1;
            cout<<answer<<endl;
            if(dq.size()==0){
                answer++;
            }
        }else if(curNumber==5 && dq.front()>=5){
            answer+=(10-curNumber);
            carry = 1;
            cout<<answer<<endl;
        }
        else{
            answer+=curNumber;
            carry = 0;
            cout<<answer<<endl;
        }
    }
    return answer;
}