#include <iostream>
#include <deque>
#include <queue>
using namespace std;

deque <int> dq;

void printer(){
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }cout<<endl;
}

int back_pop(int a){
    int cnt = 0;
    while(dq.front()!=a){
        dq.push_front(dq.back());
        dq.pop_back();
        cnt++;
    }
    dq.pop_front();
    return cnt;
}

int front_pop(int a){
    int cnt = 0;
    while(dq.front()!=a){
        dq.push_back(dq.front());
        dq.pop_front();
        cnt++;
    }
    dq.pop_front();
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M,a, answer = 0;
    cin>>N>>M;
    while(N--) dq.push_front(N+1);
    queue<int> pick;
    while(M--){
        cin>>a;
        int frontIdx, backIdx = 0;
        for(int i=0;i<dq.size();i++){
            if(dq[i]==a){
                frontIdx = i;
                break;
            }
        }
        backIdx = dq.size()-frontIdx+1;
        if(frontIdx<backIdx)answer+= front_pop(a);
        else answer+= back_pop(a);
    }
    cout<<answer;

}