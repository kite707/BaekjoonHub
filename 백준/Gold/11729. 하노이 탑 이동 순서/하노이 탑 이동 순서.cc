//3개를 3번막대로 옮기기 = 7번
//4개를 3번막대로 옮기기 = 3개를 2번막대로 옮기기 + 4를 3으로, 나머지 3개 옮기기
//n개를 st번에서 en번 막대로 옮기기
//n-1개를 6-st-en으로 옮기기+가장 큰 조각 옮기기 + n-1개를 6-st-en에서 en으로 옮기기

#include <iostream>
using namespace std;

long long arr[21];

long long getTotal(int N){
    if(arr[N]!=0)return arr[N];
    arr[N]=getTotal(N-1)*2+1;
    return arr[N];
}

void move(int n, int st, int en){
    int remain=6-st-en;
    if(n==1){
        cout<<st<<" "<<en<<"\n";
        return;
    }
    move(n-1,st,remain);
    cout<<st<<" "<<en<<"\n";
    move(n-1,remain,en);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin>>N;
    arr[1]=1;
    arr[2]=3;
    cout<<getTotal(N)<<"\n";
    move(N,1,3);
}